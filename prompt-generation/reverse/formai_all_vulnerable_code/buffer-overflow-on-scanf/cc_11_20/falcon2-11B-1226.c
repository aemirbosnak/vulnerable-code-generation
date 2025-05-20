//Falcon2-11B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ROUNDS 5

int main(int argc, char *argv[])
{
    int rounds = 0;
    int player1, player2, result;
    char player1_choice[3], player2_choice[3];

    while (rounds < MAX_ROUNDS) {
        printf("Player 1: Choose Rock, Paper or Scissors: ");
        fflush(stdout);
        scanf("%s", player1_choice);

        if (strcmp(player1_choice, "Rock") == 0) {
            player1 = 0;
        } else if (strcmp(player1_choice, "Paper") == 0) {
            player1 = 1;
        } else if (strcmp(player1_choice, "Scissors") == 0) {
            player1 = 2;
        } else {
            printf("Invalid input for Player 1. Please choose Rock, Paper, or Scissors.\n");
            continue;
        }

        printf("Player 2: Choose Rock, Paper or Scissors: ");
        fflush(stdout);
        scanf("%s", player2_choice);

        if (strcmp(player2_choice, "Rock") == 0) {
            player2 = 0;
        } else if (strcmp(player2_choice, "Paper") == 0) {
            player2 = 1;
        } else if (strcmp(player2_choice, "Scissors") == 0) {
            player2 = 2;
        } else {
            printf("Invalid input for Player 2. Please choose Rock, Paper, or Scissors.\n");
            continue;
        }

        result = compare_choices(player1, player2);
        printf("Player %d wins!\n", result);

        if (result == 0) {
            printf("It's a tie!\n");
        }

        rounds++;
    }

    printf("Game over!\n");

    return 0;
}

int compare_choices(int player1, int player2)
{
    if (player1 == 0 && player2 == 0) {
        return 0;
    } else if (player1 == 0 && player2 == 1) {
        return 1;
    } else if (player1 == 0 && player2 == 2) {
        return 2;
    } else if (player1 == 1 && player2 == 0) {
        return 2;
    } else if (player1 == 1 && player2 == 1) {
        return 0;
    } else if (player1 == 1 && player2 == 2) {
        return 1;
    } else if (player1 == 2 && player2 == 0) {
        return 1;
    } else if (player1 == 2 && player2 == 1) {
        return 2;
    } else if (player1 == 2 && player2 == 2) {
        return 0;
    } else {
        printf("Invalid input. Please choose Rock, Paper, or Scissors.\n");
        return -1;
    }
}