//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers = 5;
    int numBingoCards = 10;
    int numRows = 5;
    int numColumns = 5;
    int numBalls = 75;
    int **bingoCards = (int **)malloc(numBingoCards * sizeof(int *));
    int **bingoDraw = (int **)malloc(numBalls * sizeof(int *));

    for (int i = 0; i < numBingoCards; i++) {
        bingoCards[i] = (int *)malloc(numRows * numColumns * sizeof(int));
    }

    for (int j = 0; j < numBalls; j++) {
        bingoDraw[j] = (int *)malloc(numRows * sizeof(int));
    }

    // Initialize the bingo cards and draw cards
    for (int i = 0; i < numBingoCards; i++) {
        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < numColumns; k++) {
                bingoCards[i][j * numColumns + k] = (rand() % 2) + 1;
            }
        }
    }

    for (int j = 0; j < numBalls; j++) {
        for (int k = 0; k < numRows; k++) {
            bingoDraw[j][k] = (rand() % 75) + 1;
        }
    }

    // Play the game
    for (int i = 0; i < numPlayers; i++) {
        int *playerCards = bingoCards[i];
        int *playerDraw = bingoDraw[i];
        int *playerWins = (int *)malloc(numRows * sizeof(int));

        // Check if the player has a bingo
        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < numColumns; k++) {
                if (playerCards[j * numColumns + k] == playerDraw[j] && playerWins[j] == 0) {
                    printf("Player %d has a bingo!\n", i + 1);
                    playerWins[j] = 1;
                }
            }
        }

        // Free the memory
        free(playerCards);
        free(playerDraw);
        free(playerWins);
    }

    // Free the memory
    for (int i = 0; i < numBingoCards; i++) {
        free(bingoCards[i]);
    }
    free(bingoCards);
    for (int i = 0; i < numBalls; i++) {
        free(bingoDraw[i]);
    }
    free(bingoDraw);

    return 0;
}