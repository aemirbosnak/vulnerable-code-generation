//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

int main()
{
    int i, score = 0, attempt = 0, currentQuestion = 0;
    char answer[20];
    char questions[MAX_QUESTIONS][200] = {
        "What is the capital of France?",
        "Who invented the telephone?",
        "What is the meaning of the word 'entrepreneur'?",
        "Which scientist won the Nobel Prize in Physics in 2020?",
        "What is the most populous country in the world?",
        "What is the chemical formula for sulfuric acid?",
        "Which president of the United States was assassinated in 1922?",
        "What is the meaning of the word 'entrepreneur'?",
        "What is the scientific name for the human brain?",
        "What is the sound of one hand clapping?"
    };

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random question
    currentQuestion = rand() % MAX_QUESTIONS;

    // Display the question
    printf("%s", questions[currentQuestion]);

    // Get the user's answer
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, questions[currentQuestion]) == 0)
    {
        // Increment the score
        score++;

        // Display a message
        printf("Your answer is correct. You have scored %d points.", score);
    }
    else
    {
        // Increment the attempt
        attempt++;

        // Display an error message
        printf("Your answer is incorrect. You have attempted %d times.", attempt);
    }

    // End of the game
    return 0;
}