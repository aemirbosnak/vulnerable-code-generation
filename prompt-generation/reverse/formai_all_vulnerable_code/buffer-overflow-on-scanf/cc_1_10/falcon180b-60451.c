//Falcon-180B DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5

typedef struct {
    char name[50];
    int score;
} Player;

void startRound(Player players[], int numPlayers) {
    int i;
    char action;
    srand(time(NULL));
    for (i = 0; i < numPlayers; i++) {
        printf("Player %s, what will you do? ", players[i].name);
        scanf(" %c", &action);
        if (action == 'a') {
            printf("Player %s attacks!\n", players[i].name);
        } else if (action == 'd') {
            printf("Player %s defends.\n", players[i].name);
        } else {
            printf("Invalid action.\n");
        }
        if (rand() % 2 == 0) {
            players[i].score++;
        }
    }
}

void endRound(Player players[], int numPlayers) {
    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("Player %s has %d points.\n", players[i].name, players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;
    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    printf("Enter the names of the players:\n");
    for (int i = 0; i < numPlayers; i++) {
        scanf(" %s", players[i].name);
    }
    int numRounds;
    printf("Enter the number of rounds (up to %d): ", MAX_ROUNDS);
    scanf("%d", &numRounds);
    for (int i = 0; i < numRounds; i++) {
        startRound(players, numPlayers);
        endRound(players, numPlayers);
    }
    return 0;
}