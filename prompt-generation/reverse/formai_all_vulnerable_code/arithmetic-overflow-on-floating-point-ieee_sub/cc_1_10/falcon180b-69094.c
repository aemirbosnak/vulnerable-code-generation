//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
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
        printf("Error: could not create output file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        double yc = (ymax - ymin) * y / (HEIGHT - 1) + ymin;
        for (int x = 0; x < WIDTH; x++) {
            double xc = (xmax - xmin) * x / (WIDTH - 1) + xmin;
            int value = mandelbrot(xc, yc);
            fprintf(fp, "%c%c%c", value % 8 + 48, value % 16 + 48, value % 32 + 48);
        }
    }

    fclose(fp);
}

int main() {
    double xmin, xmax, ymin, ymax;
    printf("Enter the coordinates of the rectangular region to generate the fractal for:\n");
    printf("Xmin: ");
    scanf("%lf", &xmin);
    printf("Xmax: ");
    scanf("%lf", &xmax);
    printf("Ymin: ");
    scanf("%lf", &ymin);
    printf("Ymax: ");
    scanf("%lf", &ymax);

    generate_fractal(xmin, xmax, ymin, ymax);

    printf("Fractal generated successfully and saved as fractal.ppm.\n");

    return 0;
}