//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int width = 800;
    int height = 800;
    int maxIterations = 1000;
    double zoom = 1.0;
    double xOffset = 0.0;
    double yOffset = 0.0;

    if (argc > 1) {
        maxIterations = atoi(argv[1]);
    }

    if (argc > 2) {
        zoom = atof(argv[2]);
    }

    if (argc > 3) {
        xOffset = atof(argv[3]);
    }

    if (argc > 4) {
        yOffset = atof(argv[4]);
    }

    int **pixels = (int **) malloc(height * sizeof(int *));
    pixels[0] = (int *) malloc(width * height * sizeof(int));
    for (int i = 1; i < height; i++) {
        pixels[i] = pixels[0] + i * width;
    }

    double x, y;
    double zx, zy, zx2, zy2;
    int i, j, iter;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            x = (j - width / 2.0) / (0.5 * zoom * width) + xOffset;
            y = (i - height / 2.0) / (0.5 * zoom * height) + yOffset;

            zx = 0.0;
            zy = 0.0;
            zx2 = 0.0;
            zy2 = 0.0;

            for (iter = 0; iter < maxIterations && zx2 + zy2 < 4.0; iter++) {
                zy = 2.0 * zx * zy + y;
                zx = zx2 - zy2 + x;

                zx2 = zx * zx;
                zy2 = zy * zy;
            }

            if (iter == maxIterations) {
                pixels[i][j] = 0;
            } else {
                pixels[i][j] = 255 * iter / maxIterations;
            }
        }
    }

    FILE *fp;
    fp = fopen("mandelbrot.pgm", "wb");
    fprintf(fp, "P2\n%d %d\n255\n", width, height);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%d ", pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    free(pixels[0]);
    free(pixels);

    return 0;
}