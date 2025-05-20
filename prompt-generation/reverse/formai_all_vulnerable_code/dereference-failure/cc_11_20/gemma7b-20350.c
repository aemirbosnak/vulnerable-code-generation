//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 256

int main() {
    int i, j, x, y, z, t, n, m;
    n = m = 0;
    time_t t_start, t_end;
    t_start = time(NULL);

    // Allocate memory for the grid
    int **grid = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++) {
        grid[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            grid[i][j] = 0;
        }
    }

    // Generate random numbers for the seeds
    srand(time(NULL));
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            grid[i][j] = rand() % MAX;
        }
    }

    // Percolation process
    for (t = 0; t < MAX; t++) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                x = i - 1;
                y = j - 1;
                z = grid[i][j] - grid[x][y];
                if (z > 0) {
                    grid[i][j] = 1;
                }
            }
        }
    }

    // Count the number of active sites
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (grid[i][j] == 1) {
                n++;
            }
        }
    }

    // Print the number of active sites
    printf("The number of active sites is: %d\n", n);

    // Free the memory
    for (i = 0; i < MAX; i++) {
        free(grid[i]);
    }
    free(grid);

    t_end = time(NULL);
    printf("Time taken: %ld seconds\n", t_end - t_start);

    return 0;
}