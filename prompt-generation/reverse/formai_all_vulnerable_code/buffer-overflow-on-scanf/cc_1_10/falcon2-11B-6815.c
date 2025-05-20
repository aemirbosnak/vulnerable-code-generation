//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,i;
    char *exam[10];
    char *answers[10];
    char *name[10];
    int score[10];
    char *roll[10];
    
    printf("Enter number of students: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter name of student: ");
        scanf("%s",&name[i]);
        printf("Enter roll number of student: ");
        scanf("%s",&roll[i]);
        printf("Enter exam name: ");
        scanf("%s",&exam[i]);
        printf("Enter number of questions: ");
        scanf("%d",&score[i]);
        printf("Enter the answers of student: ");
        scanf("%s",&answers[i]);
    }
    
    for(i=0;i<n;i++)
    {
        if(strcmp(answers[i],exam[i])==0)
            score[i] += 10;
        else
            score[i] -= 10;
    }
    
    for(i=0;i<n;i++)
    {
        if(score[i]>0)
            printf("Student %s with Roll Number %s score is %d.\n",name[i],roll[i],score[i]);
        else if(score[i]<0)
            printf("Student %s with Roll Number %s score is %d.\n",name[i],roll[i],-score[i]);
        else
            printf("Student %s with Roll Number %s score is 0.\n",name[i],roll[i]);
    }
    
    return 0;
}