//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];

// checks if the value is already in the row
int checkRow(int row, int val) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == val) {
            return 0;
        }
    }
    return 1;
}

// checks if the value is already in the column
int checkColumn(int col, int val) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == val) {
            return 0;
        }
    }
    return 1;
}

// checks if the value is already in the 3 by 3 grid
int checkGrid(int row, int col, int val) {
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val) {
                return 0;
            }
        }
    }
    return 1;
}

// finds the next unassigned location
int findUnassignedLocation(int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// solves the sudoku puzzle
int solveSudoku() {
    int row, col;
    if (!findUnassignedLocation(&row, &col)) {
        return 1;
    }
    
    for (int val = 1; val <= SIZE; val++) {
        if (checkRow(row, val) && checkColumn(col, val) && checkGrid(row, col, val)) {
            board[row][col] = val;
            if (solveSudoku()) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    
    return 0;
}

// prints the solved sudoku puzzle
void printSudoku() {
    printf("Sudoku Puzzle Solution:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku puzzle (use '0' for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    if (solveSudoku()) {
        printSudoku();
    } else {
        printf("Cannot solve Sudoku puzzle.");
    }
    
    return 0;
}