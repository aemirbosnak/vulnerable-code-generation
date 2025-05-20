#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_GAME_ROUNDS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int current_player = 0;

void welcome_message() {
    printf("Welcome to the Dangerous Dungeon Adventure!\n\n");
}

void print_scoreboard() {
    for (int i = 0; i < current_player; ++i) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void increase_player_score(int amount) {
    players[current_player].score += amount;
}

void next_player() {
    current_player = (current_player + 1) % MAX_PLAYERS;
}

void game_round() {
    int score = rand() % 100;
    printf("Player %s gained %d points in this round!\n", players[current_player].name, score);
    increase_player_score(score);
}

int main() {
    char input[MAX_NAME_LENGTH];

    welcome_message();

    printf("Enter player name (max 20 characters): ");
    scanf("%s", input);
    strcpy(players[current_player].name, input);

    for (int i = 0; i < MAX_GAME_ROUNDS; ++i) {
        game_round();
        print_scoreboard();
        next_player();
    }

    print_scoreboard();
    return 0;
}
