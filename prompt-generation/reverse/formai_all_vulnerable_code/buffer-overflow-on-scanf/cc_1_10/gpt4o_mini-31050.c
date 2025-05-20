//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\n----- Scoreboard -----\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("----------------------\n");
}

int rollDice() {
    return (rand() % 6) + 1; // Random number between 1 and 6
}

void playRound(Player players[], int numPlayers) {
    printf("\n--- New Round! ---\n");
    for (int i = 0; i < numPlayers; i++) {
        int roll = rollDice();
        players[i].score += roll;
        printf("%s rolled a %d! Total score: %d\n", players[i].name, roll, players[i].score);
    }
}

int findWinner(Player players[], int numPlayers) {
    int maxScore = players[0].score;
    int winnerIndex = 0;

    for (int i = 1; i < numPlayers; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }
    return winnerIndex;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Dice Rolling Game!\n");
    printf("How many players (1 to %d)? ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Game will exit.\n");
        return 1;
    }

    initializePlayers(players, numPlayers);
    displayScores(players, numPlayers);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        playRound(players, numPlayers);
        displayScores(players, numPlayers);
    }
    
    int winnerIndex = findWinner(players, numPlayers);
    printf("\nCongratulations %s! You are the winner with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);
    return 0;
}