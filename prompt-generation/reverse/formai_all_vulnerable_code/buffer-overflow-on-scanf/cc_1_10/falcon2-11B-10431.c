//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: careful
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice, n, marks[5], roll[5];
    char name[50], question[50];

    int i;

    printf("\nWELCOME TO ONLINE EXAMINATION SYSTEM\n");
    printf("-------------------------------\n");
    printf("\n1. Register\n2. Login\n3. Exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter your name: ");
            scanf("%s", name);
            printf("Enter your roll number: ");
            scanf("%d", &roll[0]);
            printf("Enter your marks: ");
            scanf("%d %d %d %d %d", &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);
            break;
        case 2:
            printf("\nEnter your roll number: ");
            scanf("%d", &roll[0]);
            printf("Enter your marks: ");
            scanf("%d %d %d %d %d", &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);
            break;
        case 3:
            exit(0);
    }

    printf("\nYour Name: %s", name);
    printf("\nYour Roll Number: %d", roll[0]);
    printf("\nYour Marks: %d %d %d %d %d", marks[0], marks[1], marks[2], marks[3], marks[4]);
    printf("\n---------------------------------\n");

    for(i=0; i<5; i++)
    {
        printf("Question %d: ", i+1);
        printf("Enter your answer: ");
        scanf("%s", question);
    }

    printf("\n---------------------------------\n");

    printf("Your Result: %d", sum(marks));
    printf("\n---------------------------------\n");

    return 0;
}

int sum(int marks[])
{
    int sum = 0;
    for(int i=0; i<5; i++)
        sum += marks[i];
    return sum;
}