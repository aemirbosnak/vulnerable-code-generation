//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 500
#define ESCAPE_TIME 2.0

int mandelbrot(int x, int y) {
    int iterations = 0;
    double real = (double)x / WIDTH * 3.5 - 2.5;
    double imag = (double)y / HEIGHT * 2.0 - 1.0;

    double real_squared = real * real;
    double imag_squared = imag * imag;

    while (iterations < MAX_ITERATIONS && real_squared + imag_squared <= 4.0) {
        double new_real = real_squared - imag_squared + real;
        double new_imag = 2.0 * real * imag + imag_squared;
        real = new_real;
        imag = new_imag;
        iterations++;
    }

    return iterations % 8;
}

void generate_mandelbrot(FILE *fp) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int color = mandelbrot(x, y);
            fprintf(fp, "%d ", color);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int seed;
    srand(time(NULL));
    seed = rand();

    fp = fopen("mandelbrot.ppm", "wb");
    if (fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    generate_mandelbrot(fp);

    fclose(fp);

    printf("Mandelbrot set saved as mandelbrot.ppm.\n");
    return 0;
}