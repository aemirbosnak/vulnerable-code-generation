//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define a maximum number of iterations for the fractal generation
#define MAX_ITERATIONS 1000

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user to enter the number of fractals to generate
    int numFractals;
    printf("Enter the number of fractals to generate: ");
    scanf("%d", &numFractals);

    // Loop through the number of fractals the user wants to generate
    for (int i = 0; i < numFractals; i++) {
        // Generate a random fractal type
        int fractalType = rand() % 4;

        // Generate a random maximum iteration count
        int maxIterations = rand() % MAX_ITERATIONS + 1;

        // Generate a random center point for the fractal
        double xCenter = rand() % 400 - 200;
        double yCenter = rand() % 400 - 200;

        // Generate a random scale factor for the fractal
        double scale = pow(10.0, rand() % 4);

        // Generate a random rotation angle for the fractal
        double rotation = rand() % 360;

        // Calculate the number of iterations required to generate the fractal
        int iterations = 0;
        double x = 0.0;
        double y = 0.0;
        double real = xCenter;
        double imag = yCenter;
        while (iterations < maxIterations && abs(x) + abs(y) < 2.0) {
            double temp = x * x - y * y + real;
            y = 2.0 * x * y + imag;
            x = temp;
            iterations++;
        }

        // Print the fractal to the console
        printf("Fractal %d:\n", i + 1);
        printf("Type: ");
        switch (fractalType) {
            case 0:
                printf("Mandelbrot\n");
                break;
            case 1:
                printf("Julia\n");
                break;
            case 2:
                printf("Barnsley\n");
                break;
            case 3:
                printf("Koch\n");
                break;
        }
        printf("Max Iterations: %d\n", maxIterations);
        printf("Center: (%f, %f)\n", xCenter, yCenter);
        printf("Scale: %f\n", scale);
        printf("Rotation: %f degrees\n", rotation);
        printf("Iterations: %d\n", iterations);
        printf("\n");
    }

    return 0;
}