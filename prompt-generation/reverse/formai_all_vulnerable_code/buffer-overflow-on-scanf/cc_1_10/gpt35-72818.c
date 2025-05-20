//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random integer between min and max
int randomNum(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    int playerScore = 0;
    int computerScore = 0;
    int round = 1;
    int choice;

    srand(time(NULL)); // seed for random number generator

    // game loop
    while (1)
    {
        printf("----------------------------------------------\n");
        printf("                ROUND %d\n", round);
        printf("----------------------------------------------\n");

        // player's turn
        printf("Your turn:\n");
        printf("1. Roll the dice\n");
        printf("2. End turn\n");

        scanf("%d", &choice);

        // roll the dice
        if (choice == 1)
        {
            int roll = randomNum(1, 6);
            printf("You rolled a %d\n", roll);
            playerScore += roll;
            printf("Your score: %d\n", playerScore);

            // check if player wins
            if (playerScore >= 100)
            {
                printf("Congratulations, you win!\n");
                break;
            }
        }

        // end turn
        else if (choice == 2)
        {
            printf("You ended your turn.\n");
        }

        // invalid choice
        else
        {
            printf("Invalid choice, please try again.\n");
        }

        // computer's turn
        printf("\nComputer's turn:\n");

        int computerChoice = randomNum(1, 2);

        // roll the dice
        if (computerChoice == 1)
        {
            int roll = randomNum(1, 6);
            printf("Computer rolled a %d\n", roll);
            computerScore += roll;
            printf("Computer's score: %d\n", computerScore);

            // check if computer wins
            if (computerScore >= 100)
            {
                printf("Sorry, the computer wins.\n");
                break;
            }
        }

        // end turn
        else if (computerChoice == 2)
        {
            printf("The computer ended its turn.\n");
        }

        // update round
        round++;
    }

    return 0;
}