//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables for the game
    int playerScore = 0, computerScore = 0, roll, turnScore, currentPlayer = 1;
    char choice;
    srand(time(0)); // Seed for random number generation

    // Welcome message
    printf("Welcome to the Paranoid Table Game!\n");

    // Main game loop
    while (playerScore < 100 && computerScore < 100)
    {
        // Print current scores
        printf("\nCurrent Scores:\n");
        printf("Player: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);

        // Prompt user to roll or hold
        printf("It's player %d's turn. Roll or hold? (r/h): ", currentPlayer);
        scanf(" %c", &choice);

        // Switch case for user choice
        switch (choice)
        {
            case 'r':
                // Roll the dice
                roll = rand() % 6 + 1;
                printf("You rolled a %d.\n", roll);
                
                // If roll is 1, lose turn score and switch players
                if (roll == 1)
                {
                    printf("Sorry, you rolled a 1. Turn over.\n");
                    turnScore = 0;
                    currentPlayer = currentPlayer == 1 ? 2 : 1;
                }
                else
                {
                    // Add roll to turn score
                    turnScore += roll;

                    // Prompt user to roll again or hold
                    printf("Roll again (r) or hold (h)?: ");
                    scanf(" %c", &choice);

                    while (choice != 'h' && choice != 'r')
                    {
                        printf("Invalid input. Please enter 'r' or 'h': ");
                        scanf(" %c", &choice);
                    }

                    // If user holds, add turn score to player score and switch players
                    if (choice == 'h')
                    {
                        playerScore += turnScore;
                        printf("Player %d holds. Total score: %d\n", currentPlayer, playerScore);
                        turnScore = 0;
                        currentPlayer = currentPlayer == 1 ? 2 : 1;
                    }
                    else
                    {
                        // If user rolls again, continue loop
                        continue;
                    }
                }
                break;
            case 'h':
                // If player holds, switch players
                printf("Player %d holds. Total score: %d\n", currentPlayer, playerScore);
                turnScore = 0;
                currentPlayer = currentPlayer == 1 ? 2 : 1;
                break;
            default:
                // Invalid input, switch players
                printf("Invalid input. Turn over.\n");
                turnScore = 0;
                currentPlayer = currentPlayer == 1 ? 2 : 1;
                break;
        }

        // If player wins, end game and print message
        if (playerScore >= 100)
        {
            printf("\nCongratulations! Player 1 wins with a score of %d.\n", playerScore);
            break;
        }

        // Computer turn
        printf("\nIt's the computer's turn.\n");

        turnScore = 0;

        while (turnScore < 20)
        {
            // Roll the dice
            roll = rand() % 6 + 1;
            printf("The computer rolled a %d.\n", roll);

            if (roll == 1)
            {
                printf("The computer rolled a 1. Turn over.\n");
                turnScore = 0;
                break;
            }
            else
            {
                turnScore += roll;

                if (computerScore + turnScore >= 100)
                {
                    computerScore += turnScore;
                    printf("The computer holds. Total score: %d\n", computerScore);
                    break;
                }
                else if (turnScore > 20)
                {
                    computerScore += turnScore;
                    printf("The computer holds. Total score: %d\n", computerScore);
                    break;
                }
            }
        }

        // If computer wins, end game and print message
        if (computerScore >= 100)
        {
            printf("\nGame over! The computer wins with a score of %d.\n", computerScore);
            break;
        }
    }

    return 0;
}