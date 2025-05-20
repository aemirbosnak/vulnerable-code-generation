//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 80

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initialize_players(Player players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

void print_players(Player players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    Player players[MAX_PLAYERS];
    initialize_players(players);

    while (1) {
        printf("Enter your name (up to %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", message);
        strcpy(players[0].name, message);
        printf("Welcome, %s! Type 'quit' to exit.\n", players[0].name);

        while (strcmp(message, "quit")!= 0) {
            printf("Type a message (up to %d characters): ", MAX_MESSAGE_LENGTH - 1);
            scanf("%s", message);
            printf("%s: %s\n", players[0].name, message);
        }

        print_players(players);
        break;
    }

    return 0;
}