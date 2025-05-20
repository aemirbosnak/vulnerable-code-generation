//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 9
#define MAX_VALUE 9
#define MAX_NODES (MAX_SIZE*MAX_SIZE)

// Function to solve sudoku using backtracking
void solveSudoku(int board[MAX_SIZE][MAX_SIZE], int row, int col) {
    if (row == MAX_SIZE) {
        row = 0;
        col++;
    }
    if (col == MAX_SIZE) {
        printf("\nSolution found!\n");
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    if (board[row][col]!= 0) {
        return;
    }
    for (int i = 1; i <= MAX_VALUE; i++) {
        if (isValid(board, row, col, i)) {
            board[row][col] = i;
            solveSudoku(board, row, col + 1);
        }
    }
}

// Function to check if a value is valid in a given position
int isValid(int board[MAX_SIZE][MAX_SIZE], int row, int col, int value) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }
    for (j = 0; j < MAX_SIZE; j++) {
        if (board[i][col] == value) {
            return 0;
        }
    }
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (i = boxRow; i < boxRow + 3; i++) {
        for (j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get user input for the sudoku board
void getInput(int board[MAX_SIZE][MAX_SIZE]) {
    printf("Enter the sudoku board:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

// Main function
int main() {
    int board[MAX_SIZE][MAX_SIZE];
    getInput(board);
    solveSudoku(board, 0, 0);
    return 0;
}