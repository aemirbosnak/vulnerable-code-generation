//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char student_name[20];
    int student_id;
    float marks;
    char grade;

    // Get student information
    printf("Enter your name: ");
    scanf("%s", student_name);

    printf("Enter your student ID: ");
    scanf("%d", &student_id);

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
    printf("Your name: %s", student_name);
    printf("\nYour student ID: %d", student_id);
    printf("\nYour marks: %.2f", marks);
    printf("\nYour grade: %c", grade);

    return 0;
}