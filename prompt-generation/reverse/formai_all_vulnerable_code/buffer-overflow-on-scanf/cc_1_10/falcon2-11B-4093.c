//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the Sudoku board
void printBoard(int board[9][9]) {
    printf("-------------\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
            if (j == 3 || j == 6)
                printf("| ");
            else
                printf(" ");
        }
        printf("\n-------------\n");
    }
}

// Function to solve the Sudoku board
void solveSudoku(int board[9][9]) {
    // Check for an empty cell
    int row, col, value;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                break;
            }
        }
        if (row == 9)
            break;
    }
    if (row == 9) {
        printf("Sudoku solved!\n");
        return;
    }

    // Get the next available value
    for (value = 1; value <= 9; value++) {
        if (isValid(board, row, col, value)) {
            break;
        }
    }

    // Assign the value to the cell
    board[row][col] = value;

    // Recursively solve the rest of the board
    solveSudoku(board);
}

// Function to check if a value is valid in a cell
int isValid(int board[9][9], int row, int col, int value) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == value)
            return 0;
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == value)
            return 0;
    }

    // Check sub-grid
    int subGridStartRow = (row / 3) * 3;
    int subGridStartCol = (col / 3) * 3;
    for (int i = subGridStartRow; i < subGridStartRow + 3; i++) {
        for (int j = subGridStartCol; j < subGridStartCol + 3; j++) {
            if (board[i][j] == value)
                return 0;
        }
    }

    return 1;
}

int main() {
    int board[9][9];
    char input[1000];
    int row, col;

    printf("Enter the initial Sudoku board:\n");
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            scanf("%d", &board[row][col]);
        }
    }

    printf("Enter the cell to solve:\n");
    scanf("%d %d", &row, &col);

    solveSudoku(board);

    printf("\nFinal Sudoku board:\n");
    printBoard(board);

    return 0;
}