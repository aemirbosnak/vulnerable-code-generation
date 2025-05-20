//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message to the player.
    printf("Welcome to the amazing game of...\n");
    printf("ROCK, PAPER, SCISSORS!\n");

    // Initializing variables.
    int playerChoice, computerChoice, playerWins = 0, computerWins = 0, ties = 0;
    char playAgain;

    // Random seed for computer's choice.
    srand(time(NULL));

    do
    {
        // Get player's choice.
        printf("\n\nPlease choose:\n1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &playerChoice);

        // Generate computer's choice.
        computerChoice = rand() % 3 + 1;

        // Determine winner.
        if (playerChoice == computerChoice)
        {
            printf("\nIt's a tie!\n");
            ties++;
        }
        else if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2))
        {
            printf("\nYou win!\n");
            playerWins++;
        }
        else
        {
            printf("\nComputer wins!\n");
            computerWins++;
        }

        // Ask if player wants to play again.
        printf("\nDo you want to play again? (Y/N)\n");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    // Print final scores.
    printf("\n\nHere are the final scores:\n");
    printf("Player wins: %d\n", playerWins);
    printf("Computer wins: %d\n", computerWins);
    printf("Ties: %d\n", ties);

    // Goodbye message to the player.
    printf("\nThank you for playing ROCK, PAPER, SCISSORS!");
    printf("\nPlease come back soon!\n");

    return 0;
}