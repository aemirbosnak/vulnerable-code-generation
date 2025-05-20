//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

int mandelbrot(double real, double imag) {
    double zr = 0, zi = 0;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && (zr * zr + zi * zi) < 4) {
        double tmp = zr * zr - zi * zi + real;
        zi = 2 * zr * zi + imag;
        zr = tmp;
        iterations++;
    }

    return iterations;
}

void generate_fractal(double xmin, double xmax, double ymin, double ymax) {
    FILE *fp = fopen("fractal.ppm", "wb");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    double xscale = (xmax - xmin) / WIDTH;
    double yscale = (ymax - ymin) / HEIGHT;

    for (int x = 0; x < WIDTH; x++) {
        double real = xmin + x * xscale;
        for (int y = 0; y < HEIGHT; y++) {
            double imag = ymin + y * yscale;
            int iterations = mandelbrot(real, imag);

            double r = (double)iterations / MAX_ITERATIONS;
            double g = r;
            double b = r;

            fprintf(fp, "%c%c%c", (int)(r * 255), (int)(g * 255), (int)(b * 255));
        }
    }

    fclose(fp);
}

int main() {
    double xmin, xmax, ymin, ymax;

    printf("Enter the boundaries of the fractal (in the format xmin,xmax,ymin,ymax): ");
    scanf("%lf,%lf,%lf,%lf", &xmin, &xmax, &ymin, &ymax);

    generate_fractal(xmin, xmax, ymin, ymax);

    printf("Fractal generated successfully!\n");

    return 0;
}