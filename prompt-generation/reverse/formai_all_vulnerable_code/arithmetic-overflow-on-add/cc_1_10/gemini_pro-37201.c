//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Grid size
#define N 10

// Probability of a cell being open
#define P 0.5

// Data structure to represent a grid
typedef struct {
    int cells[N][N];
    int open_count;
} grid;

// Function to initialize a grid
void init_grid(grid *g) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g->cells[i][j] = (rand() < P * RAND_MAX);
            if (g->cells[i][j]) {
                g->open_count++;
            }
        }
    }
}

// Function to print a grid
void print_grid(grid *g) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", g->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is open
int is_open(grid *g, int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        return 0;
    }
    return g->cells[i][j];
}

// Function to perform a depth-first search of a grid
int dfs(grid *g, int i, int j) {
    if (!is_open(g, i, j)) {
        return 0;
    }

    // Mark the cell as visited
    g->cells[i][j] = -1;

    // Recursively visit the neighboring cells
    int count = 1;
    count += dfs(g, i - 1, j);
    count += dfs(g, i + 1, j);
    count += dfs(g, i, j - 1);
    count += dfs(g, i, j + 1);

    return count;
}

// Function to check if a grid percolates
int percolates(grid *g) {
    // Check if any of the cells in the top row are open
    for (int i = 0; i < N; i++) {
        if (is_open(g, 0, i)) {
            // Perform a depth-first search starting from the open cell
            int count = dfs(g, 0, i);
            if (count >= N) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    // Initialize a grid
    grid g;
    init_grid(&g);

    // Print the grid
    printf("Initial grid:\n");
    print_grid(&g);

    // Check if the grid percolates
    int result = percolates(&g);

    // Print the result
    if (result) {
        printf("The grid percolates.\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}