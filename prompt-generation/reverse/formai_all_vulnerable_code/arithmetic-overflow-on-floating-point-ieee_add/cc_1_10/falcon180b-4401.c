//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate fractal image
void fractal(int width, int height, int max_iterations, double xmin, double xmax, double ymin, double ymax) {
    double x, y, real, imag, temp;
    int i, j, iterations;
    FILE *fp;

    // Open output file
    fp = fopen("fractal.pgm", "wb");

    // Write header
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, 255);

    // Iterate over each pixel
    for (j = height - 1; j >= 0; j--) {
        for (i = 0; i < width; i++) {
            // Map pixel coordinates to complex plane
            x = (xmin + (xmax - xmin) * i / width) / (ymax - ymin);
            y = (ymin + (ymax - ymin) * j / height) / (ymax - ymin);

            // Initialize complex number
            real = 0;
            imag = 0;

            // Iterate until maximum iterations reached or escape condition met
            for (iterations = 0; iterations < max_iterations; iterations++) {
                temp = pow(real, 2) + pow(imag, 2);
                if (temp > 4) {
                    break;
                }
                real = real * real - imag * imag + x;
                imag = 2 * real * imag + y;
            }

            // Write pixel value to output file
            fprintf(fp, "%d ", iterations % 8);
        }
    }

    // Close output file
    fclose(fp);
}

int main() {
    int width, height, max_iterations;
    double xmin, xmax, ymin, ymax;

    // Get user input
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iterations);
    printf("Enter xmin: ");
    scanf("%lf", &xmin);
    printf("Enter xmax: ");
    scanf("%lf", &xmax);
    printf("Enter ymin: ");
    scanf("%lf", &ymin);
    printf("Enter ymax: ");
    scanf("%lf", &ymax);

    // Generate fractal image
    fractal(width, height, max_iterations, xmin, xmax, ymin, ymax);

    return 0;
}