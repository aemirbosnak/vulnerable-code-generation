//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

int main()
{
    int i, score = 0, time_left = 60;
    char answer;

    // Seed the random number generator
    srand(time(NULL));

    // Create an array of questions
    char questions[MAX_QUESTIONS][100] = {
        "What is the capital of France?",
        "Who invented the telephone?",
        "What is the meaning of the word 'entrepreneur'?",
        "Which scientist won the Nobel Prize for Physics in 2022?",
        "What is the most common color of hair in the world?",
        "What is the chemical symbol for gold?",
        "What is the meaning of the word 'entrepreneur'?",
        "Which animal is known for its ability to climb trees?",
        "What is the sound of one hand clapping?",
        "Which planet is the largest in the solar system?"
    };

    // Display the questions and get the user's answer
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%d. %s", i + 1, questions[i]);
        scanf(" %c", &answer);

        // Check if the answer is correct
        if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd')
        {
            score++;
        }

        // Subtract time from the time left
        time_left--;
    }

    // Display the results
    printf("Your score: %d", score);
    printf("\nTime left: %d seconds", time_left);

    return 0;
}