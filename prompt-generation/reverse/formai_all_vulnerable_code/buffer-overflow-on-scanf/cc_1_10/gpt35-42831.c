//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

int size;
bool grid[MAX][MAX], visited[MAX][MAX];

bool is_percolated(int row, int col) {
    if (row < 0 || row >= size || col < 0 || col >= size || !grid[row][col] || visited[row][col])
        return false;
    if (row == size-1)
        return true;
    visited[row][col] = true;
    return (is_percolated(row+1, col) || is_percolated(row-1, col) || is_percolated(row, col+1) || is_percolated(row, col-1));
}

int main() {
    printf("Enter the size of grid (max 50): ");
    scanf("%d", &size);

    // Initializing grid with random values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = (rand()%2 == 0);
            visited[i][j] = false;
        }
    }

    // Printing the grid
    printf("Initial grid:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Checking if the grid percolates
    bool is_percolating = false;
    for (int j = 0; j < size; j++) {
        if (is_percolated(0, j)) {
            is_percolating = true;
            break;
        }
    }

    // Printing the result
    if (is_percolating)
        printf("The grid percolates!\n");
    else
        printf("The grid does not percolate.\n");

    return 0;
}