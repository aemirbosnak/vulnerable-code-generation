//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main() {
    int **grid = NULL;
    int i, j, x, y, seed;

    // Allocate memory for the grid
    grid = malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Percolation
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if (grid[y][x] == 0) {
                if (rand() % 2 == 0) {
                    grid[y][x] = 1;
                }
            }
        }
    }

    // Print the grid
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}