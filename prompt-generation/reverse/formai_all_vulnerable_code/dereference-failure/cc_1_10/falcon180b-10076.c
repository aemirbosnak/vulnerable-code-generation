//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10
#define P 0.5
#define N 1000

int **create_grid();
void percolate(int **grid);
int check_neighbors(int **grid, int x, int y);
void print_grid(int **grid);

int main() {
    srand(time(NULL));
    int **grid = create_grid();
    percolate(grid);
    print_grid(grid);
    return 0;
}

int **create_grid() {
    int **grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

void percolate(int **grid) {
    int x, y;
    for (int i = 0; i < N; i++) {
        x = rand() % HEIGHT;
        y = rand() % WIDTH;
        if (grid[x][y] == 1 && check_neighbors(grid, x, y) == 0) {
            grid[x][y] = 0;
        } else if (grid[x][y] == 0 && check_neighbors(grid, x, y) > 0) {
            grid[x][y] = 1;
        }
    }
}

int check_neighbors(int **grid, int x, int y) {
    int count = 0;
    if (x > 0 && grid[x - 1][y] == 1) {
        count++;
    }
    if (x < HEIGHT - 1 && grid[x + 1][y] == 1) {
        count++;
    }
    if (y > 0 && grid[x][y - 1] == 1) {
        count++;
    }
    if (y < WIDTH - 1 && grid[x][y + 1] == 1) {
        count++;
    }
    return count;
}

void print_grid(int **grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}