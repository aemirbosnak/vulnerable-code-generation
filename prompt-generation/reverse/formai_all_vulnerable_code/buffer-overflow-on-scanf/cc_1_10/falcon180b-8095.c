//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_LINE 80

typedef struct {
    char name[20];
    int score;
    char token[20];
} player_t;

player_t players[MAX_PLAYERS];

void init_players() {
    for(int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
        strcpy(players[i].token, "");
    }
}

void print_player(player_t player) {
    printf("Name: %s\nScore: %d\nToken: %s\n", player.name, player.score, player.token);
}

void print_players() {
    printf("Players:\n");
    for(int i = 0; i < MAX_PLAYERS; i++) {
        print_player(players[i]);
    }
}

void init_game() {
    for(int i = 0; i < MAX_PLAYERS; i++) {
        char name[20];
        printf("Enter name for player %d: ", i+1);
        scanf("%s", name);
        strcpy(players[i].name, name);
    }
}

void start_round() {
    printf("Round starting...\n");
    srand(time(NULL));
    int roll = rand() % 6 + 1;
    for(int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %s rolled a %d.\n", players[i].name, roll);
        players[i].score += roll;
    }
}

void end_round() {
    printf("Round ended.\n");
}

void play_game() {
    init_game();
    int rounds = 5;
    for(int i = 0; i < rounds; i++) {
        start_round();
        sleep(1);
        end_round();
        sleep(1);
    }
    print_players();
}

int main() {
    init_players();
    play_game();
    return 0;
}