//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // maximum size of the grid
#define THRESHOLD 0.5 // probability threshold for percolation

int grid[MAX_SIZE][MAX_SIZE]; // the grid
int size; // size of the grid

void init_grid(int s) {
    size = s;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0; // initialize all cells to be empty
        }
    }
}

void add_cell(int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        grid[x][y] = 1; // add a cell to the grid
    }
}

int count_neighbors(int x, int y) {
    int count = 0;
    if (x > 0 && grid[x-1][y] == 1) {
        count++;
    }
    if (x < size - 1 && grid[x+1][y] == 1) {
        count++;
    }
    if (y > 0 && grid[x][y-1] == 1) {
        count++;
    }
    if (y < size - 1 && grid[x][y+1] == 1) {
        count++;
    }
    return count;
}

void percolate() {
    srand(time(NULL)); // initialize the random number generator
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 0) {
                int neighbors = count_neighbors(i, j);
                if (neighbors >= THRESHOLD) {
                    add_cell(i, j);
                }
            }
        }
    }
}

void print_grid() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    int s;
    printf("Enter the size of the grid: ");
    scanf("%d", &s);
    init_grid(s);
    percolate();
    print_grid();
    return 0;
}