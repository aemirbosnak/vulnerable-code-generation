//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define GRID_SIZE 4
#define NUM_PAIRS (GRID_SIZE * GRID_SIZE) / 2

void initializeGame(char board[GRID_SIZE][GRID_SIZE], char letters[NUM_PAIRS]) {
    int i, j, k = 0;
    
    // Fill letters array with alphabet letters
    for (i = 0; i < NUM_PAIRS; i++) {
        letters[i] = 'A' + i; // Fill with A, B, C, ...
    }
    
    // Shuffle letters
    for (i = 0; i < NUM_PAIRS; i++) {
        int randomIndex = rand() % NUM_PAIRS;
        char temp = letters[i];
        letters[i] = letters[randomIndex];
        letters[randomIndex] = temp;
    }
    
    // Place letters on the board
    k = 0;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (k < NUM_PAIRS) {
                board[i][j] = letters[k / 2]; // Place letter in pairs
                k++;
            } else {
                board[i][j] = '*'; // Placeholder for unrevealed state
            }
        }
    }
}

void printBoard(char board[GRID_SIZE][GRID_SIZE], int revealed[GRID_SIZE][GRID_SIZE]) {
    printf("  ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int main() {
    char board[GRID_SIZE][GRID_SIZE];
    char letters[NUM_PAIRS];
    int revealed[GRID_SIZE][GRID_SIZE] = {0}; // Tracks revealed cards
    int attempts = 0;
    int matches = 0;

    srand(time(NULL)); // Seed for random number generation

    initializeGame(board, letters);
    
    while (matches < NUM_PAIRS) {
        printBoard(board, revealed);

        int x1, y1, x2, y2;

        // Player input for first card
        printf("Select first card (row col): ");
        scanf("%d %d", &x1, &y1);
        revealed[x1][y1] = 1;

        // Player input for second card
        printf("Select second card (row col): ");
        scanf("%d %d", &x2, &y2);
        revealed[x2][y2] = 1;

        // Display current selection
        printBoard(board, revealed);
        
        attempts++;

        // Check for match
        if (board[x1][y1] == board[x2][y2]) {
            printf("It's a match!\n");
            matches++;
        } else {
            printf("No match! Try again.\n");
            revealed[x1][y1] = 0; // Hide the card again
            revealed[x2][y2] = 0; // Hide the card again
        }
        
        printf("Attempts so far: %d\n", attempts);
    }

    printf("Congratulations! You've matched all pairs in %d attempts!\n", attempts);

    return 0;
}