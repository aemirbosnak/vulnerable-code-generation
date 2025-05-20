//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the grid
#define MAX_SIZE 100

// Grid Size
int n;

// Grid
int grid[MAX_SIZE][MAX_SIZE];

// Function that generates a random number in the range [0, 1]
int rand_bool() {
    return rand() < RAND_MAX/2.0;
}

// Function that initializes the grid with random values
void init() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = rand_bool();
        }
    }
}

// Recursive function that performs depth-first search
void dfs(int row, int col) {
    // Check if the cell is in the grid
    if (row < 0 || col < 0 || row >= n || col >= n) {
        return;
    }

    // Check if the cell is already visited or blocked
    if (grid[row][col] == 0 || grid[row][col] == 2) {
        return;
    }

    // Mark the cell as visited
    grid[row][col] = 2;

    // Recursive call to all neighbouring cells
    dfs(row - 1, col);
    dfs(row + 1, col);
    dfs(row, col - 1);
    dfs(row, col + 1);
}

// Function that checks if the top and bottom rows are connected
int percolates() {
    // Perform depth-first search on top row
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 1) {
            dfs(0, i);
        }
    }

    // Check if any cell in the bottom row is visited
    for (int i = 0; i < n; i++) {
        if (grid[n-1][i] == 2) {
            return 1;
        }
    }

    return 0;
}

// Main function
int main() {
    // Read the size of the grid from user
    printf("Enter the size of the grid: ");
    scanf("%d", &n);

    // Initialize the grid with random values
    init();

    // Print the initial state of the grid
    printf("Initial Grid:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Check if the top and bottom rows are connected
    if (percolates()) {
        printf("Percolates\n");
    } else {
        printf("Does not Percolate\n");
    }

    return 0;
}