//Falcon-180B DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 10
#define MAX_PLAYERS 4

typedef struct {
    char name[20];
    int score;
} Player;

void initPlayers(Player players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        sprintf(players[i].name, "Player %d", i+1);
        players[i].score = 0;
    }
}

void playRound(Player players[], int numPlayers, int *winner) {
    int highestScore = 0;
    for (int i = 0; i < numPlayers; i++) {
        int roll = rand() % 6 + 1;
        printf("%s rolled a %d.\n", players[i].name, roll);
        players[i].score += roll;
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            *winner = i;
        }
    }
}

void printScores(Player players[], int numPlayers) {
    printf("Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    initPlayers(players);

    int numPlayers = 0;
    while (numPlayers < MAX_PLAYERS) {
        printf("Enter player name: ");
        scanf("%s", players[numPlayers].name);
        numPlayers++;
    }

    int round = 1;
    while (round <= MAX_ROUNDS) {
        int winner = -1;
        playRound(players, numPlayers, &winner);
        printf("\nRound %d winner: %s\n", round, players[winner].name);

        if (round == MAX_ROUNDS) {
            printf("Final scores:\n");
            printScores(players, numPlayers);
        } else {
            printf("Scores after round %d:\n", round);
            printScores(players, numPlayers);
        }

        round++;
    }

    return 0;
}