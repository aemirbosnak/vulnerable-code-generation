//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Set the random seed for reproducibility
    srand(time(NULL));

    // Set the size of the grid
    int grid_size = 20;

    // Create an array to store the grid
    int *grid = (int *)malloc(grid_size * sizeof(int));

    // Initialize the grid to 0
    for (int i = 0; i < grid_size; i++) {
        grid[i] = 0;
    }

    // Initialize the boundary conditions
    int top = grid_size - 1;
    int bottom = 0;
    int left = 0;
    int right = grid_size - 1;

    // Perform the percolation simulation
    for (int i = 0; i < 10000; i++) {
        // Choose a random cell in the grid
        int x = rand() % grid_size;
        int y = rand() % grid_size;

        // Check if the cell is already open
        if (grid[x * grid_size + y] == 1) {
            continue;
        }

        // Check the neighboring cells and open them if they are not open
        if (x > 0 && grid[x - 1 * grid_size + y] == 0) {
            grid[x - 1 * grid_size + y] = 1;
        }
        if (x < grid_size - 1 && grid[x + 1 * grid_size + y] == 0) {
            grid[x + 1 * grid_size + y] = 1;
        }
        if (y > 0 && grid[x * grid_size + y - 1] == 0) {
            grid[x * grid_size + y - 1] = 1;
        }
        if (y < grid_size - 1 && grid[x * grid_size + y + 1] == 0) {
            grid[x * grid_size + y + 1] = 1;
        }
    }

    // Print the final state of the grid
    printf("Final state of the grid:\n");
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%d ", grid[i * grid_size + j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    free(grid);

    return 0;
}