//Falcon-180B DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_GAMES 100
#define MAX_SCORE 100

struct player {
    char name[20];
    int score;
};

void init_players(struct player players[]);
void display_players(struct player players[], int count);
void play_game(struct player players[], int count);

int main() {
    struct player players[MAX_PLAYERS];
    int num_players, i;
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    if (num_players > MAX_PLAYERS) {
        printf("Error: Too many players.\n");
        return 1;
    }
    init_players(players);
    for (i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i+1, players[i].name);
    }
    play_game(players, num_players);
    return 0;
}

void init_players(struct player players[]) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].score = 0;
        sprintf(players[i].name, "Player %d", i+1);
    }
}

void display_players(struct player players[], int count) {
    int i;
    printf("Player Scores:\n");
    for (i = 0; i < count; i++) {
        printf("%d. %s: %d\n", i+1, players[i].name, players[i].score);
    }
}

void play_game(struct player players[], int count) {
    int i, j, k, max_score = 0, winner;
    srand(time(NULL));
    for (k = 0; k < MAX_GAMES; k++) {
        for (i = 0; i < count; i++) {
            players[i].score += rand() % MAX_SCORE;
        }
        max_score = 0;
        for (i = 0; i < count; i++) {
            if (players[i].score > max_score) {
                max_score = players[i].score;
                winner = i;
            }
        }
        printf("Game %d winner: %s with score %d\n", k+1, players[winner].name, max_score);
    }
}