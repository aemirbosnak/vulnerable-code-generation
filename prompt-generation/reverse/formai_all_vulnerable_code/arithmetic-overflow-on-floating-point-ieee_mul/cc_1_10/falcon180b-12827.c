//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate fractal
void generateFractal(int x, int y, double size, int maxIterations) {
    int iterations;
    double real, imaginary;

    // Initialize complex numbers
    real = x * size;
    imaginary = y * size;

    // Iterate through each point in the fractal
    for (iterations = 0; iterations < maxIterations; iterations++) {
        // Calculate the new real and imaginary values
        real = real * real - imaginary * imaginary + x;
        imaginary = 2 * real * imaginary + y;

        // Check if the point is in the fractal
        if (real * real + imaginary * imaginary > 4) {
            // If the point is in the fractal, color it
            printf("*");
        } else {
            // If the point is not in the fractal, skip it
            printf(" ");
        }
    }
}

// Main function
int main() {
    int x, y, maxIterations;
    double size;

    // Get user input
    printf("Enter the size of the fractal: ");
    scanf("%lf", &size);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Loop through each point in the fractal
    for (x = -2 * size; x < 2 * size; x++) {
        for (y = -2 * size; y < 2 * size; y++) {
            // Call the generateFractal function for each point
            generateFractal(x, y, size, maxIterations);
        }
        // Move to the next line
        printf("\n");
    }

    return 0;
}