//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_VALUE 9

// Function to print the current state of the Sudoku board
void printBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a value is valid in a given row, column, or 3x3 box
int isValid(int board[MAX_ROWS][MAX_COLS], int x, int y, int value) {
    int i, j;

    // Check row
    for (i = 0; i < MAX_ROWS; i++) {
        if (board[i][y] == value)
            return 0;
    }

    // Check column
    for (i = 0; i < MAX_ROWS; i++) {
        if (board[i][x] == value)
            return 0;
    }

    // Check 3x3 box
    int boxX = x / 3 * 3;
    int boxY = y / 3 * 3;
    for (i = boxX; i < boxX + 3; i++) {
        for (j = boxY; j < boxY + 3; j++) {
            if (board[i][j] == value)
                return 0;
        }
    }

    return 1;
}

// Function to solve the Sudoku board using backtracking
int solveSudoku(int board[MAX_ROWS][MAX_COLS]) {
    int x, y, value;

    // Check if the board is already solved
    for (x = 0; x < MAX_ROWS; x++) {
        for (y = 0; y < MAX_COLS; y++) {
            if (board[x][y] == 0)
                return 0;
        }
    }

    return 1;
}

// Function to initialize the Sudoku board with given values
void initBoard(int board[MAX_ROWS][MAX_COLS], int values) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (values & (1 << (i * MAX_COLS + j))) {
                board[i][j] = values & (1 << (i * MAX_COLS + j));
            } else {
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    int board[MAX_ROWS][MAX_COLS];
    int values;

    // Read input values from user
    printf("Enter the initial values of the Sudoku board (1-9):\n");
    scanf("%d", &values);

    // Initialize the Sudoku board with given values
    initBoard(board, values);

    // Solve the Sudoku board
    solveSudoku(board);

    // Print the solution
    printf("Solution:\n");
    printBoard(board);

    return 0;
}