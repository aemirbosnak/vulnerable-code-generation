//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int mandelbrot(double x, double y) {
    double real = 0, imag = 0;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4) {
        double temp_real = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp_real;
        iterations++;
    }

    return iterations;
}

void generate_fractal(double xmin, double xmax, double ymin, double ymax) {
    FILE *fp = fopen("fractal.ppm", "wb");

    if (fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double c_real = xmin + (xmax - xmin) * x / (WIDTH - 1);
            double c_imag = ymin + (ymax - ymin) * y / (HEIGHT - 1);
            int value = mandelbrot(c_real, c_imag);

            if (value == MAX_ITERATIONS) {
                fprintf(fp, "0 0 0\n");
            } else {
                int r = value % 8;
                int g = (value / 8) % 8;
                int b = (value / 64) % 8;
                fprintf(fp, "%d %d %d\n", r, g, b);
            }
        }
    }

    fclose(fp);
}

int main() {
    double xmin, xmax, ymin, ymax;

    printf("Enter the coordinates of the top-left corner: ");
    scanf("%lf %lf", &xmin, &ymin);

    printf("Enter the coordinates of the bottom-right corner: ");
    scanf("%lf %lf", &xmax, &ymax);

    generate_fractal(xmin, xmax, ymin, ymax);

    printf("Fractal generated successfully!\n");

    return 0;
}