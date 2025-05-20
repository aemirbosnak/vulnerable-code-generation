//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int mandelbrot(double x, double y) {
    int iterations = 0;
    double real = 0, imag = 0;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        real = real * real - imag * imag + x;
        imag = 2 * real * imag + y;

        if (real * real + imag * imag > 4) {
            return iterations;
        }

        iterations++;
    }

    return iterations;
}

void generate_mandelbrot(double xmin, double xmax, double ymin, double ymax) {
    double x, y, dx, dy;
    int iterations;

    for (y = ymax; y >= ymin; y -= dy) {
        for (x = xmin; x <= xmax; x += dx) {
            iterations = mandelbrot(x, y);

            if (iterations == MAX_ITERATIONS) {
                printf(" ");
            } else {
                printf("%02d ", iterations);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    double xmin = -2, xmax = 1, ymin = -1.5, ymax = 1.5;
    double dx = (xmax - xmin) / WIDTH, dy = (ymax - ymin) / HEIGHT;

    generate_mandelbrot(xmin, xmax, ymin, ymax);

    return 0;
}