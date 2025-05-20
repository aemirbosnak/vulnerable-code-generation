//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, score, correct_answers, total_questions;
    char answer, student_id[20];

    // Get student ID
    printf("Enter your student ID: ");
    scanf("%s", student_id);

    // Get number of questions
    printf("Enter the number of questions you want to answer: ");
    scanf("%d", &n);

    // Allocate memory for questions and answers
    char *questions = (char *)malloc(n * sizeof(char));
    char *answers = (char *)malloc(n * sizeof(char));

    // Create questions
    for (i = 0; i < n; i++)
    {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions + i);
    }

    // Get answers
    for (i = 0; i < n; i++)
    {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%c", answers + i);
    }

    // Calculate score
    correct_answers = 0;
    for (i = 0; i < n; i++)
    {
        if (answers[i] == questions[i])
        {
            correct_answers++;
        }
    }

    // Calculate total questions
    total_questions = n;

    // Print results
    printf("Student ID: %s\n", student_id);
    printf("Total number of questions: %d\n", total_questions);
    printf("Number of correct answers: %d\n", correct_answers);
    printf("Your score: %f%%", (float)correct_answers / total_questions * 100);

    // Free memory
    free(questions);
    free(answers);

    return;
}