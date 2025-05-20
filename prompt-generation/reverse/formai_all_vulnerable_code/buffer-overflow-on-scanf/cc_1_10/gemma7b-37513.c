//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    printf("********************************************************************\n");
    printf("Welcome to the Immersive C Online Examination System!\n");
    printf("********************************************************************\n");

    // Student Information
    char name[20];
    printf("Enter your full name: ");
    scanf("%s", name);

    // Exam Information
    int exam_id;
    printf("Enter the exam ID: ");
    scanf("%d", &exam_id);

    // Question Selection
    int question_num;
    printf("Select a question number: ");
    scanf("%d", &question_num);

    // Display Question
    printf("Question: ");
    switch (question_num)
    {
        case 1:
            printf("Write a C program to print 'Hello, world!'");
            break;
        case 2:
            printf("Explain the concept of pointers.");
            break;
        case 3:
            printf("Describe the different data types in C.");
            break;
        default:
            printf("Invalid question number.");
    }

    // Answer Submission
    char answer[200];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Grading
    int grade = 0;
    if (strcmp(answer, "Hello, world!") == 0)
    {
        grade = 10;
    }
    else if (strcmp(answer, "Explain the concept of pointers.") == 0)
    {
        grade = 8;
    }
    else if (strcmp(answer, "Describe the different data types in C.") == 0)
    {
        grade = 6;
    }
    else
    {
        grade = 0;
    }

    // Results
    printf("Your grade: %d\n", grade);

    // Conclusion
    printf("Thank you for participating in the Immersive C Online Examination System, %s!\n", name);
    printf("We hope you enjoyed the exam.\n");

    system("pause");
}