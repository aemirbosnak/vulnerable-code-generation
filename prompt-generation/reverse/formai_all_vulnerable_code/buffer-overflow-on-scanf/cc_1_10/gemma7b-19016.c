//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

int main()
{
    int i, student_id, marks, total_marks = 0;
    char student_name[50];
    char answer[MAX_QUESTIONS];

    // Get student name and id
    printf("Enter student name: ");
    scanf("%s", student_name);

    printf("Enter student id: ");
    scanf("%d", &student_id);

    // Get student marks for each question
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Enter marks for question %d: ", i + 1);
        scanf("%d", &marks);
        total_marks += marks;
        answer[i] = getchar();
    }

    // Calculate total marks and grade
    marks = total_marks / MAX_QUESTIONS;
    char grade = 'F';
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

    // Print results
    printf("Student name: %s\n", student_name);
    printf("Student id: %d\n", student_id);
    printf("Total marks: %d\n", total_marks);
    printf("Marks per question: %d\n", marks);
    printf("Grade: %c\n", grade);

    return 0;
}