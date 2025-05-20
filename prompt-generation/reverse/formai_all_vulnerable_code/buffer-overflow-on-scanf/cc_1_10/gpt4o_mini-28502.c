//GPT-4o-mini DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 100
#define MAX_GAMES 10

// Function prototypes
void recordGameResults(int playerScores[], int numPlayers);
void displayStatistics(int playerScores[], int numPlayers);
void displayTopPlayers(int playerScores[], int numPlayers, int topCount);
void sortScores(int playerScores[], int numPlayers);
void displayMenu();

int main() {
    int playerScores[MAX_PLAYERS] = {0};
    int numPlayers = 0;
    int choice;

    srand(time(NULL)); // Seed random number generator

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
                scanf("%d", &numPlayers);
                if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
                    printf("Invalid number of players.\n");
                } else {
                    recordGameResults(playerScores, numPlayers);
                }
                break;
            case 2:
                displayStatistics(playerScores, numPlayers);
                break;
            case 3:
                printf("Enter the number of top players to display: ");
                int topCount;
                scanf("%d", &topCount);
                displayTopPlayers(playerScores, numPlayers, topCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Game Statistics Menu ===\n");
    printf("1. Record Game Results\n");
    printf("2. Display Statistics\n");
    printf("3. Display Top Players\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void recordGameResults(int playerScores[], int numPlayers) {
    printf("Recording game results...\n");
    for (int i = 0; i < numPlayers; i++) {
        playerScores[i] = rand() % 100; // Random score between 0 and 99
        printf("Player %d scored: %d\n", i + 1, playerScores[i]);
    }
}

void displayStatistics(int playerScores[], int numPlayers) {
    if (numPlayers == 0) {
        printf("No players have recorded scores.\n");
        return;
    }

    int totalScore = 0, highestScore = 0, lowestScore = 100;
    for (int i = 0; i < numPlayers; i++) {
        totalScore += playerScores[i];
        if (playerScores[i] > highestScore) {
            highestScore = playerScores[i];
        }
        if (playerScores[i] < lowestScore) {
            lowestScore = playerScores[i];
        }
    }

    float averageScore = (float)totalScore / numPlayers;

    printf("\n=== Game Statistics ===\n");
    printf("Total Players: %d\n", numPlayers);
    printf("Total Score: %d\n", totalScore);
    printf("Average Score: %.2f\n", averageScore);
    printf("Highest Score: %d\n", highestScore);
    printf("Lowest Score: %d\n", lowestScore);
}

void displayTopPlayers(int playerScores[], int numPlayers, int topCount) {
    if (numPlayers == 0) {
        printf("No players have recorded scores.\n");
        return;
    }

    if (topCount < 1 || topCount > numPlayers) {
        printf("Invalid number of top players to display.\n");
        return;
    }

    sortScores(playerScores, numPlayers);

    printf("\n=== Top %d Players ===\n", topCount);
    for (int i = numPlayers - 1; i >= numPlayers - topCount; i--) {
        printf("Player %d: %d\n", i + 1, playerScores[i]);
    }
}

void sortScores(int playerScores[], int numPlayers) {
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            if (playerScores[j] < playerScores[j + 1]) {
                // Swap scores
                int temp = playerScores[j];
                playerScores[j] = playerScores[j + 1];
                playerScores[j + 1] = temp;
            }
        }
    }
}