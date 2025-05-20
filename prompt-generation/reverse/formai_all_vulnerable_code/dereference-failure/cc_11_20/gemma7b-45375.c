//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main() {
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++) {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    int x, y, n, k;
    scanf("Enter the number of iterations: ", &n);
    for (int t = 0; t < n; t++) {
        scanf("Enter the location of the drop (x, y): ", &x, &y);
        scanf("Enter the number of drops: ", &k);
        for (int i = 0; i < k; i++) {
            grid[x][y] = 1;
        }
    }

    // Check if the grid is saturated
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("The grid is saturated.\n");
                return 0;
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}