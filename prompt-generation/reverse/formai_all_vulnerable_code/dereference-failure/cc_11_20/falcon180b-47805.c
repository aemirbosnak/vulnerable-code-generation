//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int n, m, k, count = 0;
    int **grid;
    int top = 0, bottom = 0;
    int left = 0, right = 0;
    int i, j;

    srand(time(NULL));
    n = rand() % 10 + 5; // randomly generate the size of the grid
    m = rand() % 10 + 5; // randomly generate the number of iterations
    k = rand() % 10 + 5; // randomly generate the number of drops

    grid = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++) {
        int x = rand() % n;
        int y = rand() % n;
        grid[x][y] = 1;
        if (x < top) {
            top = x;
        }
        if (x > bottom) {
            bottom = x;
        }
        if (y < left) {
            left = y;
        }
        if (y > right) {
            right = y;
        }
    }

    for (i = 0; i < k; i++) {
        int x = rand() % n;
        int y = rand() % n;
        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            count++;
        }
    }

    printf("Grid Size: %d\n", n);
    printf("Number of Iterations: %d\n", m);
    printf("Number of Drops: %d\n", k);
    printf("Number of Drops on Grid: %d\n", count);
    printf("Top: %d\n", top);
    printf("Bottom: %d\n", bottom);
    printf("Left: %d\n", left);
    printf("Right: %d\n", right);

    return 0;
}