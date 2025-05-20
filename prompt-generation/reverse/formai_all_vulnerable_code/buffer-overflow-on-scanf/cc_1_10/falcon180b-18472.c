//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define NUM_SIDES 6

int rollDice() {
    int dice[NUM_DICE];
    for (int i = 0; i < NUM_DICE; i++) {
        dice[i] = rand() % NUM_SIDES + 1;
    }
    return dice[0];
}

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    char choice;

    do {
        printf("Welcome to the Dice Game!\n");
        printf("You are player 1 and the computer is player 2.\n");
        printf("The first player to reach 100 points wins!\n\n");
        printf("Your score: %d\n", playerScore);
        printf("Computer score: %d\n", computerScore);
        printf("Do you want to roll the dice? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            int diceRoll = rollDice();
            printf("You rolled a %d!\n", diceRoll);
            playerScore += diceRoll;
            if (playerScore >= 100) {
                printf("Congratulations! You won the game!\n");
                break;
            }
        } else {
            printf("The computer rolls the dice...\n");
            computerScore += rollDice();
            if (computerScore >= 100) {
                printf("Sorry, you lost the game.\n");
                break;
            }
        }

    } while (1);

    return 0;
}