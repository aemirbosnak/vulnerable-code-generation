//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WATER_LEVEL 0.5
#define BOTTOM_ROW 9
#define LEFT_COL 0
#define RIGHT_COL 9
#define TOP_ROW 0

int grid[ROWS][COLS];
int water_level;
int num_droplets;

void init_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

void add_water() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < num_droplets; i++) {
        int x = rand() % COLS;
        int y = rand() % ROWS;
        if (x == LEFT_COL || x == RIGHT_COL || y == TOP_ROW || y == BOTTOM_ROW) {
            continue;
        }
        if (grid[y][x] == 0) {
            grid[y][x] = 1;
        }
    }
}

int count_neighbors(int row, int col) {
    int count = 0;
    if (row > 0 && grid[row - 1][col] == 1) {
        count++;
    }
    if (row < ROWS - 1 && grid[row + 1][col] == 1) {
        count++;
    }
    if (col > 0 && grid[row][col - 1] == 1) {
        count++;
    }
    if (col < COLS - 1 && grid[row][col + 1] == 1) {
        count++;
    }
    return count;
}

void percolate() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                int neighbors = count_neighbors(i, j);
                if (neighbors < 2) {
                    grid[i][j] = 0;
                } else if (neighbors == 2) {
                    grid[i][j] = 2;
                }
            }
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of droplets: ");
    scanf("%d", &num_droplets);
    init_grid();
    add_water();
    printf("\n");
    for (i = TOP_ROW; i < BOTTOM_ROW; i++) {
        for (j = LEFT_COL; j < RIGHT_COL; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else if (grid[i][j] == 2) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    percolate();
    for (i = TOP_ROW; i < BOTTOM_ROW; i++) {
        for (j = LEFT_COL; j < RIGHT_COL; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else if (grid[i][j] == 2) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}