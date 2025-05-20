//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("cls");
    int rollno, sub, marks;
    char name[20];

    printf("Enter your name:");
    scanf("%s", name);

    printf("Enter your roll number:");
    scanf("%d", &rollno);

    printf("Enter the subject number:");
    scanf("%d", &sub);

    printf("Enter your marks:");
    scanf("%d", &marks);

    marks = marks / 10;
    switch (marks)
    {
        case 10:
            printf("Your grade is A");
            break;
        case 9:
            printf("Your grade is A-");
            break;
        case 8:
            printf("Your grade is B+");
            break;
        case 7:
            printf("Your grade is B");
            break;
        case 6:
            printf("Your grade is C+");
            break;
        case 5:
            printf("Your grade is C");
            break;
        case 4:
            printf("Your grade is D+");
            break;
        case 3:
            printf("Your grade is D");
            break;
        case 2:
            printf("Your grade is F");
            break;
        default:
            printf("Invalid marks");
    }

    printf("\nThank you for using the Online Examination System, %s!", name);
    system("pause");
}