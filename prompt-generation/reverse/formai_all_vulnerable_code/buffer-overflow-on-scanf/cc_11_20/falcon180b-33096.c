//Falcon-180B DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numPlayers = rand() % 3 + 2; // Random number of players between 2 and 4
    int playerCount = 0;
    int playerScores[4] = {0};
    int activePlayer = 0;
    int roundCount = 0;
    int gameOver = 0;
    char playerNames[4][20];

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", playerNames[i]);
        playerScores[i] = rand() % 100; // Random starting score between 0 and 99
        playerCount++;
    }

    while (!gameOver) {
        printf("\nRound %d\n", roundCount + 1);
        for (int i = 0; i < playerCount; i++) {
            printf("%s: %d points\n", playerNames[i], playerScores[i]);
        }

        activePlayer = rand() % playerCount;
        printf("%s's turn\n", playerNames[activePlayer]);

        int roll = rand() % 6 + 1;
        printf("%s rolled a %d\n", playerNames[activePlayer], roll);

        if (roll == 1) {
            printf("%s lost all points\n", playerNames[activePlayer]);
            playerScores[activePlayer] = 0;
        } else if (roll == 2 || roll == 3 || roll == 4) {
            printf("%s gained %d points\n", playerNames[activePlayer], roll);
            playerScores[activePlayer] += roll;
        } else if (roll == 5) {
            printf("%s lost half the points\n", playerNames[activePlayer]);
            playerScores[activePlayer] /= 2;
        } else if (roll == 6) {
            printf("%s doubled the points\n", playerNames[activePlayer]);
            playerScores[activePlayer] *= 2;
        }

        if (playerScores[activePlayer] >= 100) {
            gameOver = 1;
            printf("%s won the game with %d points\n", playerNames[activePlayer], playerScores[activePlayer]);
        }

        roundCount++;
    }

    return 0;
}