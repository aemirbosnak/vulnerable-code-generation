//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // number of sites
#define T 1000 // number of trials
#define P 0.5 // probability of a site being open

int **create_grid(int n) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = -1; // -1 means closed site
        }
    }
    return grid;
}

void percolate(int **grid, int n, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return;
    if (grid[i][j] == -1) {
        grid[i][j] = 1; // open site
        if (i > 0 && grid[i - 1][j] == -1)
            percolate(grid, n, i - 1, j);
        if (i < n - 1 && grid[i + 1][j] == -1)
            percolate(grid, n, i + 1, j);
        if (j > 0 && grid[i][j - 1] == -1)
            percolate(grid, n, i, j - 1);
        if (j < n - 1 && grid[i][j + 1] == -1)
            percolate(grid, n, i, j + 1);
    }
}

int main() {
    srand(time(NULL));
    int **grid = create_grid(N);
    int count = 0;
    for (int t = 0; t < T; t++) {
        int i = rand() % N;
        int j = rand() % N;
        if (grid[i][j] == -1 && rand() % 100 < P) {
            percolate(grid, N, i, j);
            count++;
        }
    }
    printf("Percolation threshold: %.2f\n", (double)count / T);
    return 0;
}