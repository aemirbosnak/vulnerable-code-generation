//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define D 0.5
#define T 100

int **create_grid();
void percolate(int **grid);
int count_neighbors(int **grid, int row, int col);
int is_full(int **grid, int row, int col);
int is_empty(int **grid, int row, int col);
void print_grid(int **grid);

int main() {
    int **grid = create_grid();
    percolate(grid);
    print_grid(grid);
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
    int row, col;
    for (int t = 0; t < T; t++) {
        row = rand() % N;
        col = rand() % N;
        if (is_empty(grid, row, col)) {
            grid[row][col] = 1;
        }
    }
}

int count_neighbors(int **grid, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && is_full(grid, row + i, col + j)) {
                count++;
            }
        }
    }
    return count;
}

int is_full(int **grid, int row, int col) {
    return grid[row][col] == 1;
}

int is_empty(int **grid, int row, int col) {
    return grid[row][col] == 0;
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}