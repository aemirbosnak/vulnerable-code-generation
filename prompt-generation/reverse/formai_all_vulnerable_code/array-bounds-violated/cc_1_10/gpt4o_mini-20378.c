//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4
#define TOTAL_CARDS (SIZE * SIZE)
#define MAX_TRIES 20

void initializeBoard(int board[SIZE][SIZE]) {
    int numbers[SIZE * SIZE / 2];
    for (int i = 0; i < (SIZE * SIZE / 2); i++) {
        numbers[i] = i + 1;
        numbers[i + (SIZE * SIZE / 2)] = i + 1; // creating pairs
    }

    // Shuffle the cards
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Initialize the board with shuffled cards
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[i * SIZE + j];
        }
    }
}

void printBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nMemory Card Game Board:\n");
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("[%d] ", board[i][j]);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int checkMatch(int board[SIZE][SIZE], int revealed[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    return board[firstRow][firstCol] == board[secondRow][secondCol];
}

int main() {
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // 0 = hidden, 1 = revealed
    int pairsFound = 0;
    int tries = 0;
    
    srand(time(0));
    initializeBoard(board);

    printf("Welcome to the Memory Game!\n");
    while (pairsFound < TOTAL_CARDS / 2 && tries < MAX_TRIES) {
        printBoard(board, revealed);
        int firstRow, firstCol, secondRow, secondCol;

        // First card selection
        printf("Select the first card (row and column): ");
        scanf("%d %d", &firstRow, &firstCol);
        revealed[firstRow][firstCol] = 1;
        printBoard(board, revealed);
        printf("You selected: %d\n", board[firstRow][firstCol]);

        // Second card selection
        printf("Select the second card (row and column): ");
        scanf("%d %d", &secondRow, &secondCol);
        revealed[secondRow][secondCol] = 1;
        printBoard(board, revealed);
        printf("You selected: %d\n", board[secondRow][secondCol]);

        // Check for match
        if (checkMatch(board, revealed, firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again!\n");
            revealed[firstRow][firstCol] = 0;
            revealed[secondRow][secondCol] = 0;
        }
        tries++;
    }

    if (pairsFound == TOTAL_CARDS / 2) {
        printf("You found all pairs! You win!\n");
    } else {
        printf("Out of tries! Game over!\n");
    }

    return 0;
}