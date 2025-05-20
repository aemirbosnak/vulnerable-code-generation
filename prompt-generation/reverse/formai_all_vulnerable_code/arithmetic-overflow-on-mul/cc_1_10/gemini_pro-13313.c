//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int **grid;  // 2D array to represent the grid
int N;       // Size of the grid (N x N)
int num_open;  // Number of open sites
int threshold; // Percolation threshold (percentage)

// Function to initialize the grid
void init_grid() {
    // Allocate memory for the grid
    grid = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = malloc(N * sizeof(int));
    }

    // Initialize all sites to closed
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }

    // Initialize the number of open sites to 0
    num_open = 0;
}

// Function to open a site at (row, col)
void open_site(int row, int col) {
    // Check if the site is already open
    if (grid[row][col] == 1) {
        return;
    }

    // Open the site
    grid[row][col] = 1;

    // Increment the number of open sites
    num_open++;
}

// Function to check if the site at (row, col) is open
int is_open(int row, int col) {
    return grid[row][col] == 1;
}

// Function to check if the site at (row, col) is on the top of the grid
int is_on_top(int row) {
    return row == 0;
}

// Function to check if the site at (row, col) is on the bottom of the grid
int is_on_bottom(int row) {
    return row == N - 1;
}

// Function to check if the site at (row, col) is on the left of the grid
int is_on_left(int col) {
    return col == 0;
}

// Function to check if the site at (row, col) is on the right of the grid
int is_on_right(int col) {
    return col == N - 1;
}

// Function to check if the site at (row, col) is connected to the top of the grid
int is_connected_to_top(int row, int col) {
    // Check if the site is on the top of the grid
    if (is_on_top(row)) {
        return 1;
    }

    // Check if the site above is open and connected to the top
    return is_open(row - 1, col) && is_connected_to_top(row - 1, col);
}

// Function to check if the site at (row, col) is connected to the bottom of the grid
int is_connected_to_bottom(int row, int col) {
    // Check if the site is on the bottom of the grid
    if (is_on_bottom(row)) {
        return 1;
    }

    // Check if the site below is open and connected to the bottom
    return is_open(row + 1, col) && is_connected_to_bottom(row + 1, col);
}

// Function to check if the grid percolates
int does_percolate() {
    // Check if any of the sites on the top of the grid are connected to the bottom
    for (int i = 0; i < N; i++) {
        if (is_connected_to_top(0, i) && is_connected_to_bottom(N - 1, i)) {
            return 1;
        }
    }

    // Otherwise, the grid does not percolate
    return 0;
}

// Function to print the grid
void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the size of the grid
    printf("Enter the size of the grid (N x N): ");
    scanf("%d", &N);

    // Initialize the grid
    init_grid();

    // Open sites randomly until the percolation threshold is reached
    while ((double)num_open / (N * N) < threshold / 100.0) {
        // Generate a random row and column
        int row = rand() % N;
        int col = rand() % N;

        // Open the site
        open_site(row, col);
    }

    // Check if the grid percolates
    int percolates = does_percolate();

    // Print the grid
    print_grid();

    // Print the result
    if (percolates) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}