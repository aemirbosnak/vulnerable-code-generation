//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

/* C Table Game Example Program */

int main()
{
    int player1_score = 0;
    int player2_score = 0;
    int turns = 0;
    char restart_game;

    printf("Welcome to the C Table Game!\n");
    printf("Player 1: press 'a' to roll the dice.\n");
    printf("Player 2: press 'l' to roll the dice.\n");

    do {
        char player1_input, player2_input;
        int player1_roll, player2_roll;

        printf("\nTurn %d:\n", turns + 1);

        printf("Player 1, please press 'a' to roll the dice: ");
        scanf(" %c", &player1_input);

        while (player1_input != 'a') {
            printf("Invalid input. Please press 'a' to roll the dice: ");
            scanf(" %c", &player1_input);
        }

        player1_roll = rand() % 6 + 1;
        printf("Player 1 rolled: %d\n", player1_roll);

        printf("Player 2, please press 'l' to roll the dice: ");
        scanf(" %c", &player2_input);

        while (player2_input != 'l') {
            printf("Invalid input. Please press 'l' to roll the dice: ");
            scanf(" %c", &player2_input);
        }

        player2_roll = rand() % 6 + 1;
        printf("Player 2 rolled: %d\n", player2_roll);

        if (player1_roll > player2_roll) {
            player1_score++;
            printf("Player 1 wins the round!\n");
            printf("The score is now Player 1: %d, Player 2: %d\n", player1_score, player2_score);
        } else if (player2_roll > player1_roll) {
            player2_score++;
            printf("Player 2 wins the round!\n");
            printf("The score is now Player 1: %d, Player 2: %d\n", player1_score, player2_score);
        } else {
            printf("It's a tie!\n");
            printf("The score remains Player 1: %d, Player 2: %d\n", player1_score, player2_score);
        }

        turns++;

        printf("Press 'r' to play again or any other key to quit: ");
        scanf(" %c", &restart_game);

        if (restart_game == 'r') {
            player1_score = 0;
            player2_score = 0;
            turns = 0;
            printf("\nNew game started!\n");
            printf("Player 1: press 'a' to roll the dice.\n");
            printf("Player 2: press 'l' to roll the dice.\n");
        }

    } while (restart_game == 'r');

    printf("\nThanks for playing the C Table Game!\n");

    return 0;
}