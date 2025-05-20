//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void add_player(char *name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Error: cannot add more players\n");
        return;
    }

    strcpy(players[num_players].name, name);
    players[num_players].score = 0;
    num_players++;
}

void remove_player(char *name) {
    int i;

    for (i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_players) {
        printf("Error: player not found\n");
        return;
    }

    for (; i < num_players - 1; i++) {
        players[i] = players[i + 1];
    }

    num_players--;
}

void print_players() {
    int i;

    printf("Players:\n");
    for (i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    char input[100];
    int i;

    printf("Welcome to the Binary Converter Multiplayer Game!\n");
    printf("Enter the names of the players (max %d):\n", MAX_PLAYERS);

    for (i = 0; i < MAX_PLAYERS; i++) {
        scanf("%s", input);
        add_player(input);
    }

    while (1) {
        printf("\nEnter a binary number (or 'q' to quit):\n");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        for (i = 0; i < num_players; i++) {
            int result = strtol(input, NULL, 2);
            printf("%s: %d\n", players[i].name, result);
            players[i].score += result;
        }

        print_players();
    }

    printf("Thanks for playing!\n");
    return 0;
}