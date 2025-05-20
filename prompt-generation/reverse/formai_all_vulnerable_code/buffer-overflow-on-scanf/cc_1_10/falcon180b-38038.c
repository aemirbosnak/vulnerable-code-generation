//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate fractal image
void generateFractal(int width, int height, double xMin, double xMax, double yMin, double yMax, int maxIterations, FILE *fp) {
    int iter;
    double x, y;

    // Loop through each pixel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Map pixel coordinates to complex plane
            x = xMin + (xMax - xMin) * j / (double)width;
            y = yMin + (yMax - yMin) * i / (double)height;

            // Initialize complex number
            double real = x;
            double imag = y;

            // Iterate through the fractal function
            for (iter = 0; iter < maxIterations; iter++) {
                double tempReal = real * real - imag * imag + xMin;
                imag = 2 * real * imag + yMin;
                real = tempReal;

                if (real * real + imag * imag > 4) {
                    break;
                }
            }

            // Map color to iteration count
            int color = iter % 8;

            // Write pixel value to file
            fprintf(fp, "%c", color + '0');
        }
        fprintf(fp, "\n");
    }
}

int main() {
    int width, height;
    double xMin, xMax, yMin, yMax;
    int maxIterations;

    // Get user input for fractal parameters
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the minimum x value: ");
    scanf("%lf", &xMin);
    printf("Enter the maximum x value: ");
    scanf("%lf", &xMax);
    printf("Enter the minimum y value: ");
    scanf("%lf", &yMin);
    printf("Enter the maximum y value: ");
    scanf("%lf", &yMax);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Open output file
    FILE *fp = fopen("fractal.bmp", "wb");

    // Generate fractal image
    generateFractal(width, height, xMin, xMax, yMin, yMax, maxIterations, fp);

    // Close output file
    fclose(fp);

    return 0;
}