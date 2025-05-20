//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMBERS 24

int main() {
    srand(time(NULL));
    int bingoCard[ROWS][COLS];
    int playerCard[ROWS][COLS];
    int calledNumbers[TOTAL_NUMBERS];
    int i, j, k, matchCount;

    // Generate random numbers for the bingo card
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            bingoCard[i][j] = rand() % 15 + 1;
        }
    }

    // Print the bingo card
    printf("Bingo Card:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", bingoCard[i][j]);
        }
        printf("\n");
    }

    // Get the player's numbers
    printf("\nEnter your numbers (1-15): ");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &playerCard[i][j]);
        }
    }

    // Simulate the game
    matchCount = 0;
    for (k = 0; k < TOTAL_NUMBERS; k++) {
        calledNumbers[k] = rand() % 15 + 1;
        printf("%d ", calledNumbers[k]);

        // Check for a match on the player's card
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (playerCard[i][j] == calledNumbers[k]) {
                    matchCount++;
                    printf("\nMatch found at (%d,%d)!\n", i, j);
                }
            }
        }

        // Check for a match on the bingo card
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingoCard[i][j] == calledNumbers[k]) {
                    printf("\nMatch found at (%d,%d)!\n", i, j);
                }
            }
        }
    }

    // Check for a bingo
    if (matchCount == TOTAL_NUMBERS) {
        printf("\nCongratulations! You won!\n");
    } else {
        printf("\nSorry, you didn't win this time.\n");
    }

    return 0;
}