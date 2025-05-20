//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_DICE 6
#define MAX_ROLLS 100

typedef struct {
    char name[20];
    int score;
} player_t;

player_t players[MAX_PLAYERS];
int num_players;

int roll_dice() {
    return rand() % 6 + 1;
}

void print_player_scores() {
    printf("Player Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Distributed Dice Roller!\n");

    num_players = 0;
    while (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    int total_rolls = 0;
    while (total_rolls < MAX_ROLLS) {
        for (int i = 0; i < num_players; i++) {
            printf("%s, roll the dice! ", players[i].name);
            players[i].score += roll_dice();
            total_rolls++;
        }
        print_player_scores();
    }

    printf("Game over! Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}