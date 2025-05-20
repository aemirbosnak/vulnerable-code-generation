//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    system("clear");
    printf("__________________________________________________\n");
    printf("                                  /\n");
    printf("                                 ||||_|__\n");
    printf("__________________________________________________\n");
    printf("Enter the number of the question you want to answer: ");
    int num_question = 0;
    scanf("%d", &num_question);

    // Generate a random question
    char question[200];
    sprintf(question, "Question %d: %s", num_question, "Write a short story about a cat named Luna.");

    // Display the question
    printf("%s\n\n", question);

    // Get the student's answer
    char answer[200];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Check if the answer is correct
    char correct_answer[200];
    sprintf(correct_answer, "The correct answer is: %s", "A cat named Luna was sleeping on a mat.");

    // Display the result
    if (strcmp(answer, correct_answer) == 0)
    {
        printf("Your answer is correct.\n");
    }
    else
    {
        printf("Your answer is incorrect. The correct answer is: %s", correct_answer);
    }

    // Generate a random number between 1 and 10
    int num_points = rand() % 10 + 1;

    // Display the number of points
    printf("You have earned %d points.\n", num_points);

    // Thank the student
    printf("Thank you for taking the exam.\n");

    system("pause");
}