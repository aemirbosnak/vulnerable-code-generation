//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10
#define MAX_ITERATIONS 500

int main() {
    int **grid = NULL;
    int i, j, k, iterations = 0, seed = time(NULL);
    srand(seed);

    grid = malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++) {
        grid[i] = malloc(DIM * sizeof(int));
        for (j = 0; j < DIM; j++) {
            grid[i][j] = 0;
        }
    }

    // Percolation Algorithm
    for (k = 0; k < MAX_ITERATIONS; k++) {
        for (i = 0; i < DIM; i++) {
            for (j = 0; j < DIM; j++) {
                if (grid[i][j] == 1) {
                    // Randomly select a neighbor
                    int r = rand() % 4;
                    switch (r) {
                        case 0:
                            if (grid[i-1][j] == 0) grid[i-1][j] = 1;
                            break;
                        case 1:
                            if (grid[i+1][j] == 0) grid[i+1][j] = 1;
                            break;
                        case 2:
                            if (grid[i][j-1] == 0) grid[i][j-1] = 1;
                            break;
                        case 3:
                            if (grid[i][j+1] == 0) grid[i][j+1] = 1;
                            break;
                    }
                }
            }
        }
        iterations++;
    }

    // Print the final grid
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}