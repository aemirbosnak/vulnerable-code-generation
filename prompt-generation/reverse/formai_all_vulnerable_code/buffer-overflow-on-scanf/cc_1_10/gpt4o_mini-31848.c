//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define L 20 // Lattice size (L x L)
#define OPEN 1
#define BLOCKED 0

int grid[L][L]; // Grid to represent the lattice
int visited[L][L]; // To track visited sites during DFS

// Function to initialize the grid with blocked sites
void initializeGrid(float p) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            grid[i][j] = (rand() / (RAND_MAX + 1.0)) < p ? OPEN : BLOCKED;
        }
    }
}

// Function to print the grid (for visualization)
void printGrid() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Depth-first search (DFS) to check for percolation
bool dfs(int x, int y) {
    if (x < 0 || x >= L || y < 0 || y >= L || visited[x][y] || grid[x][y] == BLOCKED)
        return false;
    
    visited[x][y] = 1;

    // Check if we reached the bottom row
    if (x == L - 1) {
        return true;
    }

    // Explore all four directions
    return dfs(x + 1, y) || dfs(x - 1, y) || dfs(x, y + 1) || dfs(x, y - 1);
}

// Function to check if the system percolates
bool percolates(float p) {
    // Reset visited grid
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            visited[i][j] = 0;
        }
    }

    // Check percolation starting from the top row
    for (int j = 0; j < L; j++) {
        if (grid[0][j] == OPEN && dfs(0, j)) {
            return true; // Found a path from top to bottom
        }
    }
    return false; // No path found
}

// Main function to run the simulator
int main() {
    srand(time(0)); // Seed for random number generation
    float p; // Probability of open site
    int totalExperiments = 100;
    int percolationCount = 0;

    printf("Enter probability of open site (between 0 and 1): ");
    scanf("%f", &p);

    // Running multiple experiments to analyze percolation
    for (int experiment = 0; experiment < totalExperiments; experiment++) {
        initializeGrid(p);
        if (percolates(p)) {
            percolationCount++;
        }
    }

    // Output results
    printf("Out of %d experiments with probability %.2f, percolation occurred %d times.\n",
            totalExperiments, p, percolationCount);
    printf("Percolation probability: %.3f\n", (float)percolationCount / totalExperiments);

    return 0;
}