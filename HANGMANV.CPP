
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>

int i;
char j[3];
int body();
int wrong1();
int wrong2();
int wrong3();
int wrong4();
int wrong5();
int wrong6();
void words();

void rules()
{
printf("1.A Hint will be given and you have to guess the word\n");
printf("2.You will have 6 lives.\n");
printf("3.You should only enter capital letters");

printf("\nPress p to play game");
gets(j);
if(strcmp(j,"p")==0)
{

words();
}
}

int hints(int r)
{
printf("\tHINT:");
if(r==0)
printf("Gadget");
else if(r==1)
printf("Fruit");
else if(r==2)
printf("Search Engine");
else if(r==3)
printf("C");
else if(r==4)
printf("Knowledge");
else if(r==5)
printf("Campus");
else
printf("Color");
return r;

}

void words()
{
srand(time(NULL));
char words[][50]={"MOBILE","APPLE","GOOGLE","LANGUAGE","BOOK","PULCHOWK","BLUE"};
int random=rand()%7;                                                                                                   


int numlives=6, numcorrect=0, up=3, oldcorrect=0, quit=0;

int wordlength=strlen(words[random]);
int letterguessed[10]={0,0,0,0,0,0,0,0,0,0};

char guess[20] ,letterentered;
body();
printf("word length=%d\t",wordlength);
hints(random);
printf("\n\n");
for(i=0; i<wordlength; i++)
printf("_ ");

while(numcorrect<wordlength)
    {
 printf("\nEnter a guess letter:");
 gets(guess);
 if(strcmp(guess,"quit")==0)
	{
	quit=1;
	break;
	}

 letterentered=guess[0];
 //printf("Entered Letter:%c\n",letterentered);
 printf("\033[%dA\033[%dL",up);

 oldcorrect=numcorrect;

 for (i=0;i<wordlength;i++)
 {
 if (letterguessed[i]==1)
	{
 continue;
	}


 if (letterentered == words[random][i])

	{
	letterguessed[i]=1;
	numcorrect++;

	 }
	 }
	 printf("\n");
	 for(i=0;i<wordlength; i++){
 if(letterguessed[i]==0)
 printf("_ ");
 else
 printf("%c ",words[random][i]);
 }

 if(oldcorrect==numcorrect)
	{
	numlives--;
	 }
// printf("\nLives Left:%d",numlives);
 if(numlives==5)
 {

 body();
numlives= wrong1();
}
 if(numlives==4)
 {

 body();
numlives= wrong1();
numlives= wrong2();
}
 if(numlives==3)
 {

 body();
 numlives=wrong1();
 numlives=wrong2();
numlives= wrong3();
}
 if(numlives==2)
 {
 body();
 numlives=wrong1();
 numlives=wrong2();
 numlives=wrong3();
numlives= wrong4();
}
 if(numlives==1)
 {
 body();
 numlives=wrong1();
 numlives=wrong2();
 numlives=wrong3();
 numlives=wrong4();
numlives= wrong5();
}
 if(numlives==0)
 {
 body();
 numlives=wrong1();
 numlives=wrong2();
 numlives=wrong3();
 numlives=wrong4();
 numlives=wrong5();
numlives= wrong6();
moveto(500,100);
settextstyle(SANS_SERIF_FONT,0,0);
setusercharsize(1,1,2,1);
outtext("HANGED");
break;
 }

}


if (quit==1)
printf("\nYOU LEFT THE GAME");
if(numlives>0&&strcmp(guess,"quit")!=0)
{
moveto(500,100);
settextstyle(SANS_SERIF_FONT,0,0);
setusercharsize(1,1,2,1);
outtext("YOU WON");
}
}

int main()
{
int gd,gm;
gd=DETECT;
initgraph (&gd,&gm,"C:\\TURBOC3\\BGI");
printf("Press p to play game and r for rules");
gets(j);
if(strcmp(j,"p")==0)
words();
else if(strcmp(j,"r")==0)
rules();
getch();
closegraph();
return 0;
}


int body()
{
line (500,80,600,80);		 // horizontal line
line (500,80,500,180);          // vertical line
line (530,80,500,110);         // slanted line
line (600,80,600,90);         // small vertical line
line (500,180,630,180);      // base line
 }

int wrong1()         //function to create head
{
circle(600,100,10);
return 5;
}
int wrong2()         //function to create body
{
line(600,110,600,140);
return 4;
}
int wrong3()           //function to create hand
{
line(600,120,580,130);
return 3;
}
int wrong4()                 //function to create other hand
{
line(600,120,620,130);
return 2;
}
int wrong5()                 //function to create leg
{
line(600,140,580,160);
return 1;
}
int wrong6()                   //function to create other leg
{
line(600,140,620,160);
return 0;
}

