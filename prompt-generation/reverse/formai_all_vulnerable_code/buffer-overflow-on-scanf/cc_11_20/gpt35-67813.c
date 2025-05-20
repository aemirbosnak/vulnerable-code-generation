//FormAI DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, playerScore = 0, cpuScore = 0;
    printf("Welcome to the game of the future!\n");

    // create a seed for the random number generator
    srand(time(NULL));

    // loop until either the player or CPU reaches a score of 10
    while (playerScore < 10 && cpuScore < 10)
    {
        printf("\nChoose your move:\n");
        printf("1. Attack\n");
        printf("2. Block\n");
        scanf("%d", &choice);

        // generate a random number between 1 and 2 for the CPU's move
        int cpuChoice = rand() % 2 + 1;

        // determine the outcome of the round based on the player and CPU's moves
        if (choice == cpuChoice)
        {
            printf("\nDraw!\n");
        }
        else if (choice == 1 && cpuChoice == 2)
        {
            printf("\nYou attacked while the CPU was blocking!\n");
            playerScore++;
        }
        else if (choice == 2 && cpuChoice == 1)
        {
            printf("\nThe CPU attacked while you were blocking!\n");
            cpuScore++;
        }
        else if (choice == 1 && cpuChoice == 2)
        {
            printf("\nYou attacked while the CPU was blocking!\n");
            playerScore++;
        }
        else if (choice == 1 && cpuChoice == 2)
        {
            printf("\nYou attacked while the CPU was blocking!\n");
            playerScore++;
        }
        else if (choice == 1 && cpuChoice == 2)
        {
            printf("\nYou attacked while the CPU was blocking!\n");
            playerScore++;
        }
        else
        {
            printf("\nInvalid choice!\n");
        }

        // print the current score of the player and CPU
        printf("Player: %d\n", playerScore);
        printf("CPU: %d\n", cpuScore);
    }

    // determine the winner based on the final score
    if (playerScore >= 10)
    {
        printf("\nCongratulations! You won!\n");
    }
    else
    {
        printf("\nSorry! The CPU won!\n");
    }

    return 0;
}