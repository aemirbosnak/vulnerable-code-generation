//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1, player2, i;
    char response;
    srand(time(0)); // Seed random number generator with time

    printf("Welcome to the hilarious C Table Game!\n");
    printf("Instructions:\n");
    printf("1. Two players take turns rolling a six-sided die.\n");
    printf("2. Each roll is added to the player's score.\n");
    printf("3. The first player to reach 100 points wins!\n");
    printf("\nAre you ready to start? (y/n): ");
    scanf(" %c", &response);

    if(response == 'y' || response == 'Y')
    {
        printf("\nLet's get started!\n");

        while(player1 <= 100 && player2 <= 100) // Loop until someone reaches 100 points
        {
            // Player 1 roll
            printf("\nPlayer 1, press enter to roll the dice...");
            getchar(); // Wait for user to press enter
            player1 += rand() % 6 + 1; // Generate random number between 1 and 6
            printf("Player 1 rolled a %d. Score: %d\n", player1, player1);

            if(player1 >= 100) // Check if Player 1 has won
            {
                printf("\nPlayer 1 Wins!\n");
                break;
            }

            // Player 2 roll
            printf("\nPlayer 2, press enter to roll the dice...");
            getchar(); // Wait for user to press enter
            player2 += rand() % 6 + 1; // Generate random number between 1 and 6
            printf("Player 2 rolled a %d. Score: %d\n", player2, player2);

            if(player2 >= 100) // Check if Player 2 has won
            {
                printf("\nPlayer 2 Wins!\n");
                break;
            }
        }
    }
    else
    {
        printf("\nOk, maybe next time!\n");
    }

    return 0;
}