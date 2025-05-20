//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

#define SIZE 9 // Size of the Sudoku board

// Function declarations
void printBoard(int board[SIZE][SIZE]);
int isSafe(int board[SIZE][SIZE], int row, int col, int num);
int solveSudoku(int board[SIZE][SIZE]);
int findEmptyLocation(int board[SIZE][SIZE], int *row, int *col);

// Main program
int main() {
    int board[SIZE][SIZE];
    
    // Input the Sudoku board from the user
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    printf("Original Sudoku Board:\n");
    printBoard(board);

    // Solve the Sudoku and print the solution
    if (solveSudoku(board)) {
        printf("\nSolved Sudoku Board:\n");
        printBoard(board);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a given position
int isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) {
            return 0; // Not safe if the number exists in the row
        }
    }

    // Check the column
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) {
            return 0; // Not safe if the number exists in the column
        }
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return 0; // Not safe if the number exists in the sub-grid
            }
        }
    }

    return 1; // Safe to place the number
}

// Function to solve the Sudoku board
int solveSudoku(int board[SIZE][SIZE]) {
    int row, col;

    // If there is no empty space left, we are done
    if (!findEmptyLocation(board, &row, &col)) {
        return 1; // Solved
    }

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num; // Place the number

            // Recursively try to solve the rest of the board
            if (solveSudoku(board)) {
                return 1; // Solution found
            }

            // If placing num doesn't lead to a solution, reset the cell
            board[row][col] = 0;
        }
    }

    return 0; // Trigger backtracking
}

// Function to find an empty location in the board
int findEmptyLocation(int board[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1; // Empty location found
            }
        }
    }
    return 0; // No empty location found
}