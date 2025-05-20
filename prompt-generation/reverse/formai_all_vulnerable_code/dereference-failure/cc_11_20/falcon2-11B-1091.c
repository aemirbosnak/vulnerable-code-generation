//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void percolationSimulator(int width, int height, float porosity) {
    // Initialize a 2D array to represent the porous medium
    int** medium = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        medium[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            medium[i][j] = 0;
        }
    }

    // Initialize the porosity of the medium
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                medium[i][j] = 1;
            } else {
                medium[i][j] = (rand() / (float)RAND_MAX <= porosity)? 1 : 0;
            }
        }
    }

    int num_open_sites = 0;
    int num_sites = width * height;
    int num_neighbors = 0;
    int num_open_neighbors = 0;
    int num_active_neighbors = 0;
    int num_open_active_neighbors = 0;

    while (num_open_sites < num_sites) {
        // Choose a random site
        int x = rand() % width;
        int y = rand() % height;

        // Check if the site is already open
        if (medium[y][x] == 0) {
            // Mark the site as open
            medium[y][x] = 1;

            // Count the number of open neighbors
            for (int i = y - 1; i <= y + 1; i++) {
                for (int j = x - 1; j <= x + 1; j++) {
                    if (i >= 0 && i < height && j >= 0 && j < width && medium[i][j] == 1) {
                        num_open_neighbors++;
                    }
                }
            }

            // Check if the site is active
            if (num_open_neighbors >= 4) {
                num_active_neighbors++;
            }

            // Check if the site is active and has an open neighbor
            if (num_active_neighbors > 0 && num_open_active_neighbors < num_active_neighbors) {
                num_open_active_neighbors++;
            }

            // Update the number of open sites and neighbors
            num_open_sites++;
            num_neighbors += num_open_neighbors;
            num_open_neighbors = 0;
            num_active_neighbors = 0;
        }
    }

    // Free the memory allocated for the medium
    for (int i = 0; i < height; i++) {
        free(medium[i]);
    }
    free(medium);

    printf("Percolation Simulation Results:\n");
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Porosity: %f\n", porosity);
    printf("Number of Open Sites: %d\n", num_open_sites);
    printf("Number of Neighbors: %d\n", num_neighbors);
    printf("Number of Open Neighbors: %d\n", num_open_neighbors);
    printf("Number of Active Neighbors: %d\n", num_active_neighbors);
    printf("Number of Open Active Neighbors: %d\n", num_open_active_neighbors);
}

int main() {
    srand(time(0));
    int width = 20;
    int height = 20;
    float porosity = 0.5;

    percolationSimulator(width, height, porosity);

    return 0;
}