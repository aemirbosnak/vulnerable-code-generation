//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ITERATIONS 1000

// Define the grid
int rows, cols;
int grid[MAX_ROWS][MAX_COLS];

// Define the percolation parameters
int num_iterations;
int num_percolations;

// Define the percolation algorithm
void percolate(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return;

    // Check if the cell is already percolated
    if (grid[row][col] == 1)
        return;

    // Check if the cell is a boundary cell
    if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
        grid[row][col] = 1;
        num_percolations++;
    } else {
        // Check if the cell is percolated
        int count = 0;
        if (grid[row - 1][col] == 1)
            count++;
        if (grid[row + 1][col] == 1)
            count++;
        if (grid[row][col - 1] == 1)
            count++;
        if (grid[row][col + 1] == 1)
            count++;

        // Percolate the cell if it has at least two percolated neighbors
        if (count >= 2) {
            grid[row][col] = 1;
            num_percolations++;
        }
    }
}

// Define the main function
int main() {
    // Initialize the grid with random values
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Get the percolation parameters
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);
    printf("Enter the number of percolations: ");
    scanf("%d", &num_percolations);

    // Percolate the grid
    for (int i = 0; i < num_iterations; i++) {
        for (int j = 0; j < num_percolations; j++) {
            int row = rand() % rows;
            int col = rand() % cols;
            percolate(row, col);
        }
    }

    // Print the grid
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0)
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }

    return 0;
}