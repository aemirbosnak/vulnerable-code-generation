//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Get ready for an exciting math challenge!\n");
    printf("You will be given a series of math problems and have to solve them under a time limit.\n");
    printf("Let's get started!\n\n");

    // Set variables
    int num1, num2, answer, userAnswer, score = 0, timeRemaining = 30;

    // Seed rand
    srand(time(0));

    // Loop 5 times
    for (int i = 0; i < 5; i++)
    {
        // Generate random numbers
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        // Display problem
        printf("Problem %d: %d + %d = ?\n", i + 1, num1, num2);

        // Get user answer
        scanf("%d", &userAnswer);

        // Calculate correct answer
        answer = num1 + num2;

        // Check if answer is correct
        if (userAnswer == answer)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect!\n");
        }
    }

    // Display score and time remaining
    printf("Time's up! You scored %d out of 5\n", score);
    printf("You had %d seconds remaining\n", timeRemaining);

    return 0;
}