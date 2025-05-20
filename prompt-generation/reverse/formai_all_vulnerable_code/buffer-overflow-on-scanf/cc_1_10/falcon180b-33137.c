//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_ROUNDS 10

struct player {
    char name[MAX_NAME_LENGTH];
    int score;
};

void initialize_players(struct player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

void print_players(struct player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s\n", i + 1, players[i].name);
    }
}

void play_round(int num_players, struct player *players, int round) {
    int num_coins[num_players];
    for (int i = 0; i < num_players; i++) {
        num_coins[i] = 0;
    }

    int num_taken[num_players];
    for (int i = 0; i < num_players; i++) {
        num_taken[i] = 0;
    }

    int num_coins_left = 100;
    while (num_coins_left > 0) {
        int max_index = -1;
        for (int i = 0; i < num_players; i++) {
            if (num_coins[i] == 0) {
                max_index = i;
                break;
            }
        }

        if (max_index == -1) {
            break;
        }

        num_coins[max_index] = num_coins_left;
        num_taken[max_index]++;
        num_coins_left -= num_coins_left;
    }

    printf("Round %d:\n", round);
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s took %d coins and now has %d coins.\n", i + 1, players[i].name, num_coins[i], num_coins[i] + num_taken[i]);
    }
}

void play_game(int num_players, struct player *players) {
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        play_round(num_players, players, round);
    }
}

int main() {
    int num_players;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &num_players);

    struct player *players = (struct player *)malloc(num_players * sizeof(struct player));
    initialize_players(players, num_players);

    play_game(num_players, players);

    free(players);
    return 0;
}