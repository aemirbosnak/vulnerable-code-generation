//Falcon-180B DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1_score = 0, player2_score = 0;
    int choice;
    char play_again;

    srand(time(NULL));

    // Romance-themed game instructions
    printf("Welcome to the game of love!\n");
    printf("You and your partner will take turns rolling a dice.\n");
    printf("The first one to reach 10 points wins!\n");
    printf("Let the game of love begin!\n\n");

    do {
        // Roll dice for player 1
        int dice1 = rand() % 6 + 1;
        printf("Player 1 rolled a %d!\n", dice1);

        // Roll dice for player 2
        int dice2 = rand() % 6 + 1;
        printf("Player 2 rolled a %d!\n\n", dice2);

        // Check who won the round
        if (dice1 > dice2) {
            printf("Player 1 wins this round of love!\n");
            player1_score++;
        } else if (dice2 > dice1) {
            printf("Player 2 wins this round of love!\n");
            player2_score++;
        } else {
            printf("It's a tie! This round doesn't count.\n");
        }

        // Check if game is over
        if (player1_score == 10 || player2_score == 10) {
            printf("\n");
            if (player1_score == 10) {
                printf("Player 1 has won the game of love with a score of %d!\n", player1_score);
            } else {
                printf("Player 2 has won the game of love with a score of %d!\n", player2_score);
            }
            break;
        }

        // Ask if players want to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}