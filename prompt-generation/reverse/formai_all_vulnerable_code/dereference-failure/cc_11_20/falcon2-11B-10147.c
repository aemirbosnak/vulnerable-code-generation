//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up random seed
    srand(time(0));

    // Define array size
    int size = 1000;

    // Initialize array with 0s
    int *array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }

    // Define percolation parameters
    int numNeighbors = 8;
    double percolationProbability = 0.01;

    // Percolate array
    for (int i = 0; i < size; i++) {
        // Choose a random neighbor
        int neighbor = rand() % size;

        // If neighbor is occupied and not connected, flip it
        if (array[neighbor] == 1 && array[neighbor]!= i) {
            array[i] = 1;
        }

        // If neighbor is not occupied, flip it
        if (array[neighbor] == 0) {
            array[i] = 1;
        }
    }

    // Count connected components
    int numComponents = 0;
    for (int i = 0; i < size; i++) {
        int component = 1;
        for (int j = 0; j < size; j++) {
            if (array[j] == i) {
                component = 0;
            }
        }
        if (component == 1) {
            numComponents++;
        }
    }

    // Calculate critical percolation probability
    double criticalProbability = 0;
    while (criticalProbability <= 0 || criticalProbability >= 1) {
        criticalProbability = 0.5 * (numComponents + 1) / numComponents;
    }

    // Print results
    printf("Number of components: %d\n", numComponents);
    printf("Critical percolation probability: %.4f\n", criticalProbability);

    // Free memory
    free(array);

    return 0;
}