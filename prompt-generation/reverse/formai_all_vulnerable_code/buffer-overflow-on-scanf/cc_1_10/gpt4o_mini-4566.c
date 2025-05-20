//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

void initializePlayers(Player players[], int count);
void playRound(Player players[], int count, int round);
void displayScores(Player players[], int count);
int findWinner(Player players[], int count);
void sortPlayers(Player players[], int count);

int main() {
    int playerCount;
    Player players[MAX_PLAYERS];

    printf("Enter number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    while (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Enter again (1 - %d): ", MAX_PLAYERS);
        scanf("%d", &playerCount);
    }

    initializePlayers(players, playerCount);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        playRound(players, playerCount, round);
        displayScores(players, playerCount);
    }

    int winnerIndex = findWinner(players, playerCount);
    printf("\nThe winner is %s with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);

    return 0;
}

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void playRound(Player players[], int count, int round) {
    printf("\n--- Round %d ---\n", round);
    for (int i = 0; i < count; i++) {
        int roundScore = rand() % 10 + 1; // Generate a score between 1 and 10
        players[i].score += roundScore;
        printf("%s scored %d in this round.\n", players[i].name, roundScore);
    }
}

void displayScores(Player players[], int count) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int findWinner(Player players[], int count) {
    int maxScore = -1;
    int winnerIndex = -1;
    for (int i = 0; i < count; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }
    return winnerIndex;
}