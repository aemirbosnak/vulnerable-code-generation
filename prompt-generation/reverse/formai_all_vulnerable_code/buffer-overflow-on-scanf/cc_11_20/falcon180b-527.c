//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define NUM_CARDS 24

int main() {
    int bingoCard[ROWS][COLS];
    int userCard[ROWS][COLS];
    int calledNumbers[NUM_CARDS];
    int numCalled = 0;
    int userWins = 0;
    int i, j, k;
    char choice;

    srand(time(NULL));

    // Initialize bingo card with random numbers
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            bingoCard[i][j] = rand() % 75 + 1;
        }
    }

    // Print bingo card
    printf("Bingo Card:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", bingoCard[i][j]);
        }
        printf("\n");
    }

    // User inputs their card numbers
    printf("\nEnter your card numbers:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &userCard[i][j]);
        }
    }

    // Start game loop
    while (1) {
        // Call a number
        calledNumbers[numCalled] = rand() % 75 + 1;
        numCalled++;

        printf("\n%d has been called!\n", calledNumbers[numCalled-1]);

        // Check for bingo
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingoCard[i][j] == calledNumbers[numCalled-1]) {
                    userCard[i][j] = -1;
                }
            }
        }

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (userCard[i][j] == -1) {
                    userWins = 1;
                    break;
                }
            }
            if (userWins) {
                break;
            }
        }

        // Check for end of game
        if (numCalled == NUM_CARDS || userWins) {
            break;
        }
    }

    // Print results
    if (userWins) {
        printf("\nCongratulations! You win!\n");
    } else {
        printf("\nSorry, you lost.\n");
    }

    return 0;
}