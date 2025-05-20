//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid

// Define grid for percolation
int grid[N][N];

// Function to initialize the grid with blocked sites
void initializeGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0; // 0 indicates blocked
        }
    }
}

// Function to randomly open sites
void openSites(double probability) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double randVal = (double) rand() / RAND_MAX;
            if (randVal < probability) {
                grid[i][j] = 1; // 1 indicates open
            }
        }
    }
}

// Function to print the grid state
void printGrid() {
    printf("\nGrid State:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if there's a path from top to bottom
int isConnected(int x, int y, int visited[N][N]) {
    if (x < 0 || y < 0 || x >= N || y >= N || visited[x][y] || grid[x][y] == 0) {
        return 0; // Out of bounds or already visited or blocked
    }
    if (x == N - 1) {
        return 1; // Path to the bottom row found
    }

    // Mark cell as visited
    visited[x][y] = 1;

    // Check all four directions
    if (isConnected(x + 1, y, visited) || 
        isConnected(x - 1, y, visited) || 
        isConnected(x, y + 1, visited) || 
        isConnected(x, y - 1, visited)) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    double probability;
    
    printf("Enter the probability for site opening (0.0 to 1.0): ");
    scanf("%lf", &probability);
    
    if (probability < 0.0 || probability > 1.0) {
        printf("Invalid probability value. It must be between 0 and 1.\n");
        return 1;
    }

    // Initialize the grid
    initializeGrid();
    // Open sites based on the given probability
    openSites(probability);
    
    // Print the grid state
    printGrid();

    // Check connectivity from top row to the bottom row
    int visited[N][N] = {0}; // Initialize visited array
    int percolates = 0;

    for (int j = 0; j < N; j++) {
        if (grid[0][j] == 1 && !visited[0][j]) { // Starting from open sites
            if (isConnected(0, j, visited)) {
                percolates = 1;
                break;
            }
        }
    }

    // Output result
    if (percolates) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}