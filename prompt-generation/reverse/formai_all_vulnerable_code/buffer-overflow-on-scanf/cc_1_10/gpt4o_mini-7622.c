//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 50
#define MAX_ROUNDS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, MAX_NAME_LENGTH, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0;  // Remove newline
        players[i].score = 0;
    }
}

void displayScores(Player players[], int playerCount) {
    printf("\nScores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int rollDice() {
    return (rand() % 6) + 1;  // Returns a random number between 1 and 6
}

void playRound(Player players[], int playerCount, int roundNumber) {
    printf("\n--- ROUND %d ---\n", roundNumber);
    for (int i = 0; i < playerCount; i++) {
        printf("%s's turn to roll the dice.\n", players[i].name);
        int roll = rollDice();
        players[i].score += roll;
        printf("%s rolled a %d! Current score: %d\n", players[i].name, roll, players[i].score);
    }
}

void determineWinner(Player players[], int playerCount) {
    int maxScore = players[0].score;
    int winnerIndex = 0;
    
    for (int i = 1; i < playerCount; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }
    
    printf("\n*** The winner is %s with a score of %d! ***\n", players[winnerIndex].name, players[winnerIndex].score);
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    
    Player players[MAX_PLAYERS];
    int playerCount;
    
    printf("Welcome to the Dice Rolling Game!\n");
    do {
        printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &playerCount);
        getchar();  // Clear newline character from input buffer
    } while (playerCount < 1 || playerCount > MAX_PLAYERS);
    
    initializePlayers(players, playerCount);
    
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        playRound(players, playerCount, round);
        displayScores(players, playerCount);
    }
    
    determineWinner(players, playerCount);
    
    return 0;
}