//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

void initializeBoard(int board[SIZE][SIZE], int display[SIZE][SIZE]) {
    int numbers[SIZE * SIZE / 2];
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        numbers[i] = i + 1;
    }
    // Duplicate the numbers for pairs
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        numbers[SIZE * SIZE / 2 + i] = numbers[i];
    }

    // Shuffle the numbers
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the board and display array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[i * SIZE + j];
            display[i][j] = -1;  // Use -1 to indicate hidden
        }
    }
}

void displayBoard(int display[SIZE][SIZE]) {
    printf("\nBoard:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == -1) {
                printf("[X] ");
            } else {
                printf("[%d] ", display[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isMatch(int board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    return board[firstRow][firstCol] == board[secondRow][secondCol];
}

int hasWon(int display[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == -1) {
                return 0;  // If there's any hidden cell
            }
        }
    }
    return 1;  // All pairs matched
}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE];
    int display[SIZE][SIZE];
    initializeBoard(board, display);
    
    int firstRow, firstCol, secondRow, secondCol;
    int attempts = 0;

    printf("Welcome to the Peaceful Memory Game!\n");
    printf("Try to match the pairs to clear the board.\n");

    while (!hasWon(display)) {
        displayBoard(display);
        printf("Pick your first card (row col): ");
        scanf("%d %d", &firstRow, &firstCol);
        if (display[firstRow][firstCol] != -1) {
            printf("Please pick a hidden card!\n");
            continue;
        }

        display[firstRow][firstCol] = board[firstRow][firstCol];
        displayBoard(display);

        printf("Pick your second card (row col): ");
        scanf("%d %d", &secondRow, &secondCol);
        if (display[secondRow][secondCol] != -1) {
            printf("Please pick a hidden card!\n");
            display[firstRow][firstCol] = -1;  // Reset the first selection
            continue;
        }

        display[secondRow][secondCol] = board[secondRow][secondCol];
        displayBoard(display);

        attempts++;

        if (isMatch(board, firstRow, firstCol, secondRow, secondCol)) {
            printf("You found a match!\n");
        } else {
            printf("Not a match, try again.\n");
            display[firstRow][firstCol] = -1;  // Reset on mismatch
            display[secondRow][secondCol] = -1;  // Reset on mismatch
        }
    }
    
    printf("Congratulations! You've matched all pairs in %d attempts.\n", attempts);
    return 0;
}