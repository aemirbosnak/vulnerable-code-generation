//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a module for student information management
void student_info(char *name, int roll_no, float marks)
{
    printf("Student name: %s\n", name);
    printf("Roll number: %d\n", roll_no);
    printf("Marks: %.2f\n", marks);
}

// Define a module for exam result management
void exam_result(float marks)
{
    if (marks >= 90)
    {
        printf("Grade: A\n");
    }
    else if (marks >= 80)
    {
        printf("Grade: B\n");
    }
    else if (marks >= 70)
    {
        printf("Grade: C\n");
    }
    else if (marks >= 60)
    {
        printf("Grade: D\n");
    }
    else
    {
        printf("Grade: F\n");
    }
}

int main()
{
    char name[20];
    int roll_no;
    float marks;

    // Get student information
    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter roll number: ");
    scanf("%d", &roll_no);

    printf("Enter marks: ");
    scanf("%f", &marks);

    // Display student information
    student_info(name, roll_no, marks);

    // Display exam result
    exam_result(marks);

    return 0;
}