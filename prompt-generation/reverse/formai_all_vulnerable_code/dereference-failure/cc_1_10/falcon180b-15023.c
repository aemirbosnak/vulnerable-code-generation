//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

struct complex {
    double real;
    double imag;
};

void mandelbrot(int x, int y, int max_iterations, double *result) {
    struct complex z = {0, 0};
    struct complex c = {(double)x / WIDTH * 3.0 - 2.0, (double)y / HEIGHT * 2.0 - 1.0};
    int iterations = 0;

    while (iterations < max_iterations && z.real * z.real + z.imag * z.imag <= 4.0) {
        z.real = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        iterations++;
    }

    *result = iterations;
}

void generate_fractal(void) {
    FILE *output = fopen("fractal.ppm", "wb");

    if (output == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    fprintf(output, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    double *buffer = malloc(WIDTH * HEIGHT * sizeof(double));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            mandelbrot(x, y, MAX_ITERATIONS, &buffer[y * WIDTH + x]);
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double value = buffer[y * WIDTH + x] / MAX_ITERATIONS;
            fprintf(output, "%c%c%c", (int)(value * 255), (int)(value * 255), (int)(value * 255));
        }
    }

    fclose(output);
    free(buffer);
}

int main(void) {
    generate_fractal();

    return 0;
}