//FormAI DATASET v1.0 Category: Sudoku solver ; Style: excited
#include <stdio.h>

int board[9][9];

// Function to print the sudoku grid
void printGrid(int arr[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given number can be placed at a particular position
int isSafe(int row, int col, int num) {
    // Check if the number is already present in the row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // Check if the number is already present in the column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // Check if the number is already present in the 3x3 sub-grid
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int row, int col) {
    // If we have reached the end of the puzzle, return 1
    if (row == 9 && col == 0) {
        return 1;
    }
    // If we have reached the end of the row, move to the next row
    if (col == 9) {
        row++;
        col = 0;
    }
    // If the cell is already filled, move to the next cell
    if (board[row][col] != 0) {
        return solveSudoku(row, col + 1);
    }
    // Fill the cell with a number and check if it is safe to do so
    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            board[row][col] = num;
            // Recursively solve the rest of the puzzle
            if (solveSudoku(row, col + 1)) {
                return 1;
            }
            // If we cannot solve the puzzle with this number, backtrack
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the amazing Sudoku solver program!\n");
    printf("To start, enter the initial configuration of the puzzle:\n");
    for (int i = 0; i < 9; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("\nSolving the puzzle...\n");
    if (solveSudoku(0, 0)) {
        printf("\nThe solution to the Sudoku puzzle is:\n");
        printGrid(board);
    } else {
        printf("\nSorry, the Sudoku puzzle cannot be solved with the given input.\n");
    }
    return 0;
}