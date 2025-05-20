//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, i, j, k, count = 0;
    int **grid;
    int x, y, nx, ny;
    int top = 0, bottom = N-1;
    int left = 0, right = N-1;

    srand(time(NULL));
    N = rand() % 20 + 5;

    grid = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < 100; k++) {
        for (i = 1; i < N-1; i++) {
            for (j = 1; j < N-1; j++) {
                count = 0;
                if (grid[i-1][j] == 1) {
                    count++;
                }
                if (grid[i][j-1] == 1) {
                    count++;
                }
                if (grid[i+1][j] == 1) {
                    count++;
                }
                if (grid[i][j+1] == 1) {
                    count++;
                }

                if (count == 3) {
                    grid[i][j] = 1;
                } else if (count == 4) {
                    grid[i][j] = 0;
                }
            }
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}