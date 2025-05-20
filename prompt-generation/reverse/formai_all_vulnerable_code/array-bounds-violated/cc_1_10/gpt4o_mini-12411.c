//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // 4x4 grid
#define NUM_PAIRS (SIZE * SIZE) / 2

void initializeBoard(int board[SIZE][SIZE], int visible[SIZE][SIZE]) {
    // Fill the board with pairs of cards (1 to NUM_PAIRS)
    int numbers[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        numbers[i] = i + 1;
    }
    
    // Duplicate the numbers for pairs
    for (int i = 0; i < NUM_PAIRS; i++) {
        numbers[i + NUM_PAIRS] = numbers[i];
    }
    
    // Shuffle the pairs
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the board with shuffled pairs
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[i * SIZE + j];
            visible[i][j] = 0; // Initially, all cards are hidden
        }
    }
}

void displayBoard(int board[SIZE][SIZE], int visible[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (visible[i][j]) {
                printf("[%d]\t", board[i][j]);
            } else {
                printf("[*]\t");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    int board[SIZE][SIZE];
    int visible[SIZE][SIZE];
    initializeBoard(board, visible);

    int matchesFound = 0;
    int moves = 0;

    while (matchesFound < NUM_PAIRS) {
        displayBoard(board, visible);

        int firstRow, firstCol, secondRow, secondCol;

        // First card selection
        printf("Select the first card (row col): ");
        scanf("%d %d", &firstRow, &firstCol);
        
        if (visible[firstRow][firstCol] || firstRow < 0 || firstRow >= SIZE || firstCol < 0 || firstCol >= SIZE) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        visible[firstRow][firstCol] = 1; // Reveal the first card
        displayBoard(board, visible);

        // Second card selection
        printf("Select the second card (row col): ");
        scanf("%d %d", &secondRow, &secondCol);
        
        if (visible[secondRow][secondCol] || secondRow < 0 || secondRow >= SIZE || secondCol < 0 || secondCol >= SIZE) {
            printf("Invalid selection. Try again.\n");
            visible[firstRow][firstCol] = 0; // Hide the first card again
            continue;
        }

        visible[secondRow][secondCol] = 1; // Reveal the second card
        displayBoard(board, visible);

        // Check for match
        if (board[firstRow][firstCol] == board[secondRow][secondCol]) {
            printf("It's a match! %d found!\n", board[firstRow][firstCol]);
            matchesFound++;
        } else {
            printf("Not a match. Try again.\n");
            // Delay a second for the user to see the cards
            sleep(1);
            visible[firstRow][firstCol] = 0; // Hide the first card
            visible[secondRow][secondCol] = 0; // Hide the second card
        }

        moves++;
    }

    printf("Congratulations! You've found all pairs in %d moves!\n", moves);
    return 0;
}