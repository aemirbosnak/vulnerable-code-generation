//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the fractal function
int fractal(int x, int y, int iterations) {
    // Calculate the real and imaginary parts of the current point
    double real = 0.0;
    double imaginary = 0.0;

    for (int i = 0; i < iterations; i++) {
        // Calculate the new real and imaginary parts
        double newReal = real * real - imaginary * imaginary + x;
        imaginary = 2.0 * real * imaginary + y;
        real = newReal;
    }

    // Check if the point is in the fractal set
    if (real * real + imaginary * imaginary > 4.0) {
        return 1;
    } else {
        return 0;
    }
}

// Define the main function
int main() {
    // Define the size of the fractal image
    int width = 800;
    int height = 600;

    // Allocate memory for the fractal image
    int **image = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = (int *) malloc(width * sizeof(int));
    }

    // Generate the fractal image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = (double) j / width * 3.0 - 2.0;
            int y = (double) i / height * 2.0 - 1.0;

            int value = fractal(x, y, MAX_ITERATIONS);

            if (value == 1) {
                image[i][j] = 255;
            } else {
                image[i][j] = 0;
            }
        }
    }

    // Save the fractal image to a file
    FILE *fp = fopen("fractal.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(&image[0][0], sizeof(int), width * height, fp);

    fclose(fp);

    // Free the memory allocated for the fractal image
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}