//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

void printSudoku(int board[SIZE][SIZE]) {
    printf("Current Sudoku Board:\n");
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    // Check if 'num' is not in the given row
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check if 'num' is not in the given column
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not in the 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r + startRow][c + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[SIZE][SIZE]) {
    int row, col;
    bool empty = true;

    // Find an empty space in the board
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                empty = false;
                break;
            }
        }
        if (!empty) {
            break;
        }
    }

    // If there is no empty space left, we are done!
    if (empty) {
        return true;
    }

    // Try numbers 1 through 9 in the empty space
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursively try to fill in the rest of the board
            if (solveSudoku(board)) {
                return true;
            }

            // If it didn't work, backtrack!
            board[row][col] = 0;
        }
    }
    return false;
}

void initializeBoard(int board[SIZE][SIZE]) {
    printf("Enter Sudoku puzzle (0 for empty cells):\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            scanf("%d", &board[row][col]);
        }
    }
}

int main() {
    int board[SIZE][SIZE] = {0};

    // Initialize the board with user input
    initializeBoard(board);
    printSudoku(board);

    if (solveSudoku(board)) {
        printf("Sudoku solved successfully! The solution is:\n");
        printSudoku(board);
    } else {
        printf("Oh no! It looks like the Sudoku puzzle is unsolvable!\n");
    }

    return 0;
}