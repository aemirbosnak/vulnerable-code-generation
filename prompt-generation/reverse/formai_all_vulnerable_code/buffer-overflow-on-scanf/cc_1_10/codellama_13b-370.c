//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[50];
    int score;
} player;

void init_players(player players[], int n) {
    for (int i = 0; i < n; i++) {
        players[i].score = 0;
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }
}

void print_players(player players[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int roll_dice(int n) {
    return rand() % n + 1;
}

void play_round(player players[], int n, int rounds) {
    int winner = 0;
    int current_round = 1;
    while (current_round <= rounds) {
        for (int i = 0; i < n; i++) {
            int dice_roll = roll_dice(6);
            if (dice_roll == 6) {
                winner = i;
                break;
            }
        }
        if (winner != 0) {
            players[winner].score += 1;
            printf("Player %d wins round %d\n", winner + 1, current_round);
            break;
        }
        current_round++;
    }
}

int main() {
    srand(time(NULL));
    player players[MAX_PLAYERS];
    int n_players;
    printf("Enter number of players: ");
    scanf("%d", &n_players);
    if (n_players > MAX_PLAYERS) {
        printf("Maximum number of players is %d\n", MAX_PLAYERS);
        return 1;
    }
    init_players(players, n_players);
    printf("Players:\n");
    print_players(players, n_players);
    int rounds;
    printf("Enter number of rounds: ");
    scanf("%d", &rounds);
    if (rounds > MAX_ROUNDS) {
        printf("Maximum number of rounds is %d\n", MAX_ROUNDS);
        return 1;
    }
    play_round(players, n_players, rounds);
    printf("Final scores:\n");
    print_players(players, n_players);
    return 0;
}