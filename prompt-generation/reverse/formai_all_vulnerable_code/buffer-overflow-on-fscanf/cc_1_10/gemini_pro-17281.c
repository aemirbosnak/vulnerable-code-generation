//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// Structure to represent a cell in the Sudoku grid
typedef struct {
    int value;
    int possibilities[SIZE];
} Cell;

// Structure to represent the Sudoku grid
typedef struct {
    Cell grid[SIZE][SIZE];
} Sudoku;

// Function to read the Sudoku grid from a file
int read_sudoku(Sudoku *sudoku, FILE *file) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(file, "%d", &sudoku->grid[i][j].value);
            if (sudoku->grid[i][j].value != 0) {
                // Set the possibilities of the cell to 0
                for (int k = 0; k < SIZE; k++) {
                    sudoku->grid[i][j].possibilities[k] = 0;
                }
                sudoku->grid[i][j].possibilities[sudoku->grid[i][j].value - 1] = 1;
            } else {
                // Set the possibilities of the cell to 1
                for (int k = 0; k < SIZE; k++) {
                    sudoku->grid[i][j].possibilities[k] = 1;
                }
            }
        }
    }
    return 0;
}

// Function to print the Sudoku grid to the console
void print_sudoku(Sudoku *sudoku) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku->grid[i][j].value);
        }
        printf("\n");
    }
}

// Function to check if the Sudoku grid is solved
int is_solved(Sudoku *sudoku) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (sudoku->grid[i][j].value == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to find the next empty cell in the Sudoku grid
int find_empty(Sudoku *sudoku, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (sudoku->grid[i][j].value == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a value is valid for a cell in the Sudoku grid
int is_valid(Sudoku *sudoku, int row, int col, int value) {
    // Check if the value is present in the row
    for (int i = 0; i < SIZE; i++) {
        if (sudoku->grid[row][i].value == value) {
            return 0;
        }
    }
    // Check if the value is present in the column
    for (int i = 0; i < SIZE; i++) {
        if (sudoku->grid[i][col].value == value) {
            return 0;
        }
    }
    // Check if the value is present in the 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (sudoku->grid[i][j].value == value) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku grid using backtracking
int solve_sudoku(Sudoku *sudoku) {
    int row, col;
    if (!find_empty(sudoku, &row, &col)) {
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        if (sudoku->grid[row][col].possibilities[i] == 1) {
            int value = i + 1;
            if (is_valid(sudoku, row, col, value)) {
                sudoku->grid[row][col].value = value;
                if (solve_sudoku(sudoku)) {
                    return 1;
                } else {
                    sudoku->grid[row][col].value = 0;
                }
            }
        }
    }
    return 0;
}

int main() {
    Sudoku sudoku;
    FILE *file = fopen("sudoku.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    read_sudoku(&sudoku, file);
    fclose(file);
    print_sudoku(&sudoku);
    if (solve_sudoku(&sudoku)) {
        printf("Solved Sudoku:\n");
        print_sudoku(&sudoku);
    } else {
        printf("Could not solve Sudoku\n");
    }
    return 0;
}