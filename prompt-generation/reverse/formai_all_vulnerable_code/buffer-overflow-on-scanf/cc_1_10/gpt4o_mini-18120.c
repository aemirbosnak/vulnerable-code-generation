//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_DICE 6

// Function to roll a single die
int rollDie() {
    return (rand() % 6) + 1;
}

// Function to roll multiple dice
int rollDice(int numberOfDice) {
    int total = 0;
    for (int i = 0; i < numberOfDice; i++) {
        total += rollDie();
    }
    return total;
}

void displayScores(int scores[], int playerCount) {
    printf("\nScores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int playerCount;
    int rounds;

    printf("Welcome to the Multiplayer Dice Roller!\n");
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);

    while (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Please enter a valid number of players (2 - %d): ", MAX_PLAYERS);
        scanf("%d", &playerCount);
    }

    printf("Enter number of rounds to play: ");
    scanf("%d", &rounds);

    int scores[MAX_PLAYERS] = {0};

    // Game loop for the defined number of rounds
    for (int round = 1; round <= rounds; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < playerCount; i++) {
            int numberOfDice;
            printf("Player %d, enter number of dice to roll (1-%d): ", i + 1, MAX_DICE);
            scanf("%d", &numberOfDice);

            while (numberOfDice < 1 || numberOfDice > MAX_DICE) {
                printf("Invalid input! Please enter number of dice (1-%d): ", MAX_DICE);
                scanf("%d", &numberOfDice);
            }

            int result = rollDice(numberOfDice);
            printf("Player %d rolled: %d\n", i + 1, result);
            scores[i] += result; // Cumulatively add the scores
        }
        displayScores(scores, playerCount);
    }

    // Determine winner
    int maxScore = scores[0];
    int winnerIndex = 0;
    for (int i = 1; i < playerCount; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            winnerIndex = i;
        }
    }

    printf("\n--- Game Over ---\n");
    printf("The winner is Player %d with a score of %d!\n", winnerIndex + 1, maxScore);

    return 0;
}