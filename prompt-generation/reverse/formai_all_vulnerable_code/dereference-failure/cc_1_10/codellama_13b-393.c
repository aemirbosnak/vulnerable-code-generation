//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
/*
 * percolation_simulator.c
 *
 * A program to simulate percolation on a 2D grid.
 *
 * Usage: ./percolation_simulator <grid_size>
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GRID_SIZE 100

// Struct to represent a 2D grid
typedef struct {
    int nrows;
    int ncols;
    int grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
} Grid;

// Function to initialize a grid
void init_grid(Grid *grid, int nrows, int ncols) {
    grid->nrows = nrows;
    grid->ncols = ncols;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            grid->grid[i][j] = 0;
        }
    }
}

// Function to check if a site is open
int is_open(Grid *grid, int i, int j) {
    return grid->grid[i][j] == 1;
}

// Function to check if a site is blocked
int is_blocked(Grid *grid, int i, int j) {
    return grid->grid[i][j] == 0;
}

// Function to check if a site is percolated
int is_percolated(Grid *grid, int i, int j) {
    if (i == 0) {
        return is_open(grid, i, j);
    } else if (i == grid->nrows - 1) {
        return is_open(grid, i, j);
    } else {
        return is_open(grid, i, j) || is_percolated(grid, i + 1, j) || is_percolated(grid, i - 1, j);
    }
}

// Function to open a site
void open_site(Grid *grid, int i, int j) {
    grid->grid[i][j] = 1;
}

// Function to close a site
void close_site(Grid *grid, int i, int j) {
    grid->grid[i][j] = 0;
}

// Function to print the grid
void print_grid(Grid *grid) {
    for (int i = 0; i < grid->nrows; i++) {
        for (int j = 0; j < grid->ncols; j++) {
            printf("%c ", grid->grid[i][j] == 1 ? 'O' : ' ');
        }
        printf("\n");
    }
}

// Function to simulate percolation
void simulate(Grid *grid) {
    int nsites = grid->nrows * grid->ncols;
    int open_sites = 0;
    int closed_sites = 0;
    int percolated_sites = 0;
    int i, j;

    // Initialize the grid
    init_grid(grid, grid->nrows, grid->ncols);

    // Open sites randomly
    while (open_sites < nsites / 2) {
        i = rand() % grid->nrows;
        j = rand() % grid->ncols;
        if (is_blocked(grid, i, j)) {
            open_site(grid, i, j);
            open_sites++;
        }
    }

    // Close sites randomly
    while (closed_sites < nsites / 2) {
        i = rand() % grid->nrows;
        j = rand() % grid->ncols;
        if (is_open(grid, i, j)) {
            close_site(grid, i, j);
            closed_sites++;
        }
    }

    // Check if the system percolates
    for (i = 0; i < grid->nrows; i++) {
        for (j = 0; j < grid->ncols; j++) {
            if (is_percolated(grid, i, j)) {
                percolated_sites++;
            }
        }
    }

    // Print the results
    printf("Number of open sites: %d\n", open_sites);
    printf("Number of closed sites: %d\n", closed_sites);
    printf("Number of percolated sites: %d\n", percolated_sites);
    printf("Percentage of percolated sites: %f\n", (double)percolated_sites / (double)(open_sites + closed_sites));
}

int main(int argc, char *argv[]) {
    Grid grid;
    grid.nrows = atoi(argv[1]);
    grid.ncols = grid.nrows;
    simulate(&grid);
    return 0;
}