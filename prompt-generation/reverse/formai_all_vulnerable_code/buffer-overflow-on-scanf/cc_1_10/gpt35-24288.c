//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int player1_score = 0, player2_score = 0, turn_score = 0, turn = 1;
    char choice;
    srand(time(NULL));

    printf("Welcome to C Table Game!\n");

    // Start the game
    while (player1_score < 100 && player2_score < 100) {
        printf("\nIt's Player %d's turn!\n", turn);
        printf("Press 'r' to roll or 'h' to hold: ");
        scanf(" %c", &choice);

        // Roll the dice
        if (choice == 'r') {
            int roll = rand() % 6 + 1;
            printf("You rolled a %d\n", roll);

            // Add roll to turn score
            if (roll == 1) {
                printf("You rolled a 1. No points for you this turn.\n");
                turn_score = 0;
                turn = (turn == 1) ? 2 : 1;
            } else {
                turn_score += roll;
                printf("Your turn score is now %d\n", turn_score);
            }
        }

        // Hold and end turn
        else if (choice == 'h') {
            printf("You decided to hold.\n");
            if (turn == 1) {
                player1_score += turn_score;
                printf("Player 1's score is now %d\n", player1_score);
                turn_score = 0;
                turn = 2;
            } else {
                player2_score += turn_score;
                printf("Player 2's score is now %d\n", player2_score);
                turn_score = 0;
                turn = 1;
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Declare the winner
    if (player1_score >= 100 && player1_score > player2_score) {
        printf("\nPlayer 1 wins with a score of %d!", player1_score);
    } else {
        printf("\nPlayer 2 wins with a score of %d!", player2_score);
    }

    return 0;
}