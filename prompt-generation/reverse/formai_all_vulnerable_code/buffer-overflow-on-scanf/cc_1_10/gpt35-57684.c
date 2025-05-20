//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if cell (i, j) is valid or not
bool isValidCell(int i, int j, int N) {
    return (i >= 0 && i < N && j >= 0 && j < N);
}

// Function to check if there is a path from (i1, j1) to (i2, j2) in the grid
bool isPathExists(int** grid, int N, int i1, int j1, int i2, int j2, bool** visited) {
    // If cell (i1, j1) is not valid or it is blocked or it has already been visited
    if (!isValidCell(i1, j1, N) || grid[i1][j1] == 0 || visited[i1][j1]) {
        return false;
    }

    // If (i1, j1) is the same as (i2, j2) then we have found the path
    if (i1 == i2 && j1 == j2) {
        return true;
    }

    // Mark current cell as visited
    visited[i1][j1] = true;

    // Check if there exists a path from any of the 4 adjacent cells to (i2, j2)
    if (isPathExists(grid, N, i1 + 1, j1, i2, j2, visited) ||
        isPathExists(grid, N, i1, j1 + 1, i2, j2, visited) ||
        isPathExists(grid, N, i1 - 1, j1, i2, j2, visited) ||
        isPathExists(grid, N, i1, j1 - 1, i2, j2, visited)) {
        return true;
    }

    // If none of the adjacent cells have a path to (i2, j2), then backtrack
    visited[i1][j1] = false;

    return false;
}

// Function to simulate percolation in the grid
bool simulatePercolation(int** grid, int N) {
    // Initialize visited array to mark blocked cells
    bool** visited = (bool**)malloc(N * sizeof(bool*));
    for (int i = 0; i < N; i++) {
        visited[i] = (bool*)malloc(N * sizeof(bool));
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    // Check for connectivity between top and bottom row
    for (int j = 0; j < N; j++) {
        if (isPathExists(grid, N, 0, j, N-1, j, visited)) {
            // If path exists, percolation occurs
            for (int i = 0; i < N; i++) {
                free(visited[i]);
            }
            free(visited);
            return true;
        }
    }

    // If there is no path between top and bottom row, percolation does not occur
    for (int i = 0; i < N; i++) {
        free(visited[i]);
    }
    free(visited);
    return false;
}

int main() {
    // Set seed value for generating random numbers
    srand(time(0));

    int N;
    printf("Enter the size of the grid: ");
    scanf("%d", &N);

    // Allocate memory for 2D grid
    int** grid = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        grid[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            // Generate random numbers between 0 and 1
            double randNum = (double)rand() / RAND_MAX;
            if (randNum < 0.4) {
                // Block the cell with probability 0.4
                grid[i][j] = 0;
            }
            else {
                // Open the cell with probability 0.6
                grid[i][j] = 1;
            }
        }
    }

    // Print the initial state of the grid
    printf("Initial grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Simulate percolation
    bool percolates = simulatePercolation(grid, N);

    // Print the final state of the grid
    printf("Final grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    if (percolates) {
        printf("Percolation occurs\n");
    }
    else {
        printf("Percolation does not occur\n");
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}