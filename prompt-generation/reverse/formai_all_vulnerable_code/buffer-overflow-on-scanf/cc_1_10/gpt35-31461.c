//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
// C Sudoku Solver
#include <stdio.h>

int board[9][9];

// Function to check if a number can be placed in a particular cell
int canPlace(int x, int y, int num) {
    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == num || board[i][y] == num) {
            return 0;
        }
    }

    // Check 3x3 sub-grid
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = startX; i < startX + 3; i++) {
        for (int j = startY; j < startY + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    // If number can be placed, return 1
    return 1;
}

// Function to solve Sudoku recursively
int solveSudoku(int x, int y) {
    if (y == 9) {
        x++;
        y = 0;
    }

    // If all cells are filled, return 1
    if (x == 9) {
        return 1;
    }

    // If current cell is filled, skip to next cell
    if (board[x][y] != 0) {
        return solveSudoku(x, y + 1);
    }

    // Try numbers from 1 to 9
    for (int i = 1; i <= 9; i++) {
        if (canPlace(x, y, i)) {
            board[x][y] = i;
            if (solveSudoku(x, y + 1)) {
                return 1;
            }
            board[x][y] = 0;
        }
    }

    // If no number can be placed, return 0
    return 0;
}

// Function to print the Sudoku board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Input Sudoku board
    printf("Enter the Sudoku board:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Solve Sudoku board
    if (solveSudoku(0, 0)) {
        // Print solved Sudoku board
        printf("\nSolved Sudoku board:\n");
        printBoard();
    } else {
        printf("\nNo solution exists.");
    }

    return 0;
}