//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    system("cls");
    printf("Welcome to the C Online Examination System!\n");

    // Student Information
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    // Subject Information
    char subject[20];
    printf("Enter the subject you are taking: ");
    scanf("%s", subject);

    // Question Paper
    char question[1000];
    printf("Enter the question paper: ");
    scanf("%s", question);

    // Answer
    char answer[1000];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Evaluation
    int marks = evaluate(question, answer);

    // Result
    printf("Your marks are: %d\n", marks);

    // Feedback
    printf("Feedback: \n");
    printf("Your answer was: %s\n", answer);
    printf("The correct answer is: %s\n", question);

    return 0;
}

int evaluate(char *question, char *answer)
{
    // Logic to evaluate the answer based on the question
    // This logic can be customized based on the specific subject and question type
    int marks = 0;
    if (strcmp(answer, question) == 0)
    {
        marks = 100;
    }
    else
    {
        marks = 0;
    }
    return marks;
}