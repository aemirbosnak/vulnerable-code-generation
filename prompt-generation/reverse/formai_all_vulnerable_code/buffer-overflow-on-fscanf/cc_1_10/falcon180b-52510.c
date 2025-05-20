//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// Function to check if a number is valid in a given row, column, and block
int isValid(int board[SIZE][SIZE], int num, int row, int col) {
    int i, j;
    // Check row
    for (i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // Check column
    for (i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // Check block
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (i = startRow; i < startRow + 3; i++) {
        for (j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
void solveSudoku(int board[SIZE][SIZE]) {
    int i, j;
    // Find an empty cell
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                break;
            }
        }
        if (j == SIZE) {
            j = 0;
            i++;
        }
    }
    // Fill in the empty cell with a valid number
    int num = 1;
    while (!isValid(board, num, i, j)) {
        num++;
    }
    board[i][j] = num;
    // Check if the puzzle is solved
    int solved = 1;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                solved = 0;
                break;
            }
        }
        if (!solved) {
            break;
        }
    }
    if (solved) {
        printf("Sudoku puzzle solved:\n");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        // Backtrack and try another number
        board[i][j] = 0;
        solveSudoku(board);
    }
}

// Main function to read the Sudoku puzzle from a file and solve it
int main() {
    FILE *fp;
    int board[SIZE][SIZE];
    fp = fopen("sudoku.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            fscanf(fp, "%d", &board[i][j]);
        }
    }
    fclose(fp);
    solveSudoku(board);
    return 0;
}