//FormAI DATASET v1.0 Category: Online Examination System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int id;
    char name[20];
    char course[20];
    float score;
};

void main()
{
    int i, choice;
    float avg_score = 0.0;
    struct student std[10];
    
    printf("Welcome to the Online Examination System\n");
    
    for(i = 0; i < 10; i++) 
    {
        printf("\n\nEnter details of student %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &std[i].id);
        printf("Name: ");
        scanf("%s", &std[i].name);
        printf("Course: ");
        scanf("%s", &std[i].course);
        printf("Score: ");
        scanf("%f", &std[i].score);
    }
    
    printf("\n\nStudents information:\n");
    printf("ID\tName\tCourse\tScore\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d\t%s\t%s\t%.2f\n", std[i].id, std[i].name, std[i].course, std[i].score);
        avg_score += std[i].score;
    }
    avg_score /= 10;
    
    printf("\n\nAverage score of the students: %.2f\n", avg_score);
    
    printf("\n\nWant to search for a student's score?");
    printf("\nEnter 1 for YES, 2 for NO: ");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        int id;
        printf("Enter student ID: ");
        scanf("%d", &id);
        for(i = 0; i < 10; i++)
        {
            if(std[i].id == id)
            {
                printf("\nStudent found!\n");
                printf("ID: %d\n", std[i].id);
                printf("Name: %s\n", std[i].name);
                printf("Course: %s\n", std[i].course);
                printf("Score: %.2f\n", std[i].score);
                break;
            }
        }
        if(i == 10)
        {
            printf("\nStudent not found\n");
        }
    }
    printf("\nThank you for using the Online Examination System\n");
}