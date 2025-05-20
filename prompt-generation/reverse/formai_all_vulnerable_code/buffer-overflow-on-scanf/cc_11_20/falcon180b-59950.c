//Falcon-180B DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, roll, playerScore = 0, computerScore = 0, win = 0;
    char playAgain;

    srand(time(0));

    do
    {
        printf("\nWelcome to the Table Game!\n");
        printf("Roll the dice and try to beat the computer!\n");
        printf("Enter 1 to roll the dice or 0 to quit: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            roll = rand() % 6 + 1;
            printf("You rolled a %d!\n", roll);

            if (roll == 1)
            {
                printf("Sorry, you lose this round.\n");
            }
            else if (roll > 1 && roll < 4)
            {
                printf("You tied with the computer.\n");
            }
            else
            {
                printf("Congratulations, you win this round!\n");
                playerScore++;
            }
        }
        else if (choice!= 0)
        {
            printf("Invalid input. Please try again.\n");
        }

        computerScore = rand() % 6 + 1;

        if (computerScore == 1)
        {
            printf("The computer rolled a 1. You win this round!\n");
            playerScore++;
        }
        else if (computerScore > 1 && computerScore < 4)
        {
            printf("The computer rolled a %d. It's a tie.\n", computerScore);
        }
        else
        {
            printf("The computer rolled a %d. You lose this round.\n", computerScore);
            computerScore++;
        }

        printf("\nScore: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}