//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_ROUNDS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initPlayers(Player *players) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

void displayScores(Player *players) {
    printf("Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].score > 0) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    initPlayers(players);

    int numPlayers = rand() % MAX_PLAYERS + 2;
    printf("Number of players: %d\n", numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("Round %d:\n", round);
        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d's turn:\n", i + 1);
            int choice = rand() % 3;
            if (choice == 0) {
                players[i].score++;
            } else if (choice == 1) {
                players[i].score--;
            }
        }
        displayScores(players);
    }

    return 0;
}