//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    printf("Sudoku Solution:\n");
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            printf("%d ", board[r][d]);
        }
        printf("\n");
    }
}

// Check if a number can be placed in the given position
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check the row and column
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Solve the Sudoku board using backtracking
bool solveSudoku(int board[N][N]) {
    int row, col;
    bool isEmpty = true;

    // Find an empty space
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // If there is no empty space, we are done
    if (isEmpty) {
        return true;
    }

    // Try digits 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check if it's safe
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursively try to fill the rest
            if (solveSudoku(board)) {
                return true;
            }

            // Backtrack
            board[row][col] = 0;
        }
    }
    return false;
}

// Read the board from input
void readBoard(int board[N][N]) {
    printf("Enter Sudoku puzzle (0 for empty cells):\n");
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            scanf("%d", &board[r][d]);
        }
    }
}

// Main function to run the program
int main() {
    int board[N][N];

    readBoard(board);

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}