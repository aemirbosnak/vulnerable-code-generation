//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

typedef struct {
    char name[30];
    int score;
} Player;

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void displayScores(Player players[], int count) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("\n");
}

void romanticVerse() {
    printf("Ah, love's embrace, the candle's soft light,\n");
    printf("Two hearts entwined in this wondrous night.\n");
    printf("Let the games of love begin, my dear friend,\n");
    printf("With laughter and joy, let the moments blend.\n\n");
}

int playRound(Player players[], int count) {
    // The scoring is random, yet fateful like love
    for (int i = 0; i < count; i++) {
        int points = rand() % 10 + 1; // Random points between 1 and 10
        players[i].score += points;
        printf("%s gains %d points!\n", players[i].name, points);
    }
    romanticVerse(); // Romantic interlude after each round
}

int declareWinner(Player players[], int count) {
    int maxScore = players[0].score;
    int winnerIndex = 0;

    for (int i = 1; i < count; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }
    
    printf("The winner is... %s with %d points! 🌹\n", players[winnerIndex].name, players[winnerIndex].score);
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    srand(time(0)); // Seed the random number generator

    printf("Welcome to the Romantic Table Game of Love!\n");
    printf("In this game, players earn points and express their affection. Let romance reign supreme!\n");
    
    do {
        printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    } while (numPlayers < 1 || numPlayers > MAX_PLAYERS);

    initializePlayers(players, numPlayers);
    
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        playRound(players, numPlayers);
        displayScores(players, numPlayers);
    }

    declareWinner(players, numPlayers);
    
    printf("Thank you for playing! May love be ever in your favor! 💖\n");
    return 0;
}