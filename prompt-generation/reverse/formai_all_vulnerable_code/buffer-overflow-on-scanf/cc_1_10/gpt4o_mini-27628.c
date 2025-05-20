//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9 // Size of the Sudoku board
#define UNASSIGNED 0 // A constant for unassigned cells

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            printf("%d ", board[row][col]);
        printf("\n");
    }
}

// Function to check if it is safe to place num in board[row][col]
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++)
        if (board[row][x] == num || board[x][col] == num) 
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to find an unassigned location in the board
bool findUnassignedLocation(int board[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++)
        for (*col = 0; *col < SIZE; (*col)++)
            if (board[*row][*col] == UNASSIGNED)
                return true;
    return false;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(int board[SIZE][SIZE]) {
    int row, col;

    if (!findUnassignedLocation(board, &row, &col))
        return true; // Puzzle solved

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            board[row][col] = UNASSIGNED; // Reset if it doesn't work
        }
    }
    return false; // Trigger backtracking
}

// Function to read the Sudoku board from user input
void readBoard(int board[SIZE][SIZE]) {
    printf("Enter the Sudoku board (use 0 for unassigned cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

int main() {
    int board[SIZE][SIZE];

    readBoard(board);
    
    printf("Input Sudoku Board:\n");
    printBoard(board);

    if (solveSudoku(board)) {
        printf("Solved Sudoku Board:\n");
        printBoard(board);
    } else {
        printf("No solution exists\n");
    }
    
    return 0;
}