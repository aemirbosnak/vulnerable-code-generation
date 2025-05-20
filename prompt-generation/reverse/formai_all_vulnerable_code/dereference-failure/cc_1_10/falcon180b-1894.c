//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9
#define MAX_ATTEMPTS 10000
#define MAX_NUMBERS 9

// Function to generate a random number between 1 and MAX_SIZE
int rand_num() {
    return rand() % MAX_SIZE + 1;
}

// Function to check if a given number is valid in a given row and column
int is_valid(int **grid, int row, int col, int num) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve a given Sudoku puzzle
int solve_sudoku(int **grid) {
    int row, col;
    for (row = 0; row < MAX_SIZE; row++) {
        for (col = 0; col < MAX_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= MAX_NUMBERS; num++) {
                    if (is_valid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solve_sudoku(grid)) {
                            return 1;
                        } else {
                            grid[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

// Function to print a given Sudoku puzzle
void print_sudoku(int **grid) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL));

    int **grid = malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++) {
        grid[i] = malloc(MAX_SIZE * sizeof(int));
    }

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                grid[i][j] = rand_num();
            }
        }

        int solved = solve_sudoku(grid);

        if (solved) {
            printf("Solved Sudoku:\n");
            print_sudoku(grid);
            break;
        } else {
            printf("Unsolvable Sudoku after %d attempts.\n", attempts);
            attempts++;
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}