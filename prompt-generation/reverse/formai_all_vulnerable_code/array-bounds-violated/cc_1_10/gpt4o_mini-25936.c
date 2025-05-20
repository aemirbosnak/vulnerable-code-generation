//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2

void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE], int pairs[NUM_PAIRS]) {
    int index = 0;
    for (int i = 0; i < NUM_PAIRS; i++) {
        pairs[i] = i + 1; // Assign values from 1 to NUM_PAIRS
    }
    
    // Shuffle pairs into the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (index < NUM_PAIRS) {
                board[i][j] = pairs[index % NUM_PAIRS];
                index++;
            } else {
                board[i][j] = -1; // Unassigned space
            }
        }
    }
}

void shuffleBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int rand_i = rand() % BOARD_SIZE;
            int rand_j = rand() % BOARD_SIZE;

            // Swap the values
            int temp = board[i][j];
            board[i][j] = board[rand_i][rand_j];
            board[rand_i][rand_j] = temp;
        }
    }
}

void displayBoard(int board[BOARD_SIZE][BOARD_SIZE], bool revealed[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

bool checkForMatch(int firstChoice, int secondChoice) {
    return firstChoice == secondChoice;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int board[BOARD_SIZE][BOARD_SIZE];
    bool revealed[BOARD_SIZE][BOARD_SIZE] = {false};
    int pairs[NUM_PAIRS];
    int firstRow, firstCol, secondRow, secondCol;

    initializeBoard(board, pairs);
    shuffleBoard(board);

    int matchesFound = 0;
    int totalPairs = NUM_PAIRS;

    while (matchesFound < totalPairs) {
        displayBoard(board, revealed);

        printf("Select first card (row and column): ");
        scanf("%d %d", &firstRow, &firstCol);
        firstRow--; firstCol--; // Adjust for 0-indexing

        revealed[firstRow][firstCol] = true;
        displayBoard(board, revealed);

        printf("Select second card (row and column): ");
        scanf("%d %d", &secondRow, &secondCol);
        secondRow--; secondCol--; // Adjust for 0-indexing

        revealed[secondRow][secondCol] = true;
        displayBoard(board, revealed);

        if (checkForMatch(board[firstRow][firstCol], board[secondRow][secondCol])) {
            printf("It's a match! Card %d and Card %d\n", board[firstRow][firstCol], board[secondRow][secondCol]);
            matchesFound++;
        } else {
            printf("Not a match. Try again!\n");
            revealed[firstRow][firstCol] = false;
            revealed[secondRow][secondCol] = false;
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}