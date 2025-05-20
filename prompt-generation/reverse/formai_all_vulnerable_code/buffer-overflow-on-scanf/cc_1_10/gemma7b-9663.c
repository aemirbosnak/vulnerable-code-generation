//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 3

typedef struct Question
{
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswerIndex;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns a business", "b. A person who is good at making things", "c. A person who is always selling"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin"}, 0},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A drum", "c. A bell"}, 2}
};

int main()
{
    int i;
    int score = 0;

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Print the answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("  %s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        char answer;
        printf("Enter your answer: ");
        scanf(" %c", &answer);

        // Check if the user's answer is correct
        if (answer == questions[i].correctAnswerIndex)
        {
            score++;
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is %c.\n", questions[i].correctAnswerIndex);
        }
    }

    // Print the user's score
    printf("Your score is: %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}