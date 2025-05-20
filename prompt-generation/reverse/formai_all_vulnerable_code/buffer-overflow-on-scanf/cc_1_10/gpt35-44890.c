//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>

// A 9x9 array to store the sudoku puzzle
int sudoku[9][9];

// A function to check if a number fits in a specific cell of the puzzle
// The function takes row, column and number to check if it is valid in the given cell
int check(int row, int col, int num) {
    // Check for the same number in the same row or column
    for (int i = 0; i < 9; i++) {
        if ((sudoku[row][i] == num) || (sudoku[i][col] == num)) {
            return 0;
        }
    }
    // Check for the same number in the same 3x3 box
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    // If the number is not present in the row, column or 3x3 box, return 1
    return 1;
}

// A recursive function to solve the sudoku puzzle
int solve(int row, int col) {
    // If we reach the end of the puzzle, return 1
    if (row == 9) {
        return 1;
    }
    // If the current cell is already filled in, move to the next cell
    if (sudoku[row][col] != 0) {
        if (col == 8) {
            if (solve(row + 1, 0)) {
                return 1;
            }
        } else {
            if (solve(row, col + 1)) {
                return 1;
            }
        }
    } else {
        // Try to fill in the current cell with valid numbers
        for (int i = 1; i <= 9; i++) {
            if (check(row, col, i)) {
                sudoku[row][col] = i;
                // Move to the next cell
                if (col == 8) {
                    if (solve(row + 1, 0)) {
                        return 1;
                    }
                } else {
                    if (solve(row, col + 1)) {
                        return 1;
                    }
                }
                // If the solution is not found with the current number, backtrack and try with the next number
                sudoku[row][col] = 0;
            }
        }
    }
    // If no solution is found, return 0
    return 0;
}

// A function to print the solved sudoku puzzle
void print_sudoku() {
    printf("\nSolved Sudoku Puzzle:\n\n");
    printf("-------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}

int main() {
    printf("Enter the numbers in the Sudoku Puzzle:\n");
    // Read the input puzzle from the user
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    // Solve the puzzle
    if (solve(0, 0)) {
        // If the solution is found, print the solved puzzle
        print_sudoku();
    } else {
        printf("\nNo solution found.\n");
    }
    return 0;
}