//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array of integers to represent the grid
    int **grid = NULL;
    int rows = 10;
    int cols = 10;
    grid = malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(int));
    }

    // Initialize the grid with random values
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = rand() % 2;
        }
    }

    // Simulate the percolaton process
    int x = 0;
    int y = 0;
    int direction = 0;
    int current_value = 0;
    while (current_value != -1) {
        // Get the current value of the cell
        current_value = grid[x][y];

        // If the current value is -1, it means that the cell is already flooded
        if (current_value == -1) {
            continue;
        }

        // If the current value is 1, it means that the cell is not yet flooded
        else if (current_value == 1) {
            // Flood the cell
            grid[x][y] = -1;

            // Move in the direction of the current flow
            switch (direction) {
                case 0:
                    x++;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y--;
                    break;
            }

            // If the cell is not within the bounds of the grid, wrap around
            if (x < 0) {
                x = cols - 1;
            } else if (x >= cols) {
                x = 0;
            }

            if (y < 0) {
                y = rows - 1;
            } else if (y >= rows) {
                y = 0;
            }

            // Repeat the process for the next cell
            continue;
        }

        // Break out of the loop if the grid is completely flooded
        if (current_value == 0) {
            break;
        }
    }

    // Print the grid
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}