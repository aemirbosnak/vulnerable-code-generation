//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50

void rollDice(int playerIndex, int numRolls, int *scores) {
    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % 6 + 1; // Rolls a die (1 to 6)
        scores[playerIndex] += roll;
        printf("Player %d rolled a %d (Total Score: %d)\n", playerIndex + 1, roll, scores[playerIndex]);
    }
}

int findWinner(int *scores, int numPlayers) {
    int maxScore = scores[0];
    int winnerIndex = 0;

    for (int i = 1; i < numPlayers; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            winnerIndex = i;
        }
    }
    return winnerIndex;
}

void displayScores(char names[][MAX_NAME_LENGTH], int *scores, int numPlayers) {
    printf("\nScores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", names[i], scores[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int numPlayers;
    char names[MAX_PLAYERS][MAX_NAME_LENGTH];
    int scores[MAX_PLAYERS] = {0}; // Initialize scores to 0

    printf("Welcome to the Multiplayer Dice Roller Game!\n");
    printf("Enter the number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    // Input player names
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", names[i]);
    }
    
    int numRolls;
    printf("Enter the number of rolls each player will have: ");
    scanf("%d", &numRolls);
    
    // Start rolling dice
    printf("\nLet's start rolling the dice!\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("\n%s's Turn:\n", names[i]);
        rollDice(i, numRolls, scores);
    }

    // Display scores
    displayScores(names, scores, numPlayers);
    
    // Determine the winner
    int winnerIndex = findWinner(scores, numPlayers);
    printf("\nThe winner is %s with a total score of %d!\n", names[winnerIndex], scores[winnerIndex]);

    return 0;
}