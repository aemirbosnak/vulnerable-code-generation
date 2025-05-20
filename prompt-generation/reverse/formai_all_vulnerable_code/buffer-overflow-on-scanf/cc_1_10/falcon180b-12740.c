//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
srand(time(NULL));
int n,i,j,k;

printf("Enter the number of questions:");
scanf("%d",&n);

int marks[n];
printf("Enter the marks for each question:\n");
for(i=0;i<n;i++)
{
scanf("%d",&marks[i]);
}

printf("Enter the options for each question:\n");
char options[n][100];
for(i=0;i<n;i++)
{
scanf("%s",options[i]);
}

int correct_answers[n];
for(i=0;i<n;i++)
{
correct_answers[i]=rand()%4;
}

printf("The examination has started\n");
for(i=0;i<n;i++)
{
printf("\nQuestion %d:\n",i+1);
printf("%s\n",options[i]);
int user_ans;
scanf("%d",&user_ans);

if(user_ans==correct_answers[i])
{
marks[i]+=10;
printf("Correct answer\n");
}
else
{
printf("Incorrect answer\n");
}
}

printf("The examination has ended");

return 0;
}