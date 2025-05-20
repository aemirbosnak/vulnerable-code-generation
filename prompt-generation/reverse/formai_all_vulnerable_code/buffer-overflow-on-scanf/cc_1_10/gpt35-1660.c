//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int round = 1;
    int diceRoll;
    char choice;

    printf("Welcome to the Dice Roll Game!\n");

    do {
        printf("\nRound %d\n", round);
        printf("Player's Turn\n");
        printf("Press any key to roll the dice ");
        getchar();
        srand(time(NULL));
        diceRoll = rand() % 6 + 1;
        printf("You rolled a %d\n", diceRoll);
        playerScore += diceRoll;

        printf("\nComputer's Turn\n");
        srand(time(NULL));
        diceRoll = rand() % 6 + 1;
        printf("The computer rolled a %d\n", diceRoll);
        computerScore += diceRoll;

        printf("\nCurrent Score\n");
        printf("Player: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);

        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &choice);
        round++;

    } while (choice == 'y' || choice == 'Y');

    printf("\nFinal Score\n");
    printf("Player: %d\n", playerScore);
    printf("Computer: %d\n\n", computerScore);

    if (playerScore > computerScore) {
        printf("Congratulations! You won!\n");
    } else if (computerScore > playerScore) {
        printf("Sorry, you lost!\n");
    } else {
        printf("The game ended in a tie!\n");
    }

    return 0;
}