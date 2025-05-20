//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Player;

void sanitize_input(char *input) {
    int i = 0, j = 0;
    while (input[i]!= '\0') {
        if (isalnum(input[i])) {
            input[j++] = tolower(input[i]);
        }
        i++;
    }
    input[j] = '\0';
}

void print_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i + 1, players[i].name);
    }
}

int main() {
    int num_players;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        sanitize_input(players[i].name);
    }

    for (int i = 0; i < num_players; i++) {
        printf("Player %d, enter your message: ", i + 1);
        fgets(players[i].message, MAX_MESSAGE_LENGTH, stdin);
        sanitize_input(players[i].message);
    }

    printf("Player 1: %s\n", players[0].message);
    printf("Player 2: %s\n", players[1].message);

    return 0;
}