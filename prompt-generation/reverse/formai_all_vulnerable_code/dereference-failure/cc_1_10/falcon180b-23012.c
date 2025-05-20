//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define DROPS 10000
#define POROSITY 0.5

int **createGrid();
void percolate(int **grid, int size);
int isFull(int **grid, int x, int y);
int countAdjacent(int **grid, int x, int y);
int main() {
    int **grid;
    int size = SIZE;
    int drops = DROPS;
    int porosity = POROSITY;
    srand(time(NULL));
    grid = createGrid();
    percolate(grid, size);
    printf("Grid size: %d\n", size);
    printf("Drops: %d\n", drops);
    printf("Porosity: %.2f\n", porosity);
    return 0;
}
int **createGrid() {
    int **grid;
    int i, j;
    grid = (int **)malloc(sizeof(int *) * SIZE);
    for (i = 0; i < SIZE; i++) {
        grid[i] = (int *)malloc(sizeof(int) * SIZE);
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}
void percolate(int **grid, int size) {
    int i, j, k;
    for (k = 0; k < size * size; k++) {
        i = rand() % size;
        j = rand() % size;
        if (grid[i][j] == 0 && countAdjacent(grid, i, j) == 0) {
            grid[i][j] = 1;
        }
    }
}
int isFull(int **grid, int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        return 0;
    }
    return grid[x][y] == 1;
}
int countAdjacent(int **grid, int x, int y) {
    int count = 0;
    if (isFull(grid, x - 1, y)) count++;
    if (isFull(grid, x + 1, y)) count++;
    if (isFull(grid, x, y - 1)) count++;
    if (isFull(grid, x, y + 1)) count++;
    return count;
}