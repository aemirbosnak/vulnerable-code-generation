//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_PAIRS (GRID_SIZE * GRID_SIZE / 2)

void initializeBoard(int board[GRID_SIZE][GRID_SIZE]) {
    int numbers[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        numbers[i] = i + 1;
        numbers[i + NUM_PAIRS] = i + 1;  // Create pairs
    }

    // Shuffle the numbers
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the board
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            board[i][j] = numbers[i * GRID_SIZE + j];
        }
    }
}

void displayBoard(int board[GRID_SIZE][GRID_SIZE], int revealed[GRID_SIZE][GRID_SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int board[GRID_SIZE][GRID_SIZE];
    int revealed[GRID_SIZE][GRID_SIZE] = {0};

    initializeBoard(board);
    int pairsFound = 0;

    while (pairsFound < NUM_PAIRS) {
        displayBoard(board, revealed);
        printf("Select first card (row and column): ");
        int firstRow, firstCol;
        scanf("%d %d", &firstRow, &firstCol);

        if (revealed[firstRow][firstCol]) {
            printf("This card is already revealed. Try again.\n");
            continue;
        }

        revealed[firstRow][firstCol] = 1;
        displayBoard(board, revealed);

        printf("Select second card (row and column): ");
        int secondRow, secondCol;
        scanf("%d %d", &secondRow, &secondCol);

        if (revealed[secondRow][secondCol]) {
            printf("This card is already revealed. Try again.\n");
            revealed[firstRow][firstCol] = 0; // Hide the first card again
            continue;
        }

        revealed[secondRow][secondCol] = 1;
        displayBoard(board, revealed);

        if (board[firstRow][firstCol] == board[secondRow][secondCol]) {
            printf("You found a pair!\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            sleep(2);
            revealed[firstRow][firstCol] = 0; // Hide the first card again
            revealed[secondRow][secondCol] = 0; // Hide the second card again
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}