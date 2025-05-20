//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
// Percolation Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid
typedef struct {
    int rows;
    int cols;
    int** grid;
} Grid;

// Function to create a new grid
Grid* createGrid(int rows, int cols) {
    Grid* grid = malloc(sizeof(Grid));
    grid->rows = rows;
    grid->cols = cols;
    grid->grid = malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows * cols; i++) {
        grid->grid[i] = 0;
    }
    return grid;
}

// Function to delete a grid
void deleteGrid(Grid* grid) {
    free(grid->grid);
    free(grid);
}

// Function to print a grid
void printGrid(Grid* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%d ", grid->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to simulate percolation
void simulatePercolation(Grid* grid, int iterations) {
    srand(time(NULL));
    for (int i = 0; i < iterations; i++) {
        int row = rand() % grid->rows;
        int col = rand() % grid->cols;
        if (grid->grid[row][col] == 0) {
            grid->grid[row][col] = 1;
        }
    }
}

// Function to check if the system percolates
int checkPercolation(Grid* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j] == 1 && (i == 0 || i == grid->rows - 1 || j == 0 || j == grid->cols - 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    Grid* grid = createGrid(10, 10);
    simulatePercolation(grid, 1000);
    printGrid(grid);
    if (checkPercolation(grid)) {
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }
    deleteGrid(grid);
    return 0;
}