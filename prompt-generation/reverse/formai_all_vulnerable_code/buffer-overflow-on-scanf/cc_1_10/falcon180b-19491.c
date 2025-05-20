//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5

typedef struct {
    char name[50];
    int score;
} player_t;

void init_players(player_t players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        sprintf(players[i].name, "Player %d", i + 1);
        players[i].score = 0;
    }
}

void display_players(player_t players[]) {
    printf("Players:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void roll_dice(int *dice) {
    srand(time(NULL));
    *dice = rand() % 6 + 1;
}

void play_round(player_t players[], int num_players, int round) {
    printf("Round %d:\n", round);
    for (int i = 0; i < num_players; i++) {
        roll_dice(&players[i].score);
        printf("%s rolled a %d\n", players[i].name, players[i].score);
    }
    display_players(players);
}

int main() {
    player_t players[MAX_PLAYERS];
    init_players(players);

    int num_players = 0;
    while (num_players < MAX_PLAYERS) {
        printf("Enter your name: ");
        scanf("%s", players[num_players].name);
        num_players++;
    }

    for (int i = 0; i < MAX_ROUNDS; i++) {
        play_round(players, num_players, i + 1);
    }

    return 0;
}