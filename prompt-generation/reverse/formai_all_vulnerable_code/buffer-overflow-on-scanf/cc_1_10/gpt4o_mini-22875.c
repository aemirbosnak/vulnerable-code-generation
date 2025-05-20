//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define TARGET_SCORE 20

void rollDie(int *roll) {
    *roll = rand() % 6 + 1; // Roll a die (1-6)
}

void printScores(int scores[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d Score: %d\n", i + 1, scores[i]);
    }
}

int checkWinner(int scores[], int numPlayers, int targetScore) {
    for (int i = 0; i < numPlayers; i++) {
        if (scores[i] >= targetScore) {
            return i; // Return the index of the winner
        }
    }
    return -1; // No winner yet
}

void playGame(int numPlayers) {
    int scores[MAX_PLAYERS] = {0};
    int currentPlayer = 0;
    int roll;

    while (1) {
        printf("\nPlayer %d's turn:\n", currentPlayer + 1);
        rollDie(&roll);
        printf("Player %d rolled a %d!\n", currentPlayer + 1, roll);
        scores[currentPlayer] += roll;

        // Check for a winner
        int winner = checkWinner(scores, numPlayers, TARGET_SCORE);
        if (winner != -1) {
            printf("Player %d wins with a score of %d!\n", winner + 1, scores[winner]);
            break;
        }

        // Print current scores
        printScores(scores, numPlayers);

        // Move to the next player
        currentPlayer = (currentPlayer + 1) % numPlayers;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int numPlayers;

    printf("Welcome to the Dice Roll Game!\n");
    printf("Enter the number of players (1-4): ");
    scanf("%d", &numPlayers);

    // Validate the number of players
    while (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players! Please choose between 1 and 4: ");
        scanf("%d", &numPlayers);
    }

    playGame(numPlayers);

    return 0;
}