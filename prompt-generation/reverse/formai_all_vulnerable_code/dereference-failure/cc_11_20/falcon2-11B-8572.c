//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    int n = 100;
    int r = 0.5;
    int m = 100000;

    srand(time(NULL));

    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 1;
        }
    }

    int count = 0;
    while (count < m) {
        int x = rand() % n;
        int y = rand() % n;
        int neighbours = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < n) {
                    if (grid[x + i][y + j] == 1) {
                        neighbours++;
                    }
                }
            }
        }
        if (rand() % 100 < r && neighbours >= 4) {
            grid[x][y] = 0;
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}