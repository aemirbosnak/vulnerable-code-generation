//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // Number of sites

int **create_grid(); // Function to create the grid
void percolate(int **grid); // Function to simulate percolation
void print_grid(int **grid); // Function to print the grid

int main() {
    int **grid = create_grid(); // Create the grid
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < N; i++) { // Simulate percolation
        percolate(grid);
        print_grid(grid);
    }
    return 0;
}

int **create_grid() {
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0; // Initialize all sites as blocked
        }
    }
    return grid;
}

void percolate(int **grid) {
    int x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) { // If the site is blocked
                int count = 0; // Count the number of open neighbors
                if (i > 0 && grid[i-1][j] == 1) count++; // Check the top neighbor
                if (i < N-1 && grid[i+1][j] == 1) count++; // Check the bottom neighbor
                if (j > 0 && grid[i][j-1] == 1) count++; // Check the left neighbor
                if (j < N-1 && grid[i][j+1] == 1) count++; // Check the right neighbor
                if (count == 0) { // If the site has no open neighbors
                    grid[i][j] = 1; // Mark it as open
                }
            }
        }
    }
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                printf("X ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}