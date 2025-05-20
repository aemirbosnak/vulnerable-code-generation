//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_rows = 10;
    int num_cols = 10;
    int num_steps = 1000;
    int **grid;

    srand(time(NULL));

    grid = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        grid[i] = (int *)malloc(num_cols * sizeof(int));
        for (int j = 0; j < num_cols; j++) {
            grid[i][j] = rand() % 2 == 0;
        }
    }

    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                int neighbors = 0;
                for (int k = -1; k <= 1; k += 2) {
                    for (int l = -1; l <= 1; l += 2) {
                        if (i + k >= 0 && i + k < num_rows &&
                            j + l >= 0 && j + l < num_cols) {
                            if (grid[i + k][j + l] == 1) {
                                neighbors++;
                            }
                        }
                    }
                }
                if (grid[i][j] == 1 && neighbors == 0) {
                    grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors >= 4) {
                    grid[i][j] = 1;
                }
            }
        }
    }

    printf("Percolation Simulation\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}