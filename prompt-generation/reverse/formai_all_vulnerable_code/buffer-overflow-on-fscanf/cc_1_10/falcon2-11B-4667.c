//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9

// Define a 2D array to store the Sudoku grid
int sudoku[ROWS][COLS];

// Function to print the Sudoku grid
void print_sudoku(int sudoku[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid for a given position in the Sudoku grid
int is_valid(int pos[ROWS][COLS], int num, int row, int col) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (sudoku[i][j] == num && (i!= row || j!= col)) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle
int solve_sudoku(int sudoku[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (sudoku[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(sudoku, num, row, col)) {
                        sudoku[row][col] = num;
                        if (solve_sudoku(sudoku)) {
                            return 1;
                        }
                        // If the backtracking fails, put back the number to its original position
                        sudoku[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

// Main function
int main() {
    // Read the Sudoku grid from a file
    FILE *fp = fopen("sudoku.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the Sudoku grid and store it in a 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(fp, "%d", &sudoku[i][j]);
        }
    }
    fclose(fp);

    // Solve the Sudoku puzzle
    solve_sudoku(sudoku);

    // Print the solved Sudoku grid
    printf("\nSolved Sudoku Grid:\n");
    print_sudoku(sudoku);

    return 0;
}