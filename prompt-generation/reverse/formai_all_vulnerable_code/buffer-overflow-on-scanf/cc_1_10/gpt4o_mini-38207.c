//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define ROUNDS 5

void initializeScores(int scores[], int numPlayers);
void rollDice(int *diceRoll);
void displayScores(int scores[], int numPlayers);
int determineWinner(int scores[], int numPlayers);

int main() {
    int numPlayers;
    int scores[MAX_PLAYERS] = {0};
    
    // Seed random number generator
    srand(time(NULL));

    printf("Welcome to the Dice Rolling Game!\n");
    printf("Enter number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    // Validate the number of players
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    initializeScores(scores, numPlayers);

    for (int round = 1; round <= ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int player = 0; player < numPlayers; player++) {
            int diceRoll;
            rollDice(&diceRoll);
            scores[player] += diceRoll;
            printf("Player %d rolled a %d (Total score: %d)\n", player + 1, diceRoll, scores[player]);
        }
        displayScores(scores, numPlayers);
    }

    int winner = determineWinner(scores, numPlayers);
    printf("\nPlayer %d wins with a score of %d!\n", winner + 1, scores[winner]);

    return 0;
}

void initializeScores(int scores[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        scores[i] = 0;
    }
}

void rollDice(int *diceRoll) {
    *diceRoll = (rand() % 6) + 1; // Dice rolls between 1 and 6
}

void displayScores(int scores[], int numPlayers) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
}

int determineWinner(int scores[], int numPlayers) {
    int highestScore = scores[0];
    int winner = 0;

    for (int i = 1; i < numPlayers; i++) {
        if (scores[i] > highestScore) {
            highestScore = scores[i];
            winner = i;
        }
    }
    return winner;
}