//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Define the grid size
    int width = 10;
    int height = 10;

    // Create the grid
    int **grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }

    // Define the probability of percolation
    float p = 0.5;

    // Simulate percolation
    int num_percolated = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (rand() < p) {
                grid[i][j] = 1;
                if (i > 0 && grid[i - 1][j] == 1) {
                    num_percolated++;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    num_percolated++;
                }
            }
        }
    }

    // Print the result
    printf("Percolation simulator result:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("Number of percolated regions: %d\n", num_percolated);

    // Free memory
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}