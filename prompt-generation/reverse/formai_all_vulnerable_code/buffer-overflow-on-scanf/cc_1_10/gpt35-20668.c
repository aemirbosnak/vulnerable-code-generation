//FormAI DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0, roll;
    char choice;

    printf("Welcome to the C Table Game!\n");

    do {
        printf("\nYour current score is: %d\n", player_score);
        printf("Computer's current score is: %d\n", computer_score);
        printf("\nPress 'r' to roll the dice or 'h' to hold: ");
        scanf(" %c", &choice);

        // Player's turn
        if (choice == 'r') {
            srand(time(0));
            roll = (rand() % 6) + 1;
            printf("\nYou rolled a %d!\n", roll);
            if (roll == 1) {
                printf("Oops! You rolled a 1. Your turn is over.\n");
            } else {
                player_score += roll;
                if (player_score >= 100) {
                    printf("\nCongratulations! You won!\n");
                    return 0;
                }
            }
        } else if (choice == 'h') {
            printf("\nYou chose to hold. Your turn is over.\n");
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }

        // Computer's turn
        if (computer_score < 20) {
            printf("\nComputer rolled the dice.\n");
            roll = (rand() % 6) + 1;
            printf("Computer rolled a %d.\n", roll);
            if (roll == 1) {
                printf("\nOops! Computer rolled a 1. Your turn now.\n");
            } else {
                computer_score += roll;
                if (computer_score >= 100) {
                    printf("\nComputer won. Better luck next time.\n");
                    return 0;
                }
            }
        } else {
            printf("\nComputer chose to hold\n");
        }


    } while (1);

    return 0;
}