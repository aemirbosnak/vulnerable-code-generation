//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char **questions = malloc(10 * sizeof(char *));
    questions = realloc(questions, 20 * sizeof(char *));

    for (int i = 0; i < 20; i++)
    {
        questions[i] = malloc(100 * sizeof(char));
    }

    questions[0] = "What is the meaning of the word 'entrepreneur'?";
    questions[1] = "Who invented the telephone?";
    questions[2] = "What is the capital of France?";
    // Add more questions...

    int **answers = malloc(20 * sizeof(int *));
    answers = realloc(answers, 20 * sizeof(int *));

    for (int i = 0; i < 20; i++)
    {
        answers[i] = malloc(20 * sizeof(int));
    }

    answers[0] = 1;
    answers[1] = 2;
    answers[2] = 3;
    // Add more answers...

    int student_id;
    printf("Enter your student ID: ");
    scanf("%d", &student_id);

    int score = 0;
    for (int i = 0; i < 20; i++)
    {
        char answer;
        printf("%s: ", questions[i]);
        scanf(" %c", &answer);

        if (answer == answers[i])
        {
            score++;
        }
    }

    printf("Your score is: %d", score);
    free(questions);
    free(answers);
}