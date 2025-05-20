//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define THRESHOLD 4.0

// Function to calculate the Mandelbrot value at a given point
float mandelbrot(float x, float y) {
    float zx = 0, zy = 0, n = 0;
    while (n < MAX_ITER && (zx * zx + zy * zy) < THRESHOLD) {
        float zx_new = zx * zx - zy * zy + x;
        zy = 2 * zx * zy + y;
        zx = zx_new;
        n++;
    }
    return n;
}

// Function to generate the fractal image
void generate_fractal(int width, int height, float xmin, float ymin, float xmax, float ymax, float scale) {
    FILE *fp = fopen("fractal.ppm", "wb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", width, height, 255);

    float xstep = (xmax - xmin) / width;
    float ystep = (ymax - ymin) / height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float x = xmin + j * xstep;
            float y = ymin + i * ystep;
            float value = mandelbrot(x, y) / MAX_ITER * 255;
            fprintf(fp, "%c%c%c", value, value, value);
        }
    }

    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 7) {
        printf("Usage: %s <width> <height> <xmin> <ymin> <xmax> <ymax>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    float xmin = atof(argv[3]);
    float ymin = atof(argv[4]);
    float xmax = atof(argv[5]);
    float ymax = atof(argv[6]);

    float scale = (xmax - xmin) / (float)width;

    generate_fractal(width, height, xmin, ymin, xmax, ymax, scale);

    return 0;
}