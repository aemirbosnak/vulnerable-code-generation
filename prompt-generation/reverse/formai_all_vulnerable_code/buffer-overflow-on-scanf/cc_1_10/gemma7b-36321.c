//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

int main()
{
    time_t t;
    int i, score = 0, timeLeft = 60;
    char answer;

    // Seed the random number generator
    srand(time(NULL));

    // Create an array of questions
    char questions[MAX_QUESTIONS][100] = {
        "What is the capital of France?",
        "Who painted the Mona Lisa?",
        "What is the meaning of the word 'entrepreneur'?",
        "What is the chemical symbol for gold?",
        "Which planet is the largest?",
        "What is the square of 5?",
        "What is the meaning of the word 'entrepreneur'?",
        "What is the sound of one hand clapping?",
        "Which scientist invented the theory of relativity?",
        "Who was the first president of the United States?"
    };

    // Display the questions and get the answers
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s (Please enter your answer: ", questions[i]);
        scanf(" %c", &answer);

        // Check if the answer is correct
        if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd')
        {
            score++;
        }
    }

    // Display the results
    printf("Your score is: %d", score);

    // Calculate the time elapsed
    t = time(NULL) - timeLeft;
    printf("Time elapsed: %d seconds", t);

    return 0;
}