//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 2
#define MAX_ROUNDS 5
#define MIN_DIE_VALUE 1
#define MAX_DIE_VALUE 6

int main() {
    int players[MAX_PLAYERS] = {0};
    int current_player = 0;
    int rounds = 0;

    srand(time(NULL));

    while (rounds < MAX_ROUNDS) {
        int dice_roll = rand() % (MAX_DIE_VALUE - MIN_DIE_VALUE + 1) + MIN_DIE_VALUE;
        int player_guess;

        printf("Player %d, the dice rolled %d. Enter your guess (even or odd): ", current_player + 1, dice_roll);
        scanf("%d", &player_guess);

        if (player_guess == (dice_roll % 2)) {
            printf("Congratulations, Player %d! You guessed correctly.\n", current_player + 1);
            players[current_player]++;
        } else {
            printf("Sorry, Player %d. Better luck next time.\n", current_player + 1);
        }

        current_player = (current_player + 1) % MAX_PLAYERS;
        rounds++;
    }

    printf("\nGame Over!\n");

    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d won %d rounds.\n", i + 1, players[i]);
    }

    int winner = players[0];
    for (int i = 1; i < MAX_PLAYERS; i++) {
        if (players[i] > winner) {
            winner = players[i];
        }
    }

    printf("Player %d won the game with %d rounds.\n", winner + 1, winner);

    return 0;
}