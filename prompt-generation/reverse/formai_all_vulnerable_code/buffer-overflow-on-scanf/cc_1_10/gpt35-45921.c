//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int player_score = 0, computer_score = 0, dice_result = 0, player_turn = 1;
    char input;
    srand(time(NULL)); // Seed random number generator with current time

    printf("Welcome to the dice game! Press enter to roll the dice.\n");

    while (1) {
        if (player_turn) {
            // Player's turn
            printf("Your turn!\n");
            printf("Press enter to roll the dice.\n");
            scanf("%c", &input); // Wait for player to press enter
            dice_result = rand() % 6 + 1; // Random number between 1 and 6
            printf("You rolled a %d!\n", dice_result);
            player_score += dice_result;

            if (player_score >= 20) {
                printf("Congratulations! You won!\n");
                break;
            }

            printf("Your total score is now %d.\n", player_score);
            printf("Do you want to roll again? (Y/N)\n");
            scanf(" %c", &input); // Ignore whitespace before input
            if (input == 'N' || input == 'n') {
                player_turn = 0;
            }
        } else {
            // Computer's turn
            printf("Computer's turn!\n");
            dice_result = rand() % 6 + 1;
            printf("Computer rolled a %d!\n", dice_result);
            computer_score += dice_result;

            if (computer_score >= 20) {
                printf("Computer wins!\n");
                break;
            }

            printf("Computer's total score is now %d.\n", computer_score);
            if (computer_score < 15) {
                printf("Computer rolls again!\n");
            } else {
                printf("Computer stops rolling.\n");
                player_turn = 1;
            }
        }
    }

    return 0;
}