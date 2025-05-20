//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int main() {
    srand(time(NULL));

    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2 == 0;
        }
    }

    int occupied_neighbors[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            occupied_neighbors[i][j] = 0;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j]) {
                    if (occupied_neighbors[i][j] == 0) {
                        occupied_neighbors[i][j] = 1;
                        grid[i][j] = 0;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                count++;
            }
        }
    }

    printf("Percolation simulator: %d occupied cells\n", count);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            free(grid[i][j]);
        }
        free(grid[i]);
    }
    free(grid);

    return 0;
}