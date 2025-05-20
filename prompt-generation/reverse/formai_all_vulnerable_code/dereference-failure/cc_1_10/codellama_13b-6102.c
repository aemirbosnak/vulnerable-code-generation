//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
/*
 * percolation_simulator.c
 *
 * A simple program to simulate percolation in a 2D grid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define P 0.5

// Struct to represent a 2D grid
typedef struct {
    int width;
    int height;
    int** grid;
} grid_t;

// Function to create a 2D grid
grid_t* create_grid(int width, int height) {
    grid_t* grid = malloc(sizeof(grid_t));
    grid->width = width;
    grid->height = height;
    grid->grid = malloc(sizeof(int*) * width);
    for (int i = 0; i < width; i++) {
        grid->grid[i] = malloc(sizeof(int) * height);
    }
    return grid;
}

// Function to free a 2D grid
void free_grid(grid_t* grid) {
    for (int i = 0; i < grid->width; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

// Function to initialize the grid with random values
void init_grid(grid_t* grid) {
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            grid->grid[i][j] = rand() % 2;
        }
    }
}

// Function to simulate percolation in the grid
int simulate_percolation(grid_t* grid) {
    int percolated = 0;
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            if (grid->grid[i][j] == 1) {
                if (i == 0 || i == grid->width - 1 || j == 0 || j == grid->height - 1) {
                    percolated = 1;
                } else {
                    if (grid->grid[i - 1][j] == 1 || grid->grid[i + 1][j] == 1 || grid->grid[i][j - 1] == 1 || grid->grid[i][j + 1] == 1) {
                        percolated = 1;
                    }
                }
            }
        }
    }
    return percolated;
}

int main() {
    // Create a 100x100 grid
    grid_t* grid = create_grid(100, 100);

    // Initialize the grid with random values
    init_grid(grid);

    // Simulate percolation
    int percolated = simulate_percolation(grid);

    // Print the result
    if (percolated == 1) {
        printf("Percolation occurred!\n");
    } else {
        printf("Percolation did not occur.\n");
    }

    // Free the grid
    free_grid(grid);

    return 0;
}