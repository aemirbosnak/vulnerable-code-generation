//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

enum {
    EMPTY,
    RED,
    GREEN,
    BLUE,
    YELLOW,
};

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create a 2D array to represent the game board
    int board[NUM_ROWS][NUM_COLS];

    // Fill the game board with random colors
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = rand() % 5;
        }
    }

    // Print the game board
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf("  ");
                    break;
                case RED:
                    printf("\033[41m  \033[0m");
                    break;
                case GREEN:
                    printf("\033[42m  \033[0m");
                    break;
                case BLUE:
                    printf("\033[44m  \033[0m");
                    break;
                case YELLOW:
                    printf("\033[43m  \033[0m");
                    break;
            }
        }
        printf("\n");
    }

    // Get the player's move
    int row, col;
    printf("Enter the row and column of the cell you want to move (e.g. 1 2): ");
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS || board[row][col] == EMPTY) {
        printf("Invalid move. Please try again.\n");
        return 1;
    }

    // Make the move
    int temp = board[row][col];
    board[row][col] = board[row - 1][col];
    board[row - 1][col] = temp;

    // Print the updated game board
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf("  ");
                    break;
                case RED:
                    printf("\033[41m  \033[0m");
                    break;
                case GREEN:
                    printf("\033[42m  \033[0m");
                    break;
                case BLUE:
                    printf("\033[44m  \033[0m");
                    break;
                case YELLOW:
                    printf("\033[43m  \033[0m");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}