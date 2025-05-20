//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4  // Grid size (4x4 grid)
#define TOTAL_PAIRS (SIZE * SIZE) / 2

void initializeBoard(char board[SIZE][SIZE], char symbols[TOTAL_PAIRS]) {
    // Fill the board with pairs of symbols
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < TOTAL_PAIRS) {
                board[i][j] = symbols[index];
                board[j][i] = symbols[index];
                index++;
            }
        }
    }

    // Shuffle the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int rand_i = rand() % SIZE;
            int rand_j = rand() % SIZE;

            char temp = board[i][j];
            board[i][j] = board[rand_i][rand_j];
            board[rand_i][rand_j] = temp;
        }
    }
}

void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" * "); 
            }
        }
        printf("\n");
    }
}

bool checkMatch(char board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    return board[firstRow][firstCol] == board[secondRow][secondCol];
}

int main() {
    srand(time(NULL));
    
    char symbols[TOTAL_PAIRS] = {'!', '@', '#', '$', '%', '^', '&', '*'};
    char board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};
    
    initializeBoard(board, symbols);

    int attempts = 0;
    int matches = 0;

    while (matches < TOTAL_PAIRS) {
        printBoard(board, revealed);
        
        int firstRow, firstCol, secondRow, secondCol;

        printf("Enter first card (row and column) to flip (0-3 space 0-3): ");
        scanf("%d %d", &firstRow, &firstCol);
        
        if (revealed[firstRow][firstCol]) {
            printf("Card already revealed! Try again.\n");
            continue;
        }
        
        revealed[firstRow][firstCol] = true;
        printBoard(board, revealed);
        
        printf("Enter second card (row and column) to flip (0-3 space 0-3): ");
        scanf("%d %d", &secondRow, &secondCol);
        
        if (revealed[secondRow][secondCol]) {
            printf("Card already revealed! Try again.\n");
            revealed[firstRow][firstCol] = false; // Un-reveal first card
            continue;
        }

        attempts++;

        revealed[secondRow][secondCol] = true;
        printBoard(board, revealed);

        if (checkMatch(board, firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n");
            matches++;
        } else {
            printf("Not a match, try again.\n");
            revealed[firstRow][firstCol] = false; // Un-reveal first card
            revealed[secondRow][secondCol] = false; // Un-reveal second card
        }
    }

    printf("Congratulations! You've matched all pairs in %d attempts!\n", attempts);
    
    return 0;
}