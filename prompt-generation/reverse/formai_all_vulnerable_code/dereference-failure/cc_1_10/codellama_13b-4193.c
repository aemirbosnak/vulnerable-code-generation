//Code Llama-13B DATASET v1.0 Category: Sudoku solver ; Style: portable
// Sudoku solver program in a portable style

#include <stdio.h>

// Function to check if a given number is in the row, column or box
int check_unique(int num, int row, int col, int **sudoku) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return 0;
        }
        if (i < 3 && col < 3) {
            if (sudoku[row - row % 3 + i][col - col % 3 + i] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the solved Sudoku
void print_sudoku(int **sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to solve the Sudoku
void solve_sudoku(int **sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (check_unique(num, i, j, sudoku)) {
                        sudoku[i][j] = num;
                        solve_sudoku(sudoku);
                        sudoku[i][j] = 0;
                    }
                }
                return;
            }
        }
    }
    print_sudoku(sudoku);
}

int main() {
    // Initialize the Sudoku
    int sudoku[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Solve the Sudoku
    solve_sudoku(sudoku);

    return 0;
}