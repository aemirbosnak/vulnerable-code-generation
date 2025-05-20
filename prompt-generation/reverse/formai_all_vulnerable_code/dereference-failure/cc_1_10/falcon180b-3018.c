//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ITERATIONS 1000000
#define POINTS 5000
#define WIDTH 800
#define HEIGHT 600

int mandelbrot_escape_time(double real, double imag, int max_iterations) {
    double zr = 0, zi = 0;
    int iterations = 0;

    while (iterations < max_iterations && (zr * zr + zi * zi) < 4) {
        double tr = zr * zr - zi * zi + real;
        zi = 2 * zr * zi + imag;
        zr = tr;
        iterations++;
    }

    return iterations;
}

void draw_mandelbrot(double xmin, double xmax, double ymin, double ymax, int width, int height, int max_iterations, FILE *fp) {
    double xscale = (xmax - xmin) / width;
    double yscale = (ymax - ymin) / height;

    for (int x = 0; x < width; x++) {
        double xreal = xmin + x * xscale;

        for (int y = 0; y < height; y++) {
            double yimag = ymin + y * yscale;

            int iterations = mandelbrot_escape_time(xreal, yimag, max_iterations);

            double color = (double)iterations / max_iterations;

            fprintf(fp, "%c%c%c", (int)(color * 255), (int)(color * 255), (int)(color * 255));
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <output_file> <max_iterations>\n", argv[0]);
        return 1;
    }

    char *output_file = argv[1];
    int max_iterations = atoi(argv[2]);

    FILE *fp = fopen(output_file, "wb");

    if (fp == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    double xmin, xmax, ymin, ymax;

    xmin = -2.0;
    xmax = 1.0;
    ymin = -1.5;
    ymax = 1.5;

    draw_mandelbrot(xmin, xmax, ymin, ymax, WIDTH, HEIGHT, max_iterations, fp);

    fclose(fp);

    return 0;
}