//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10
#define MAX_SCORES 10

typedef struct {
    char name[30];
    int scores[MAX_SCORES];
    int totalScore;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].totalScore = 0;
    }
}

void printScores(Player players[], int numPlayers, int round) {
    printf("\nScores after round %d:\n", round);
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: ", players[i].name);
        for (int j = 0; j < MAX_SCORES; j++) {
            if (players[i].scores[j] > 0) {
                printf("%d ", players[i].scores[j]);
            }
        }
        printf("(Total: %d)\n", players[i].totalScore);
    }
}

int playRound(Player players[], int numPlayers, int round) {
    int roundScores[MAX_PLAYERS] = {0};
    printf("\n--- Round %d ---\n", round);
    
    for (int i = 0; i < numPlayers; i++) {
        roundScores[i] = rand() % 10 + 1; // Random score between 1 and 10
        players[i].scores[round - 1] = roundScores[i];
        players[i].totalScore += roundScores[i];
        printf("%s scored: %d\n", players[i].name, roundScores[i]);
    }
    
    return 0;
}

void declareWinner(Player players[], int numPlayers) {
    int highestScore = 0;
    Player* winner = NULL;
    
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].totalScore > highestScore) {
            highestScore = players[i].totalScore;
            winner = &players[i];
        }
    }

    printf("\nThe winner is %s with a total score of %d!\n", winner->name, winner->totalScore);
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    initializePlayers(players, numPlayers);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        playRound(players, numPlayers, round);
        printScores(players, numPlayers, round);
    }

    declareWinner(players, numPlayers);

    return 0;
}