//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Define the number of iterations
    int niter = 1000;

    // Allocate memory for the grid
    int **grid = (int**)malloc(niter * sizeof(int*));
    for(int i = 0; i < niter; i++) {
        grid[i] = (int*)malloc(niter * sizeof(int));
    }

    // Initialize the grid
    for(int i = 0; i < niter; i++) {
        for(int j = 0; j < niter; j++) {
            grid[i][j] = 0;
        }
    }

    // Create the initial shape
    grid[10][10] = 1;
    grid[10][11] = 1;
    grid[10][12] = 1;
    grid[11][10] = 1;
    grid[11][11] = 1;
    grid[11][12] = 1;

    // Simulate the shape shifting
    for(int iter = 0; iter < niter; iter++) {

        // Calculate the gradient of each cell
        for(int i = 0; i < niter; i++) {
            for(int j = 0; j < niter; j++) {
                int sum = 0;
                if(i > 0) sum += grid[i-1][j];
                if(i < niter-1) sum += grid[i+1][j];
                if(j > 0) sum += grid[i][j-1];
                if(j < niter-1) sum += grid[i][j+1];
                grid[i][j] = sum / 4;
            }
        }

        // Smooth the shape
        for(int i = 0; i < niter; i++) {
            for(int j = 0; j < niter; j++) {
                grid[i][j] = (grid[i][j] > 1) ? 1 : grid[i][j];
            }
        }

        // Update the shape
        for(int i = 0; i < niter; i++) {
            for(int j = 0; j < niter; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 2;
                }
            }
        }
    }

    // Print the final shape
    for(int i = 0; i < niter; i++) {
        for(int j = 0; j < niter; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < niter; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}