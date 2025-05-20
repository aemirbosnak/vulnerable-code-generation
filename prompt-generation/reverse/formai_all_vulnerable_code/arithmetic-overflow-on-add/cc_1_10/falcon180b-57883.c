//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PLAYERS 10

#define PLAYER_NAME_LENGTH 20
#define PLAYER_SCORE_LENGTH 20

typedef struct {
    char name[PLAYER_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void init_players() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player ");
        sprintf(players[i].name + strlen(players[i].name), "%d", i + 1);
        players[i].score = 0;
    }
}

void print_scoreboard() {
    printf("SCOREBOARD\n");
    printf("--------------------\n");
    printf("NAME    SCORE\n");
    for (int i = 0; i < num_players; i++) {
        printf("%-20s %d\n", players[i].name, players[i].score);
    }
    printf("--------------------\n");
}

int main() {
    srand(time(NULL));
    init_players();
    int num_rounds = rand() % 5 + 1;
    int winner;
    for (int i = 0; i < num_rounds; i++) {
        printf("ROUND %d\n", i + 1);
        for (int j = 0; j < num_players; j++) {
            players[j].score = rand() % 100;
        }
        print_scoreboard();
        winner = rand() % num_players;
        printf("Player %d wins!\n", winner + 1);
        players[winner].score += 100;
    }
    print_scoreboard();
    return 0;
}