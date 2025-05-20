//Falcon-180B DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5
#define MAX_SCORE 100

typedef struct {
    char name[20];
    int score;
} Player;

void initPlayers(Player players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        sprintf(players[i].name, "Player %d", i + 1);
        players[i].score = 0;
    }
}

void printPlayers(Player players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void playRound(Player players[], int round) {
    int roll;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %s, roll the dice! ", players[i].name);
        scanf("%d", &roll);
        players[i].score += roll;
        printf("%s rolled %d and now has a score of %d.\n", players[i].name, roll, players[i].score);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    initPlayers(players);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("Round %d:\n", round);
        playRound(players, round);
        printf("\n");
    }

    printf("Final scores:\n");
    printPlayers(players);

    return 0;
}