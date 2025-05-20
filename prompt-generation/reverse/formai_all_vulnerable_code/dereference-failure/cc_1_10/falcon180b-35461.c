//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20
#define P 0.5
#define N_DROPS 1000

int rows, cols;
int **grid;

void init_grid() {
    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;
    grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2)? 1 : 0;
        }
    }
}

void percolate() {
    int count = 0;
    while (count < N_DROPS) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            count++;
        }
    }
}

void print_grid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    init_grid();
    percolate();
    print_grid();
    return 0;
}