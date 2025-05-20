//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

int main() {

    // Define grid size
    int x_size = 128;
    int y_size = 64;

    // Allocate memory for grid
    double **grid = (double**)malloc(x_size * sizeof(double *) + y_size * sizeof(double));
    for (int i = 0; i < x_size; i++) {
        grid[i] = (double *)malloc(y_size * sizeof(double));
    }

    // Initialize grid with random values
    for (int i = 0; i < x_size; i++) {
        for (int j = 0; j < y_size; j++) {
            grid[i][j] = rand() % MAX;
        }
    }

    // Calculate wind direction and speed
    int wind_direction = rand() % 4;
    int wind_speed = rand() % 10;

    // Simulate weather patterns
    switch (wind_direction) {
        case 0:
            // East-West wind
            for (int i = 0; i < x_size; i++) {
                for (int j = 0; j < y_size; j++) {
                    grid[i][j] += wind_speed * 0.25;
                }
            }
            break;
        case 1:
            // North-South wind
            for (int i = 0; i < x_size; i++) {
                for (int j = 0; j < y_size; j++) {
                    grid[i][j] += wind_speed * 0.25;
                }
            }
            break;
        case 2:
            // South-East wind
            for (int i = 0; i < x_size; i++) {
                for (int j = 0; j < y_size; j++) {
                    grid[i][j] += wind_speed * 0.25;
                }
            }
            break;
        case 3:
            // South-West wind
            for (int i = 0; i < x_size; i++) {
                for (int j = 0; j < y_size; j++) {
                    grid[i][j] += wind_speed * 0.25;
                }
            }
            break;
    }

    // Display the grid
    for (int i = 0; i < x_size; i++) {
        for (int j = 0; j < y_size; j++) {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < x_size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}