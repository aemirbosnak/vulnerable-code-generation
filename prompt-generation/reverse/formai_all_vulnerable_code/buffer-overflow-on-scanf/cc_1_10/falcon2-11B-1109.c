//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the grid with random numbers
void initGrid(int grid[10][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to simulate the percolation process
void percolate(int grid[10][10], int size) {
    int occupiedCells = 0;
    int iteration = 0;

    while (occupiedCells < size * size / 4) {
        iteration++;

        // Iterate over all cells in the grid
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;

                // Count the number of neighboring occupied cells
                if (i > 0 && grid[i - 1][j] == 1) {
                    neighbors++;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    neighbors++;
                }
                if (i < size - 1 && grid[i + 1][j] == 1) {
                    neighbors++;
                }
                if (j < size - 1 && grid[i][j + 1] == 1) {
                    neighbors++;
                }

                // If a cell is occupied and has at least two neighboring occupied cells, flip its value
                if (grid[i][j] == 1 && neighbors >= 2) {
                    grid[i][j] = 0;
                    occupiedCells++;
                }
            }
        }
    }
}

// Function to print the final state of the grid
void printGrid(int grid[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    // Prompt user for grid dimensions
    int size;
    printf("Enter grid size (between 1 and 100): ");
    scanf("%d", &size);
    if (size < 1 || size > 100) {
        printf("Invalid size\n");
        return 1;
    }

    // Allocate memory for the grid
    int grid[10][10];

    // Initialize the grid with random numbers
    initGrid(grid, size);

    // Simulate the percolation process
    percolate(grid, size);

    // Print the final state of the grid
    printGrid(grid);

    return 0;
}