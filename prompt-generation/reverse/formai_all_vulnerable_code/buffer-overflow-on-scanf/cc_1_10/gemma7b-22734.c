//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the C Online Examination System!\n");
    printf("------------------------\n");

    // Student Information
    char name[20];
    printf("Enter your full name: ");
    scanf("%s", name);

    // Exam Paper Selection
    int paper_id;
    printf("Select the exam paper you want to attempt: \n");
    printf("1. Mathematics\n");
    printf("2. English\n");
    printf("3. Science\n");
    scanf("%d", &paper_id);

    // Question Paper Generation
    int num_questions;
    switch (paper_id)
    {
        case 1:
            num_questions = 10;
            break;
        case 2:
            num_questions = 15;
            break;
        case 3:
            num_questions = 20;
            break;
    }

    // Question Display
    printf("Here are the questions: \n");
    for (int i = 0; i < num_questions; i++)
    {
        printf("Question %d: ", i + 1);
        // Insert question text here
        printf("\n");
    }

    // Answer Submission
    char answer[200];
    printf("Enter your answers below: \n");
    scanf("%s", answer);

    // Result Calculation
    int marks = 0;
    for (int i = 0; i < num_questions; i++)
    {
        // Check if the answer is correct
        if (answer[i] == 'a')
        {
            marks++;
        }
    }

    // Result Display
    printf("Your total marks are: %d\n", marks);
    printf("Your grade is: ");
    if (marks >= 80)
    {
        printf("A");
    }
    else if (marks >= 60)
    {
        printf("B");
    }
    else if (marks >= 40)
    {
        printf("C");
    }
    else
    {
        printf("F");
    }

    printf("\nThank you for attempting the C Online Examination System, %s! We hope you had a pleasant experience.", name);

    return 0;
}