//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // number of sites
#define M 1000 // number of trials

int **create_grid(int n) {
    int **grid = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = -1; // -1 indicates a blocked site
        }
    }
    return grid;
}

void percolate(int **grid, int n, int x, int y, int t) {
    if (t == 0) {
        if (grid[x][y] == -1) {
            grid[x][y] = 0;
        }
    } else if (t == 1) {
        if (grid[x][y] == 0) {
            grid[x][y] = 1;
        }
    }
}

void print_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int **grid = create_grid(N);
    for (int i = 0; i < M; i++) {
        int x = rand() % N;
        int y = rand() % N;
        percolate(grid, N, x, y, rand() % 2);
    }
    print_grid(grid, N);
    return 0;
}