//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITERATIONS 1000
#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR 255
#define ZOOM 1.1

int mandelbrot(double real, double imag, int iterations) {
    double cr = real;
    double ci = imag;
    int count = 0;

    for (int i = 0; i < iterations; i++) {
        double zr = cr * cr - ci * ci + real;
        double zi = 2 * cr * ci + imag;
        cr = zr;
        ci = zi;

        if (cr * cr + ci * ci > 4) {
            count++;
        }
    }

    return count;
}

void generate_fractal(double xmin, double xmax, double ymin, double ymax, int width, int height, int max_color, int iterations) {
    FILE *fp = fopen("fractal.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", width, height, max_color);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = (xmin + (x * (xmax - xmin) / (width - 1))) / ZOOM;
            double imag = (ymin + (y * (ymax - ymin) / (height - 1))) / ZOOM;

            int color = mandelbrot(real, imag, iterations);

            fprintf(fp, "%d ", color);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;
    int width = WIDTH;
    int height = HEIGHT;
    int max_color = MAX_COLOR;
    int iterations = MAX_ITERATIONS;

    generate_fractal(xmin, xmax, ymin, ymax, width, height, max_color, iterations);

    return 0;
}