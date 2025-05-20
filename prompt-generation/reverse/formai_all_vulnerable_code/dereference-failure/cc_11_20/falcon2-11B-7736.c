//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Prototype for the game of life function
int game_of_life(int** grid, int num_rows, int num_cols);

int main() {
    // Define the number of rows and columns for the grid
    int num_rows = 10;
    int num_cols = 10;

    // Allocate memory for the grid
    int** grid = malloc(num_rows * sizeof(int*));
    for (int i = 0; i < num_rows; i++) {
        grid[i] = malloc(num_cols * sizeof(int));
    }

    // Initialize the grid with random live cells
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            grid[i][j] = rand() % 2 == 0;
        }
    }

    // Call the game of life function to update the grid
    game_of_life(grid, num_rows, num_cols);

    // Print the final state of the grid
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < num_rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

// Function to update the grid according to the rules of the Game of Life
int game_of_life(int** grid, int num_rows, int num_cols) {
    // Initialize the new grid with the same dimensions as the old grid
    int** new_grid = malloc(num_rows * sizeof(int*));
    for (int i = 0; i < num_rows; i++) {
        new_grid[i] = malloc(num_cols * sizeof(int));
    }

    // Iterate over each cell in the grid
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            // Count the number of live neighbors for the current cell
            int live_neighbors = 0;

            // Check the neighboring cells and count the live cells
            if (i > 0 && j > 0 && i < num_rows - 1 && j < num_cols - 1) {
                if (grid[i - 1][j - 1] && grid[i - 1][j] && grid[i - 1][j + 1]) {
                    live_neighbors++;
                }
                if (grid[i - 1][j] && grid[i][j - 1] && grid[i][j + 1]) {
                    live_neighbors++;
                }
                if (grid[i][j - 1] && grid[i + 1][j - 1] && grid[i + 1][j]) {
                    live_neighbors++;
                }
                if (grid[i + 1][j - 1] && grid[i + 1][j] && grid[i + 1][j + 1]) {
                    live_neighbors++;
                }
            }

            // Update the cell based on the number of live neighbors
            if (grid[i][j] && (live_neighbors < 2 || live_neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (!grid[i][j] && live_neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }

    // Free the old grid and replace it with the new grid
    for (int i = 0; i < num_rows; i++) {
        free(grid[i]);
    }
    free(grid);
    grid = new_grid;
    new_grid = NULL;

    // Call the game of life function recursively to update the grid again
    game_of_life(grid, num_rows, num_cols);

    return 0;
}