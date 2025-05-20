//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 1000
#define P 0.5
#define T 100

int **create_grid();
void percolate(int **grid);
int count_neighbors(int **grid, int x, int y);
void print_grid(int **grid);
int main() {
    srand(time(NULL));
    int **grid = create_grid();
    percolate(grid);
    print_grid(grid);
    free(grid);
    return 0;
}

int **create_grid() {
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

void percolate(int **grid) {
    int x, y, n;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    n = count_neighbors(grid, i, j);
                    if (n == 0 || n == 1) {
                        grid[i][j] = 0;
                    }
                } else if (grid[i][j] == 0 && rand() % 100 < P) {
                    grid[i][j] = 1;
                }
            }
        }
    }
}

int count_neighbors(int **grid, int x, int y) {
    int count = 0;
    if (x > 0 && grid[x - 1][y] == 1) {
        count++;
    }
    if (x < N - 1 && grid[x + 1][y] == 1) {
        count++;
    }
    if (y > 0 && grid[x][y - 1] == 1) {
        count++;
    }
    if (y < N - 1 && grid[x][y + 1] == 1) {
        count++;
    }
    return count;
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}