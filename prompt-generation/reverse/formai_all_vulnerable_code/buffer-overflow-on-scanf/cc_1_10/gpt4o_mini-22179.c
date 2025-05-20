//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void initializeGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0; // Initialize all cells to 0
        }
    }
}

void printGrid(int grid[SIZE][SIZE]) {
    printf("Current Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int grid[SIZE][SIZE], int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && grid[row][col] == 0;
}

void makeMove(int grid[SIZE][SIZE], int row, int col, int player) {
    grid[row][col] = player; // Set the cell to the current player's number
}

int checkWin(int grid[SIZE][SIZE], int player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player && grid[i][3] == player && grid[i][4] == player) ||
            (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player && grid[3][i] == player && grid[4][i] == player)) {
            return 1; // Win found
        }
    }
    
    // Check diagonals
    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player && grid[3][3] == player && grid[4][4] == player) ||
        (grid[0][4] == player && grid[1][3] == player && grid[2][2] == player && grid[3][1] == player && grid[4][0] == player)) {
        return 1; // Win found
    }
    
    return 0; // No win
}

int main() {
    int grid[SIZE][SIZE];
    int currentPlayer = 1;
    int moves = 0;
    int row, col;

    initializeGrid(grid);
    printf("Welcome to Number Flip!\n");
    printf("Players take turns to fill cells in the grid (5x5).\n");
    printf("The first player to fill a complete row, column, or diagonal wins!\n\n");

    while (moves < SIZE * SIZE) {
        printGrid(grid);
        printf("Player %d, enter your move (row and col, 0-4): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isValidMove(grid, row, col)) {
            makeMove(grid, row, col, currentPlayer);
            moves++;
            if (checkWin(grid, currentPlayer)) {
                printGrid(grid);
                printf("Player %d wins!\n", currentPlayer);
                return 0; // Exit the game on win
            }
            // Switch player
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    printGrid(grid);
    printf("It's a draw!\n");
    return 0;
}