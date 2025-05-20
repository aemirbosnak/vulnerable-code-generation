//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847563439444886874714403884183493463262208

int main() {
    // Create a 2D array to represent the physical simulation
    float* matrix = malloc(sizeof(float) * 100 * 100);

    // Initialize the matrix with random values
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            matrix[i * 100 + j] = (float)rand() / RAND_MAX;
        }
    }

    // Run the simulation for 10 time steps
    for (int i = 0; i < 10; i++) {
        // Update each element in the matrix based on its neighbors
        for (int x = 1; x < 99; x++) {
            for (int y = 1; y < 99; y++) {
                int neighbors = 0;

                if (x > 0) {
                    neighbors += matrix[i * 100 + y * 100 + (x - 1) * 100];
                }
                if (x < 99) {
                    neighbors += matrix[i * 100 + y * 100 + (x + 1) * 100];
                }
                if (y > 0) {
                    neighbors += matrix[i * 100 + (y - 1) * 100 + x * 100];
                }
                if (y < 99) {
                    neighbors += matrix[i * 100 + (y + 1) * 100 + x * 100];
                }

                float newValue = (1 - 0.01 * i) * matrix[i * 100 + y * 100 + x * 100] + 0.01 * i * (neighbors / 4);
                matrix[i * 100 + y * 100 + x * 100] = newValue;
            }
        }
    }

    // Print the final state of the matrix
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%8.3f ", matrix[i * 100 + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(matrix);

    return 0;
}