//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define OPEN 1  // Cell state: open
#define BLOCKED 0 // Cell state: blocked

// Define the grid
int grid[SIZE][SIZE];

// Function to initialize the grid
void initialize_grid() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = BLOCKED;
}

// Function to fill the grid with random states
void populate_grid(double probability) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = (rand() / (double)RAND_MAX) < probability ? OPEN : BLOCKED;
}

// Function to print the grid
void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// Function to check if cell is in bounds
int is_in_bounds(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// Function to check if percolation exists
int check_percolation(int x, int y, int visited[SIZE][SIZE]) {
    // If we reach the bottom row
    if (x == SIZE - 1) return 1;
    
    // If out of bounds or already visited, or blocked
    if (!is_in_bounds(x, y) || visited[x][y] || grid[x][y] == BLOCKED) return 0;
    
    // Mark the cell as visited
    visited[x][y] = 1;

    // Check all possible directions
    if (check_percolation(x + 1, y, visited)) return 1; // Down
    if (check_percolation(x - 1, y, visited)) return 1; // Up
    if (check_percolation(x, y + 1, visited)) return 1; // Right
    if (check_percolation(x, y - 1, visited)) return 1; // Left

    return 0; // No percolation found
}

// Function to perform percolation check
int percolates() {
    int visited[SIZE][SIZE] = {0}; // Initialize visited array
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i] == OPEN && check_percolation(0, i, visited)) {
            return 1; // Found percolation
        }
    }
    return 0; // No percolation
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    double probability; // Probability of a site being open

    // Get user input for the probability
    printf("Enter the probability (between 0 and 1) of a site being open: ");
    scanf("%lf", &probability);
    
    // Ensure valid input
    if (probability < 0 || probability > 1) {
        printf("Invalid probability! Must be between 0 and 1.\n");
        return 1;
    }

    // Initialize and populate the grid
    initialize_grid();
    populate_grid(probability);

    // Print the resulting grid
    printf("Generated grid:\n");
    print_grid();

    // Check for percolation and display the result
    if (percolates()) {
        printf("Percolation occurs!\n");
    } else {
        printf("No percolation found.\n");
    }

    return 0;
}