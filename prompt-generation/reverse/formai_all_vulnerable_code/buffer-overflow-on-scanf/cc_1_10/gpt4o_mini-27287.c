//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50

void rollDice(int sides, int* result) {
    *result = (rand() % sides) + 1; // Generate a random dice roll between 1 and 'sides'
}

void displayScores(char playerNames[][MAX_NAME_LENGTH], int scores[], int playerCount) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", playerNames[i], scores[i]);
    }
}

int main() {
    int playerCount;
    char playerNames[MAX_PLAYERS][MAX_NAME_LENGTH];
    int scores[MAX_PLAYERS] = {0}; // Initialize scores to 0

    printf("Welcome to the Multiplayer Dice Roller!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    // Get player names
    for (int i = 0; i < playerCount; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", playerNames[i]);
    }

    int sides, rounds;
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);
    
    printf("Enter the number of rounds to play: ");
    scanf("%d", &rounds);

    srand(time(NULL)); // Seed random number generator with current time

    for (int round = 1; round <= rounds; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < playerCount; i++) {
            int rollResult;
            printf("%s's turn! Press Enter to roll the dice...", playerNames[i]);
            getchar(); // Wait for Enter key
            getchar(); // Additional getchar to absorb the newline character

            rollDice(sides, &rollResult);
            printf("%s rolled a %d!\n", playerNames[i], rollResult);
            scores[i] += rollResult; // Add roll result to player's score
        }
        displayScores(playerNames, scores, playerCount);
    }

    printf("\n--- Final Scores ---\n");
    displayScores(playerNames, scores, playerCount);
    
    // Determine the winner
    int highestScore = 0;
    int winnerIndex = -1;
    for (int i = 0; i < playerCount; i++) {
        if (scores[i] > highestScore) {
            highestScore = scores[i];
            winnerIndex = i;
        }
    }

    printf("\nThe winner is %s with a score of %d!\n", playerNames[winnerIndex], highestScore);
    return 0;
}