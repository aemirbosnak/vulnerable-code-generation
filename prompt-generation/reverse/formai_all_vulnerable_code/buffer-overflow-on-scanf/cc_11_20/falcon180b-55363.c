//Falcon-180B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numPlayers, playerScore[10] = {0}, computerScore = 0, choice, i;
    char playAgain;

    do
    {
        // Initialize random seed
        srand(time(0));

        // Get number of players
        printf("Enter number of players (1-10): ");
        scanf("%d", &numPlayers);

        // Initialize scores
        for (i = 0; i < numPlayers; i++)
        {
            printf("Enter name for player %d: ", i + 1);
            scanf("%s", &playerScore[i]);
        }

        // Play game
        while (1)
        {
            // Roll dice for computer
            int computerDice = rand() % 6 + 1;

            // Roll dice for player
            int playerDice;
            do
            {
                printf("Press enter to roll dice: ");
                scanf("%d", &playerDice);
            } while (playerDice < 1 || playerDice > 6);

            // Determine winner
            if (playerDice > computerDice)
            {
                printf("Player %s wins!\n", playerScore[computerDice - 1]);
                playerScore[computerDice - 1]++;
            }
            else if (playerDice < computerDice)
            {
                printf("Computer wins!\n");
                computerScore++;
            }
            else
            {
                printf("It's a tie!\n");
            }

            // Check for winner
            if (computerScore >= numPlayers)
            {
                printf("Computer wins the game!\n");
                break;
            }
            else if (playerScore[0] >= numPlayers - 1)
            {
                printf("Player %s wins the game!\n", playerScore[0]);
                break;
            }
        }

        // Ask if player wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}