//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int width = 10;
    int height = 10;
    int num_of_iterations = 100;
    int **grid = NULL;
    int top = 0;
    int bottom = height - 1;
    int left = 0;
    int right = width - 1;
    int count = 0;
    int choice = 0;

    grid = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        grid[i] = (int *)malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }

    for (int i = 0; i < num_of_iterations; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (grid[j][k] == 1) {
                    if (j > 0 && grid[j - 1][k] == 0) {
                        grid[j - 1][k] = 1;
                        count++;
                    }
                    if (j < height - 1 && grid[j + 1][k] == 0) {
                        grid[j + 1][k] = 1;
                        count++;
                    }
                    if (k > 0 && grid[j][k - 1] == 0) {
                        grid[j][k - 1] = 1;
                        count++;
                    }
                    if (k < width - 1 && grid[j][k + 1] == 0) {
                        grid[j][k + 1] = 1;
                        count++;
                    }
                }
            }
        }
        printf("Iteration %d: %d sites occupied\n", i + 1, count);
        count = 0;
    }

    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}