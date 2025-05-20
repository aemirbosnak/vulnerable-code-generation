//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the grid with empty cells
void initialize(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to check if a cell is valid
int is_valid(int **grid, int n, int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a cell is empty
int is_empty(int **grid, int n, int i, int j) {
    if (grid[i][j] == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to simulate the percolation process
void percolate(int **grid, int n) {
    int count = 0;
    while (count < n * n) {
        int i, j;
        do {
            i = rand() % n;
            j = rand() % n;
        } while (!is_valid(grid, n, i, j));

        if (is_empty(grid, n, i, j)) {
            grid[i][j] = 1;
            count++;
        }
    }
}

// Function to print the grid
void print_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n = 10; // Size of the grid
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
    }

    initialize(grid, n);
    percolate(grid, n);
    print_grid(grid, n);

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}