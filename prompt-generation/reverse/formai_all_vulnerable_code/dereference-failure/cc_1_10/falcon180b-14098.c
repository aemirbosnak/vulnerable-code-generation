//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define N 20
#define D 0.5

int **create_grid();
void percolate(int **grid, int x, int y);
int check_neighbors(int **grid, int x, int y);

int main() {
    srand(time(NULL));
    int **grid = create_grid();
    percolate(grid, 0, 0);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int **create_grid() {
    int **grid = (int **) malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (int *) malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

void percolate(int **grid, int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        return;
    }
    if (grid[x][y] == 1) {
        grid[x][y] = 2;
        percolate(grid, x - 1, y);
        percolate(grid, x + 1, y);
        percolate(grid, x, y - 1);
        percolate(grid, x, y + 1);
    } else if (grid[x][y] == 0 && check_neighbors(grid, x, y) == 3) {
        grid[x][y] = 1;
    }
}

int check_neighbors(int **grid, int x, int y) {
    int count = 0;
    if (grid[x - 1][y] == 1) {
        count++;
    }
    if (grid[x + 1][y] == 1) {
        count++;
    }
    if (grid[x][y - 1] == 1) {
        count++;
    }
    if (grid[x][y + 1] == 1) {
        count++;
    }
    return count;
}