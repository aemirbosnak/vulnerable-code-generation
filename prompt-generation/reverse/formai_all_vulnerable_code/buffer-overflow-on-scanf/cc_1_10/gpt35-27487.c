//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerScore = 0, computerScore = 0, roll;
    char again;

    printf("Welcome to the Table Game!\n");

    do {
        printf("\nPlayer, it's your turn!\n");
        printf("Press enter to roll the dice.");
        getchar();

        // Seed the random number generator
        srand(time(NULL));

        // Roll the dice
        roll = (rand() % 6) + 1;
        printf("You rolled a %d.\n", roll);
        
        // Update the player score
        playerScore += roll;
        printf("Your current score is %d.\n", playerScore);

        if (playerScore == 21) {
            printf("Congratulations! You scored a perfect 21!\n");
            playerScore = 0;
            computerScore = 0;
            continue;
        } else if (playerScore > 21) {
            printf("Oops! You bust and lose the game.\n");
            playerScore = 0;
            computerScore = 0;
            continue;
        }

        printf("\nComputer's turn!\n");
        
        // Computer rolls the dice
        roll = (rand() % 6) + 1;
        printf("Computer rolled a %d.\n", roll);
        
        // Update the computer score
        computerScore += roll;
        printf("Computer's current score is %d.\n", computerScore);

        if (computerScore == 21) {
            printf("Sorry, computer scored a perfect 21. You lose!\n");
            playerScore = 0;
            computerScore = 0;
            continue;
        } else if (computerScore > 21) {
            printf("Yay! Computer busts and you win the game.\n");
            playerScore = 0;
            computerScore = 0;
            continue;
        } else if (computerScore >= 17 && computerScore > playerScore) {
            printf("Computer wins the game with a score of %d.\n", computerScore);
            playerScore = 0;
            computerScore = 0;
            continue;
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf("%c", &again);

    } while (again == 'y' || again == 'Y');

    printf("Thanks for playing the Table Game!");

    return 0;
}