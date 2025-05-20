//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 200
#define DELTA 0.01

int main() {
    int x, y, iterations;
    double real, imag;

    double **image = (double **)malloc(sizeof(double *) * HEIGHT);
    for (y = 0; y < HEIGHT; y++) {
        image[y] = (double *)malloc(sizeof(double) * WIDTH);
    }

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            real = (double)x / WIDTH * 3.5 - 2.5;
            imag = (double)y / HEIGHT * 2.5 - 1.5;

            iterations = 0;
            while (iterations < MAX_ITERATIONS && abs(real) + abs(imag) < 2) {
                double temp_real = real * real - imag * imag + (double)x / WIDTH * 3.5 - 2.5;
                double temp_imag = 2 * real * imag + (double)y / HEIGHT * 2.5 - 1.5;
                real = temp_real;
                imag = temp_imag;
                iterations++;
            }

            image[y][x] = iterations;
        }
    }

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%d ", image[y][x]);
        }
        printf("\n");
    }

    for (y = 0; y < HEIGHT; y++) {
        free(image[y]);
    }
    free(image);

    return 0;
}