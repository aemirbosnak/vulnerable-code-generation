//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

void generateMandelbrot(int maxIterations) {
    double xmin = -2.0, xmax = 1.0;
    double ymin = -1.0, ymax = 1.0;
    double xFactor = (xmax - xmin) / WIDTH;
    double yFactor = (ymax - ymin) / HEIGHT;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cr = xmin + x * xFactor;
            double ci = ymin + y * yFactor;
            double zr = 0.0, zi = 0.0;
            int iterations = 0;

            while (zr * zr + zi * zi <= 4.0 && iterations < maxIterations) {
                double temp = zr * zr - zi * zi + cr;
                zi = 2 * zr * zi + ci;
                zr = temp;
                iterations++;
            }

            if (iterations == maxIterations) {
                printf("#"); // the point is in the set
            } else {
                printf(" "); // the point is not in the set
            }
        }
        printf("\n"); // move to the next line after each row
    }
}

int main() {
    int maxIterations;

    printf("Welcome to the Mandelbrot Set Generator!\n");
    printf("Enter the maximum number of iterations (recommended: 50-100): ");
    scanf("%d", &maxIterations);

    // Clear the screen
    printf("\033[H\033[J");

    printf("Generating Mandelbrot Set...\n");
    generateMandelbrot(maxIterations);

    printf("Finished! Enjoy the fractal artwork!\n");
    return 0;
}