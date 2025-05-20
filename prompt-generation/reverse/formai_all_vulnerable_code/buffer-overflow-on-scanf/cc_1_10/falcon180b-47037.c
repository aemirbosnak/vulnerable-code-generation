//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define SIDES 6

int rollDice() {
    return rand() % SIDES + 1;
}

int main() {
    int playerScore, computerScore;
    char playAgain;

    do {
        srand(time(NULL));
        playerScore = 0;
        computerScore = 0;

        printf("Welcome to the Dice Game!\n");
        printf("You will roll the dice and try to get a higher score than the computer.\n");
        printf("The first one to reach 10 points wins!\n");

        while (playerScore < 10 && computerScore < 10) {
            printf("Your turn. Press enter to roll the dice:\n");
            scanf("%c", &playAgain);

            if (playAgain == '\n') {
                playerScore += rollDice();
                printf("You rolled a %d!\n", playerScore);
            }
        }

        while (computerScore < 10) {
            computerScore += rollDice();
            printf("The computer rolled a %d!\n", computerScore);
        }

        if (playerScore == 10) {
            printf("You win!\n");
        } else if (computerScore == 10) {
            printf("You lose.\n");
        } else {
            printf("Tie game.\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}