//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 50
#define MAX_ROUNDS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, MAX_NAME_LENGTH, stdin);
        strtok(players[i].name, "\n"); // Remove newline character
        players[i].score = 0;
    }
}

void printScores(Player players[], int playerCount) {
    printf("\n--- Scores ---\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("----------------\n");
}

void playRound(Player players[], int playerCount, int roundNumber) {
    printf("\n--- Round %d ---\n", roundNumber);
    for (int i = 0; i < playerCount; i++) {
        int points = rand() % 10 + 1; // Generate random points between 1 and 10
        players[i].score += points;
        printf("%s scored %d points!\n", players[i].name, points);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    int playerCount;
    Player players[MAX_PLAYERS];

    printf("Welcome to the Dynamic Score Game!\n");
    printf("How many players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    getchar(); // Clear the newline character from input buffer

    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    initializePlayers(players, playerCount);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        playRound(players, playerCount, round);
        printScores(players, playerCount);
    }

    // Determine winner
    int maxScore = players[0].score;
    int winnerIndex = 0;
    for (int i = 1; i < playerCount; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }

    printf("\nCongratulations %s! You are the winner with %d points!\n", players[winnerIndex].name, players[winnerIndex].score);
    
    return 0;
}