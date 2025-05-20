//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE) / 2

void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\n");
    printf("Cyberpunk Memory Game\n");
    printf("Use the coordinates (row and column) to open tiles.\n");
    printf(" e.g., '1 2' opens the tile at row 1 and column 2.\n");
    printf("Tiles marked with '?' are unrevealed.\n\n");
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" ? ");
            }
        }
        printf("\n");
    }
}

void initializeBoard(char board[SIZE][SIZE]) {
    char symbols[] = {'@', '#', '$', '%', '&', '*', '!', '^', '<', '>', '(', ')'};
    int index = 0;

    // Fill the board with pairs of symbols
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < TOTAL_PAIRS) {
                board[i][j] = symbols[index / 2];
            } else {
                board[i][j] = ' '; // Empty space
            }
            index++;
        }
    }
}

void shuffleBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int random_i = rand() % SIZE;
            int random_j = rand() % SIZE;

            // Swap
            char temp = board[i][j];
            board[i][j] = board[random_i][random_j];
            board[random_i][random_j] = temp;
        }
    }
}

int checkMatch(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return 1; // Match found
    }
    return 0; // No match
}

int main() {
    char board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0};
    int totalMatched = 0;
    int attempts = 0;
    
    srand(time(NULL));
    initializeBoard(board);
    shuffleBoard(board);

    while (totalMatched < TOTAL_PAIRS) {
        printBoard(board, revealed);
        int row1, col1, row2, col2;

        // Get first coordinate
        printf("Select first tile (row col): ");
        scanf("%d %d", &row1, &col1);
        row1--; col1--; // Adjust to 0 index

        revealed[row1][col1] = 1; // Reveal the first tile
        printBoard(board, revealed);

        // Get second coordinate
        printf("Select second tile (row col): ");
        scanf("%d %d", &row2, &col2);
        row2--; col2--; // Adjust to 0 index

        revealed[row2][col2] = 1; // Reveal the second tile
        printBoard(board, revealed);

        // Check for a match
        if (checkMatch(board, revealed, row1, col1, row2, col2)) {
            printf("Match found! You are one step closer to dominating the Neon City.\n");
            totalMatched++;
        } else {
            printf("No match. Try again...\n");
            sleep(2); // Pause before re-hiding tiles
            revealed[row1][col1] = 0; // Hide the first tile again
            revealed[row2][col2] = 0; // Hide the second tile again
        }

        attempts++; // Increment attempts
    }

    printf("Congratulations! You've mastered the memory of the Neon City in %d attempts.\n", attempts);
    return 0;
}