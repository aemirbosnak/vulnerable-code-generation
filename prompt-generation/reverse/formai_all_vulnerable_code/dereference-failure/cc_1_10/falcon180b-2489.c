//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define P 0.5
#define T 10000

int **create_grid();
void percolate(int **grid);
int count_connected(int **grid, int x, int y);
void print_grid(int **grid);

int main() {
    int **grid = create_grid();
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    percolate(grid);
    print_grid(grid);
    return 0;
}

int **create_grid() {
    int **grid = (int **) malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *) malloc(N * sizeof(int));
    }
    return grid;
}

void percolate(int **grid) {
    int open_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 2;
                open_count++;
            }
        }
    }
    int k = 0;
    while (k < T && open_count > 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    if (count_connected(grid, i, j) == 1) {
                        grid[i][j] = 2;
                        open_count--;
                    }
                }
            }
        }
        k++;
    }
}

int count_connected(int **grid, int x, int y) {
    int count = 0;
    if (x > 0 && grid[x-1][y] == 2) count++;
    if (x < N-1 && grid[x+1][y] == 2) count++;
    if (y > 0 && grid[x][y-1] == 2) count++;
    if (y < N-1 && grid[x][y+1] == 2) count++;
    if (count == 1) return 1;
    else return 0;
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) printf(".");
            else if (grid[i][j] == 1) printf("X");
            else printf("O");
        }
        printf("\n");
    }
}