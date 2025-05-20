//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000

int **create_grid(int size) {
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void free_grid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
}

int count_neighbors(int **grid, int x, int y, int size) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && grid[x + i][y + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void percolate(int **grid, int x, int y, int size) {
    grid[x][y] = 1;
    if (count_neighbors(grid, x, y, size) == 2) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i!= 0 || j!= 0) && grid[x + i][y + j] == 0) {
                    grid[x + i][y + j] = 1;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    int **grid = create_grid(size);
    int x = rand() % size;
    int y = rand() % size;
    percolate(grid, x, y, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    free_grid(grid, size);
    return 0;
}