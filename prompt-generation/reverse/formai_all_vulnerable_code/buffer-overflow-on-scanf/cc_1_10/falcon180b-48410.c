//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define SIDES 6

int rollDice(void) {
    int i;
    int total = 0;

    for (i = 0; i < NUM_DICE; i++) {
        int roll = rand() % SIDES + 1;
        printf("Dice %d rolled a %d\n", i+1, roll);
        total += roll;
    }

    return total;
}

int main() {
    srand(time(NULL));

    int playerScore = 0;
    int computerScore = 0;

    while (playerScore < 100 && computerScore < 100) {
        printf("Player's turn. Roll the dice? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            playerScore += rollDice();
            printf("Your score is now %d\n", playerScore);
        }
    }

    while (computerScore < 100) {
        computerScore += rollDice();
        printf("Computer rolled a %d\n", computerScore);
    }

    if (playerScore > computerScore) {
        printf("Congratulations! You win!\n");
    } else if (playerScore < computerScore) {
        printf("Sorry, you lose.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}