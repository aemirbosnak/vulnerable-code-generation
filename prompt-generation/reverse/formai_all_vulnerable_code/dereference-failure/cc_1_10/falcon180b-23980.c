//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define COLOR_SCALE 3

int main() {
    srand(time(NULL));

    int width = WIDTH;
    int height = HEIGHT;
    int max_iterations = MAX_ITERATIONS;

    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;

    double xscale = (xmax - xmin) / width;
    double yscale = (ymax - ymin) / height;

    int *pixels = calloc(width * height, sizeof(int));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double cx = xmin + x * xscale;
            double cy = ymin + y * yscale;

            int color = 0;
            for (int i = 0; i < max_iterations; i++) {
                double zx = cx;
                double zy = cy;

                if (zx * zx + zy * zy > 4.0) {
                    break;
                }

                double zx_new = zx * zx - zy * zy + cx;
                double zy_new = 2 * zx * zy + cy;

                cx = zx_new;
                cy = zy_new;

                color++;
            }

            pixels[(y * width) + x] = color % 8 * COLOR_SCALE;
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", pixels[(y * width) + x]);
        }
        printf("\n");
    }

    free(pixels);

    return 0;
}