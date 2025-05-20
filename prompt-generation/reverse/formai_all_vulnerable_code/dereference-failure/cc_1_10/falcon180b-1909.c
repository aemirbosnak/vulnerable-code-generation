//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

// Function to calculate the Mandelbrot set
int mandelbrot(double x, double y) {
    double real = 0, imag = 0;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4) {
        double temp = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp;
        iterations++;
    }

    return iterations;
}

int main() {
    int i, j;
    double x, y, dx, dy;
    FILE *fp;
    time_t start, end;

    // Initialize the image
    double *image = (double *)malloc(WIDTH * HEIGHT * sizeof(double));
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = 0;
    }

    // Generate the fractal
    start = time(NULL);
    for (i = 0; i < HEIGHT; i++) {
        y = (double)i / HEIGHT * 3.5 - 2.5;
        for (j = 0; j < WIDTH; j++) {
            x = (double)j / WIDTH * 2 - 1;
            dx = (double)WIDTH / HEIGHT * 3.5 / (double)HEIGHT;
            dy = (double)HEIGHT / WIDTH * 2 / (double)WIDTH;
            image[i * WIDTH + j] = mandelbrot(x, y) / MAX_ITERATIONS;
        }
    }
    end = time(NULL);

    // Save the image to a file
    fp = fopen("mandelbrot.pgm", "wb");
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp, "%d ", (int)(255 * image[i * WIDTH + j]));
        }
    }

    fclose(fp);

    printf("Fractal generated in %ld seconds.\n", end - start);

    return 0;
}