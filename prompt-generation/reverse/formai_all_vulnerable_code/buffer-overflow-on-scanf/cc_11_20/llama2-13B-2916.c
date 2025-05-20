//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SQUARE_SIZE 5

int main() {
    // Initialize game board
    int board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Set starting position
    int x = 5;
    int y = 5;

    // Set game over flag
    int gameOver = 0;

    // Main game loop
    while (!gameOver) {
        // Print game board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Get user input
        printf("Enter move (row, col): ");
        int row, col;
        scanf("%d%d", &row, &col);

        // Check if user input is valid
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Update game board
        board[row][col] = x;
        x = (x + 1) % SQUARE_SIZE;

        // Check for game over
        if (board[row][col] == 0) {
            gameOver = 1;
        }
    }

    // Print final game board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}