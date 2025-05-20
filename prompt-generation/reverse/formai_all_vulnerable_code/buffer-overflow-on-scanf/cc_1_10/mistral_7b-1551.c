//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define NUM_ROUNDS 5

int main() {
    int player1_wins = 0, player2_wins = 0, random_number, player1_attempts, player2_attempts;
    char player1_name[20], player2_name[20];

    printf("Welcome to Number Guessing Game!\n");
    printf("Player 1 and Player 2, please enter your names:\n");
    scanf("%s", player1_name);
    scanf("%s", player2_name);

    srand(time(NULL));

    while (player1_wins < NUM_ROUNDS && player2_wins < NUM_ROUNDS) {
        random_number = rand() % 100 + 1;
        printf("\nRound %d:\n", rand() % 2 + 1);

        player1:
        printf("%s is guessing: ", player1_name);
        scanf("%d", &player1_attempts);

        if (player1_attempts < 1 || player1_attempts > MAX_ATTEMPTS) {
            printf("Invalid attempt! Try again.\n");
            goto player1;
        }

        if (player1_attempts == random_number) {
            printf("%s wins this round! (in %d attempts)\n", player1_name, player1_attempts);
            player1_wins++;
            goto next_round;
        } else {
            printf("%s's guess is incorrect. %s, it's your turn.\n", player1_name, player2_name);
        }

        player2:
        printf("%s is guessing: ", player2_name);
        scanf("%d", &player2_attempts);

        if (player2_attempts < 1 || player2_attempts > MAX_ATTEMPTS) {
            printf("Invalid attempt! Try again.\n");
            goto player2;
        }

        if (player2_attempts == random_number) {
            printf("%s wins this round! (in %d attempts)\n", player2_name, player2_attempts);
            player2_wins++;
            goto next_round;
        } else {
            printf("%s's guess is incorrect. %s, it's %s turn again.\n", player2_name, player1_name, player1_name);
        }

        next_round:
        printf("\n");
    }

    if (player1_wins > player2_wins) {
        printf("%s wins the game with a score of %d - %d.\n", player1_name, player1_wins, player2_wins);
    } else {
        printf("%s wins the game with a score of %d - %d.\n", player2_name, player2_wins, player1_wins);
    }

    return 0;
}