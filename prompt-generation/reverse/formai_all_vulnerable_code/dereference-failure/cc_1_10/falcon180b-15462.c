//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the fractal function
int fractal(int x, int y) {
    int n = 0;
    int real = 0;
    int imag = 0;

    // Iterate through the fractal formula
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        real = real * real + imag * imag;
        imag = 2 * real * imag + 1;
        if (real * real + imag * imag > 4) {
            n = i;
            break;
        }
    }

    // Return the number of iterations required to escape the fractal
    return n;
}

// Define the main function
int main() {
    int width = 800;
    int height = 600;
    int x, y;
    int max_iterations = MAX_ITERATIONS;

    // Create a new image
    int *image = (int *)malloc(width * height * sizeof(int));

    // Iterate through the pixels of the image
    for (int i = 0; i < width * height; i++) {
        x = i % width;
        y = i / width;

        // Calculate the fractal value for this pixel
        int fractal_value = fractal(x, y);

        // Map the fractal value to a color
        int color = fractal_value % 8;

        // Set the pixel color
        image[i] = color;
    }

    // Save the image to a file
    FILE *file = fopen("fractal.bmp", "wb");
    fwrite(image, sizeof(int), width * height, file);
    fclose(file);

    // Free the image memory
    free(image);

    return 0;
}