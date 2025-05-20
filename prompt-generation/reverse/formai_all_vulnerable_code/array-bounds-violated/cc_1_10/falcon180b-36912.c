//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define DROPS 1000

int grid[ROWS][COLS];
int count = 0;

void init_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

void draw_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int check_neighbors(int x, int y) {
    int count = 0;
    if (x > 0 && grid[x - 1][y] == 1) {
        count++;
    }
    if (x < COLS - 1 && grid[x + 1][y] == 1) {
        count++;
    }
    if (y > 0 && grid[x][y - 1] == 1) {
        count++;
    }
    if (y < ROWS - 1 && grid[x][y + 1] == 1) {
        count++;
    }
    return count;
}

void percolate() {
    srand(time(NULL));
    for (int i = 0; i < DROPS; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        if (grid[x][y] == 0 && check_neighbors(x, y) == 1) {
            grid[x][y] = 1;
            count++;
        }
    }
}

int main() {
    init_grid();
    percolate();
    draw_grid();
    printf("Percolation threshold: %.2f\n", (float)count / (ROWS * COLS));
    return 0;
}