//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3
#define FULL -1
#define EMPTY 0

int **create_grid(int size);
void init_grid(int **grid, int size);
int check_neighbors(int **grid, int row, int col);
void percolate(int **grid, int size);
void print_grid(int **grid, int size);

int main() {
    int size = SIZE;
    int **grid = create_grid(size);
    init_grid(grid, size);
    percolate(grid, size);
    print_grid(grid, size);
    return 0;
}

int **create_grid(int size) {
    int **grid = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *) malloc(size * sizeof(int));
    }
    return grid;
}

void init_grid(int **grid, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = (rand() % 2)? FULL : EMPTY;
        }
    }
}

int check_neighbors(int **grid, int row, int col) {
    int neighbors = 0;
    if (row > 0 && grid[row - 1][col] == FULL) {
        neighbors++;
    }
    if (col > 0 && grid[row][col - 1] == FULL) {
        neighbors++;
    }
    if (row < SIZE - 1 && grid[row + 1][col] == FULL) {
        neighbors++;
    }
    if (col < SIZE - 1 && grid[row][col + 1] == FULL) {
        neighbors++;
    }
    return neighbors;
}

void percolate(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == EMPTY && check_neighbors(grid, i, j) == 3) {
                grid[i][j] = FULL;
            }
        }
    }
}

void print_grid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == FULL) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}