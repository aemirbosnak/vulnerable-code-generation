//Code Llama-13B DATASET v1.0 Category: Sudoku solver ; Style: real-life
// Sudoku Solver in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the size of the Sudoku grid
#define N 9

// Define the structure for a Sudoku grid
typedef struct {
    int grid[N][N];
} Sudoku;

// Define the structure for a Sudoku solution
typedef struct {
    int solution[N][N];
} SudokuSolution;

// Function to print a Sudoku grid
void print_sudoku(Sudoku *s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", s->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to print a Sudoku solution
void print_solution(SudokuSolution *s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", s->solution[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a Sudoku grid is valid
bool is_valid(Sudoku *s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s->grid[i][j] < 1 || s->grid[i][j] > 9) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a Sudoku grid has a unique solution
bool has_unique_solution(Sudoku *s) {
    // Initialize a solution grid
    SudokuSolution solution;

    // Initialize a temporary grid for the backtracking algorithm
    Sudoku temp;

    // Initialize a boolean to keep track of whether the solution is unique
    bool unique = true;

    // Initialize a boolean to keep track of whether the solution is complete
    bool complete = false;

    // Initialize a boolean to keep track of whether the solution is valid
    bool valid = true;

    // Loop through the rows of the grid
    for (int i = 0; i < N && valid; i++) {
        // Loop through the columns of the grid
        for (int j = 0; j < N && valid; j++) {
            // If the cell is empty, backtrack to find a solution
            if (s->grid[i][j] == 0) {
                // Initialize the temporary grid
                for (int k = 0; k < N; k++) {
                    for (int l = 0; l < N; l++) {
                        temp.grid[k][l] = s->grid[k][l];
                    }
                }

                // Set the cell to 1
                temp.grid[i][j] = 1;

                // Check if the temporary grid is valid
                if (is_valid(&temp)) {
                    // If the temporary grid is valid, check if it has a unique solution
                    if (has_unique_solution(&temp)) {
                        // If the temporary grid has a unique solution, set the solution grid to the temporary grid
                        for (int k = 0; k < N; k++) {
                            for (int l = 0; l < N; l++) {
                                solution.solution[k][l] = temp.grid[k][l];
                            }
                        }
                    } else {
                        // If the temporary grid does not have a unique solution, set the cell to 0 and backtrack
                        temp.grid[i][j] = 0;
                        valid = false;
                    }
                } else {
                    // If the temporary grid is not valid, set the cell to 0 and backtrack
                    temp.grid[i][j] = 0;
                    valid = false;
                }
            }
        }
    }

    // If the solution grid is not valid, return false
    if (!valid) {
        return false;
    }

    // If the solution grid is valid, check if it is complete
    complete = true;
    for (int i = 0; i < N && complete; i++) {
        for (int j = 0; j < N && complete; j++) {
            if (solution.solution[i][j] == 0) {
                complete = false;
            }
        }
    }

    // If the solution grid is complete, return true
    if (complete) {
        return true;
    }

    // If the solution grid is not complete, return false
    return false;
}

int main() {
    // Initialize a Sudoku grid
    Sudoku s;

    // Initialize a Sudoku solution
    SudokuSolution solution;

    // Read in the Sudoku grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &s.grid[i][j]);
        }
    }

    // Check if the Sudoku grid is valid
    if (is_valid(&s)) {
        // If the Sudoku grid is valid, check if it has a unique solution
        if (has_unique_solution(&s)) {
            // If the Sudoku grid has a unique solution, print it
            print_solution(&solution);
        } else {
            // If the Sudoku grid does not have a unique solution, print an error message
            printf("Error: The Sudoku grid does not have a unique solution.\n");
        }
    } else {
        // If the Sudoku grid is not valid, print an error message
        printf("Error: The Sudoku grid is not valid.\n");
    }

    return 0;
}