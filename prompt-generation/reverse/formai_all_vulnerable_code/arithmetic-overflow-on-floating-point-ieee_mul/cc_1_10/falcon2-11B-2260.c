//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>
#include <math.h>

// Define constants
const int MAX_ITERATIONS = 100;
const float ITERATION_STEP = 0.5;

// Function to calculate the next iteration of the Mandelbrot set
float mandelbrot(float x, float y, int maxIterations) {
    // Calculate the absolute value of x and y, and square them
    float x2 = x * x;
    float y2 = y * y;

    // Initialize the number of iterations to 0
    int iterations = 0;

    // Loop until the absolute value of the complex number is greater than 2
    while (x2 + y2 < 4 && iterations < maxIterations) {
        // Calculate the next iteration of the complex number
        x = x2 - y * y;
        y = 2 * x * y + y2;

        // Increment the number of iterations
        iterations++;
    }

    // Return the number of iterations
    return iterations;
}

// Function to generate the Mandelbrot set
void generateMandelbrotSet(int xMin, int xMax, int yMin, int yMax, int maxIterations) {
    // Loop through the x-coordinates
    for (int x = xMin; x <= xMax; x++) {
        // Loop through the y-coordinates
        for (int y = yMin; y <= yMax; y++) {
            // Calculate the iterations for the current x and y coordinates
            int iterations = mandelbrot(x, y, maxIterations);

            // Print the result
            if (iterations == 0) {
                printf("(%d, %d) ", x, y);
            }
        }
    }
}

// Function to generate the Mandelbrot set with a black background
void generateMandelbrotSetBlack(int xMin, int xMax, int yMin, int yMax, int maxIterations) {
    // Loop through the x-coordinates
    for (int x = xMin; x <= xMax; x++) {
        // Loop through the y-coordinates
        for (int y = yMin; y <= yMax; y++) {
            // Calculate the iterations for the current x and y coordinates
            int iterations = mandelbrot(x, y, maxIterations);

            // Print the result
            if (iterations == 0) {
                printf("(%d, %d) ", x, y);
            } else {
                printf("(%d, %d) ", x, y);
            }
        }
    }
}

int main() {
    // Define the dimensions of the Mandelbrot set
    int xMin = -2.0;
    int xMax = 1.0;
    int yMin = -1.5;
    int yMax = 1.5;

    // Define the maximum number of iterations
    int maxIterations = MAX_ITERATIONS;

    // Generate the Mandelbrot set with a black background
    generateMandelbrotSetBlack(xMin, xMax, yMin, yMax, maxIterations);

    return 0;
}