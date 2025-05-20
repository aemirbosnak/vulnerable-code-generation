//FormAI DATASET v1.0 Category: Online Examination System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student       //structure for holding student information 
{
    char name[50];
    int roll_no;
    int marks;
}stud[100];

int main()
{
    int n,i,choice,search,flag=0,high_score=0;
    printf("\nNumber of students:");
    scanf("%d",&n);
    for(i=0;i<n;i++)     //loop for entering student information 
    {
        printf("\nEnter student %d name:",i+1);
        scanf("%s",stud[i].name);
        printf("Enter roll number:");
        scanf("%d",&stud[i].roll_no);
        printf("Enter marks:");
        scanf("%d",&stud[i].marks);
        if(stud[i].marks>high_score)    //tracking highest score 
        {
            high_score=stud[i].marks;
        }
    }
    
    printf("\n1. Display student information\n2. Search for student information\nEnter your choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:     //displaying all student information 
            printf("\nAll student information:");
            for(i=0;i<n;i++)
            {
                printf("\nName:%s\nRoll number:%d\nMarks:%d\n",stud[i].name,stud[i].roll_no,stud[i].marks);
            }
            break;
            
        case 2:     //searching for a student 
            printf("\nEnter roll number to search:");
            scanf("%d",&search);
            for(i=0;i<n;i++)
            {
                if(stud[i].roll_no==search)
                {
                    printf("\nName:%s\nRoll number:%d\nMarks:%d\n",stud[i].name,stud[i].roll_no,stud[i].marks);
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("\nStudent not found.");
            }
            break;
            
        default:
            printf("\nInvalid choice!");
            break;
    }
    
    printf("\nHighest score in the exam:%d",high_score);   //displaying highest score 
    return 0;
}