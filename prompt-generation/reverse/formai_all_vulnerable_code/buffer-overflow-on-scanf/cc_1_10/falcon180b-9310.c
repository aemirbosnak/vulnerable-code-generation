//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

// Define the complex number data type
typedef struct {
    double real;
    double imag;
} Complex;

// Define the Mandelbrot set fractal generation function
void mandelbrot_fractal(double xmin, double xmax, double ymin, double ymax, int width, int height) {
    // Define the complex plane
    Complex plane[width][height];

    // Initialize the complex plane with zeros
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            plane[i][j].real = xmin + (xmax - xmin) * i / (width - 1);
            plane[i][j].imag = ymin + (ymax - ymin) * j / (height - 1);
        }
    }

    // Generate the fractal
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Complex z = plane[i][j];
            Complex c = {0, 0};
            int iterations = 0;

            while (iterations < MAX_ITERATIONS && abs(z.real) + abs(z.imag) > 2) {
                Complex temp = {z.real * z.real - z.imag * z.imag + c.real, 2 * z.real * z.imag + c.imag};
                z = temp;
                c = z;
                iterations++;
            }

            // Color the pixel based on the number of iterations
            if (iterations == MAX_ITERATIONS) {
                printf(" ");
            } else {
                int color = (int) (255 * iterations / MAX_ITERATIONS);
                printf("%c", (color % 6) + '0');
            }
        }
        printf("\n");
    }
}

int main() {
    double xmin, xmax, ymin, ymax;
    int width, height;

    // Get user input for fractal parameters
    printf("Enter the minimum and maximum x values: ");
    scanf("%lf %lf", &xmin, &xmax);
    printf("Enter the minimum and maximum y values: ");
    scanf("%lf %lf", &ymin, &ymax);
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    // Generate the fractal
    mandelbrot_fractal(xmin, xmax, ymin, ymax, width, height);

    return 0;
}