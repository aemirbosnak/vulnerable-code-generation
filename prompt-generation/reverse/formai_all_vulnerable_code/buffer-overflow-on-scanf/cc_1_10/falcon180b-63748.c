//Falcon-180B DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CHIPS 100
#define MAX_ROUNDS 10

int num_players;
int num_rounds;
int player_chips[MAX_PLAYERS];

void init_game(int num_players_, int num_rounds_) {
    num_players = num_players_;
    num_rounds = num_rounds_;

    for (int i = 0; i < num_players; i++) {
        player_chips[i] = MAX_CHIPS;
    }
}

void start_round(int current_round) {
    printf("Starting round %d...\n", current_round);
    fflush(stdout);
}

void end_round(int current_round, int winner) {
    printf("Round %d ended. Winner: %d\n", current_round, winner);
    fflush(stdout);
}

int main() {
    int num_players_, num_rounds_;
    printf("Enter number of players: ");
    scanf("%d", &num_players_);
    printf("Enter number of rounds: ");
    scanf("%d", &num_rounds_);

    init_game(num_players_, num_rounds_);

    for (int i = 0; i < num_rounds; i++) {
        start_round(i);
        int winner = rand() % num_players;
        end_round(i, winner);

        for (int j = 0; j < num_players; j++) {
            if (j == winner) {
                player_chips[j] += MAX_CHIPS / num_players;
            } else {
                player_chips[j] -= MAX_CHIPS / num_players;
            }
        }
    }

    return 0;
}