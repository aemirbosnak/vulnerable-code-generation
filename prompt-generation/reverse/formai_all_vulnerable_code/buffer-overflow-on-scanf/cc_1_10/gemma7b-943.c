//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int student_id;
    char name[20];
    float marks;
    char grade;

    printf("Welcome to the C Online Examination System!\n");

    // Get student id, name, and marks
    printf("Enter your student ID: ");
    scanf("%d", &student_id);

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your marks: ");
    scanf("%f", &marks);

    // Calculate grade
    if (marks >= 90)
    {
        grade = 'A';
    }
    else if (marks >= 80)
    {
        grade = 'B';
    }
    else if (marks >= 70)
    {
        grade = 'C';
    }
    else if (marks >= 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    // Print results
    printf("Your student ID is: %d\n", student_id);
    printf("Your name is: %s\n", name);
    printf("Your marks are: %.2f\n", marks);
    printf("Your grade is: %c\n", grade);

    return 0;
}