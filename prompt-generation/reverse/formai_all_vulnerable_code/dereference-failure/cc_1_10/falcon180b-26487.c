//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 100
#define T 0.5
#define D 0.5

int **create_grid(int n, int m) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void free_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

void percolate(int **grid, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    printf("Percentage of Percolation: %f\n", (float)count / (n * m) * 100);
}

int main() {
    srand(time(NULL));
    int **grid = create_grid(N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (rand() % 100 <= T) {
                grid[i][j] = 1;
            }
        }
    }
    percolate(grid, N, M);
    free_grid(grid, N);
    return 0;
}