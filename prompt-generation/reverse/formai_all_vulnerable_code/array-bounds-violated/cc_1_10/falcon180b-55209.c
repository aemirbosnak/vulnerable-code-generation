//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define DROPS 100

int grid[ROWS][COLS];
int numDrops;

void initGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

void drop(int x, int y) {
    if (y >= COLS) {
        return;
    }
    if (grid[x][y] == 0 && grid[x][y+1] == 0) {
        grid[x][y] = 1;
        grid[x][y+1] = 1;
        numDrops++;
    }
}

void percolate(int x, int y) {
    if (y < 0 || y >= COLS) {
        return;
    }
    if (grid[x][y] == 1) {
        grid[x][y] = 0;
        numDrops -= 2;
    }
}

int countDrops() {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initGrid();
    for (int i = 0; i < DROPS; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        drop(x, y);
    }
    printf("Initial grid:\n");
    printGrid();
    while (numDrops > 0) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        percolate(x, y);
        printf("Grid after percolation:\n");
        printGrid();
    }
    return 0;
}