//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding random number generator with time

    // Initializing variables
    int computerScore = 0;
    int playerScore = 0;
    int roundCount = 1;
    int remainingRounds = 5;
    int computerChoice, playerChoice;

    printf("Welcome to the Rock, Paper, Scissors game! ");
    printf("You will play 5 rounds against the computer.\n");
    printf("Remember, rock beats scissors, scissors beat paper, and paper beats rock.\n");
    printf("Let's begin!\n\n");

    // Game loop
    while (remainingRounds > 0)
    {
        printf("Round %d:\n", roundCount);

        // Randomly generate computer's choice
        computerChoice = rand() % 3 + 1;

        // Get player's choice
        printf("Enter your choice: 1 for rock, 2 for paper, 3 for scissors: ");
        scanf("%d", &playerChoice);

        // Compare choices and update scores
        switch (playerChoice)
        {
            case 1:
                if(computerChoice == 1)
                {
                    printf("It's a tie!\n");
                }
                else if(computerChoice == 2)
                {
                    printf("Computer wins!\n");
                    computerScore++;
                }
                else
                {
                    printf("You win!\n");
                    playerScore++;
                }
                break;

            case 2:
                if(computerChoice == 2)
                {
                    printf("It's a tie!\n");
                }
                else if(computerChoice == 3)
                {
                    printf("Computer wins!\n");
                    computerScore++;
                }
                else
                {
                    printf("You win!\n");
                    playerScore++;
                }
                break;

            case 3:
                if(computerChoice == 3)
                {
                    printf("It's a tie!\n");
                }
                else if(computerChoice == 1)
                {
                    printf("Computer wins!\n");
                    computerScore++;
                }
                else
                {
                    printf("You win!\n");
                    playerScore++;
                }
                break;

            default:
                printf("Invalid choice, try again.\n");
                remainingRounds++;
        }

        // Reduce remaining round count
        remainingRounds--;
        roundCount++;

        printf("\n");
    }

    // Display results
    printf("Game over!\n");
    printf("Computer score: %d\n", computerScore);
    printf("Your score: %d\n", playerScore);

    if (computerScore > playerScore)
    {
        printf("Computer wins the game!\n");
    }
    else if (playerScore > computerScore)
    {
        printf("Congratulations, you win the game!\n");
    }
    else
    {
        printf("It's a tie game!\n");
    }

    return 0;
}