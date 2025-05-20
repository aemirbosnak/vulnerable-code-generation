//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    // Define the size of the grid
    int grid_size = 30;

    // Allocate memory for the grid
    int *grid = (int *)malloc(grid_size * grid_size * sizeof(int));

    // Initialize the grid with random live cells
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            grid[i * grid_size + j] = rand() % 2;
        }
    }

    // Print the initial grid
    printf("Initial Grid:\n");
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%d ", grid[i * grid_size + j]);
        }
        printf("\n");
    }

    // Print the updated grid after each iteration
    for (int i = 0; i < 10; i++) {
        // Iterate through each cell in the grid
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                // Check the rules for the Game of Life
                int live_neighbors = 0;
                if (i > 0 && grid[i - 1] > 0) live_neighbors++;
                if (i < grid_size - 1 && grid[i + 1] > 0) live_neighbors++;
                if (j > 0 && grid[i * grid_size + j - 1] > 0) live_neighbors++;
                if (j < grid_size - 1 && grid[i * grid_size + j + 1] > 0) live_neighbors++;
                if (live_neighbors == 2 || live_neighbors == 3) {
                    grid[i * grid_size + j] = 1;
                } else {
                    grid[i * grid_size + j] = 0;
                }
            }
        }

        // Print the updated grid
        printf("Iteration %d:\n", i + 1);
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                printf("%d ", grid[i * grid_size + j]);
            }
            printf("\n");
        }
    }

    // Free the allocated memory for the grid
    free(grid);

    return 0;
}