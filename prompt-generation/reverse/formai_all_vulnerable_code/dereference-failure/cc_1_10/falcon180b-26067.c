//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int **grid;
int num_sites;
int num_occupied;
int top;
int bottom;
int left;
int right;
int threshold;

void init_grid() {
    srand(time(NULL));
    grid = (int **) malloc(sizeof(int *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (int *) malloc(sizeof(int) * SIZE);
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    num_sites = 0;
    num_occupied = 0;
    top = 0;
    bottom = SIZE - 1;
    left = 0;
    right = SIZE - 1;
    threshold = (int) (0.5 * SIZE);
}

void percolate() {
    int x, y;
    for (int i = 0; i < num_occupied; i++) {
        x = rand() % SIZE;
        y = rand() % SIZE;
        if (grid[x][y] == 0 && (x == top || grid[x - 1][y] == 1) && (y == left || grid[x][y - 1] == 1)) {
            grid[x][y] = 1;
            num_occupied++;
        }
    }
}

void print_grid() {
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
}

int main() {
    init_grid();
    for (int i = 0; i < SIZE; i++) {
        grid[i][0] = 1;
        grid[i][SIZE - 1] = 1;
    }
    for (int i = 0; i < SIZE; i++) {
        grid[0][i] = 1;
        grid[SIZE - 1][i] = 1;
    }
    percolate();
    print_grid();
    return 0;
}