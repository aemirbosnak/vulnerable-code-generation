//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seeds the random number generator with the current time
    
    printf("Let's play a game!\n\n");
    printf("I will give you a random math expression and you have to solve it!\n");
    printf("If your answer is correct, you get a point!\n");
    printf("If your answer is incorrect, you lose a point!\n\n");
    printf("Are you ready? Let's go!\n\n");

    int score = 0; // Initialize the score to 0
    int num1, num2, answer, userAnswer;

    while (1) // Loop forever until the user quits
    {
        num1 = rand() % 100; // Generate a random number between 0 and 99
        num2 = rand() % 100; // Generate another random number between 0 and 99

        if (rand() % 2 == 0) // Flip a coin to decide whether to add or subtract
        {
            answer = num1 + num2;
            printf("What is %d + %d? ", num1, num2);
        }
        else
        {
            answer = num1 - num2;
            printf("What is %d - %d? ", num1, num2);
        }

        scanf("%d", &userAnswer); // Get input from the user

        if (userAnswer == answer)
        {
            printf("Excellent! That is correct!\n");
            score++;
        }
        else
        {
            printf("Oops! That is incorrect!\n");
            score--;
        }

        printf("Your score is now %d. Keep going!\n\n", score);

        if (score < 0) // Check if the user has lost
        {
            printf("Oh no! You've lost! Better luck next time.\n");
            break;
        }
    }

    return 0;
}