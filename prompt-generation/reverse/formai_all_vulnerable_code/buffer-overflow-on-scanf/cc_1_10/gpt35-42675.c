//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define THRESHOLD 0.6

int grid[MAX_SIZE][MAX_SIZE];
int size;
int visited[MAX_SIZE][MAX_SIZE];

void initializeGrid() {
    int i, j;
    double random;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            random = (double) rand()/ RAND_MAX;
            if (random > THRESHOLD) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
            visited[i][j] = 0;
        }
    }
}

int isOpen(int row, int col) {
    return grid[row][col] == 1;
}

int isFull(int row, int col) {
    if (row >= size || row < 0 || col >= size || col < 0) {
        return 0;
    }
    if (visited[row][col] == 1) {
        return 0;
    }
    visited[row][col] = 1;
    if (!isOpen(row, col)) {
        return 0;
    }
    if (row == 0) {
        return 1;
    }
    return isFull(row-1, col) || isFull(row+1, col) || isFull(row, col-1) || isFull(row, col+1);
}

int percolates() {
    int i;
    for (i=0; i<size; i++) {
        if (isFull(size-1, i)) {
            return 1;
        }
    }
    return 0;
}

void printGrid() {
    int i, j;
    printf("Printing grid: \n");
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            if (grid[i][j] == 1) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void simulatePercolation() {
    initializeGrid();
    if (percolates()) {
        printf("Percolation achieved!\n");
    } else {
        printf("Percolation not achieved!\n");
    }
}

int main() {
    srand(time(NULL));
    printf("Enter the size of the grid: ");
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        printf("Maximum size exceeded. Please enter a size <= %d\n", MAX_SIZE);
        return 0;
    }
    printGrid();
    simulatePercolation();
    return 0;
}