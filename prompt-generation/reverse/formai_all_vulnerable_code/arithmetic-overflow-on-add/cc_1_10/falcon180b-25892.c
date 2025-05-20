//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

int grid[ROWS][COLS];
int numDrops;
int numFilled;

void initGrid() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void drawGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && grid[(row + i + ROWS) % ROWS][(col + j + COLS) % COLS] == 1) {
                count++;
            }
        }
    }
    return count;
}

void percolate(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return;
    }
    if (grid[row][col] == 1) {
        numFilled++;
    }
    if (grid[row][col] == 0) {
        grid[row][col] = 1;
        numFilled++;
        numDrops++;
    }
}

int main() {
    initGrid();
    drawGrid();
    int row, col;
    while (1) {
        printf("Enter row and column to drop water: ");
        scanf("%d %d", &row, &col);
        row = (row + ROWS) % ROWS;
        col = (col + COLS) % COLS;
        if (grid[row][col] == 0) {
            percolate(row, col);
        }
    }
    return 0;
}