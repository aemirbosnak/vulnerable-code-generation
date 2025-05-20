//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
// Percolation Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define N 100
#define M 100

typedef struct {
    int i, j;
} pair_t;

void init_percolation(int n, int m, int **grid) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_percolation(int n, int m, int **grid) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", grid[i][j] ? 'X' : '.');
        }
        printf("\n");
    }
}

bool is_full(int n, int m, int **grid) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool is_percolated(int n, int m, int **grid) {
    for (int i = 0; i < n; i++) {
        if (grid[i][0] && grid[i][m-1]) {
            return true;
        }
    }
    return false;
}

void run_percolation(int n, int m, int **grid) {
    srand(time(NULL));
    init_percolation(n, m, grid);
    while (!is_percolated(n, m, grid)) {
        pair_t pair = {rand() % n, rand() % m};
        grid[pair.i][pair.j] = 1;
    }
    print_percolation(n, m, grid);
}

int main() {
    int **grid = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        grid[i] = (int*)malloc(M * sizeof(int));
    }
    run_percolation(N, M, grid);
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}