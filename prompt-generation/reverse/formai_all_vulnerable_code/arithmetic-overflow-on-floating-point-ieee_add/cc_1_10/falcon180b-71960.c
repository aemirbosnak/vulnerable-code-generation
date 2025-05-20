//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

typedef struct {
    double x, y;
} Point;

void mandelbrot(int x, int y, int max_iterations, double xmin, double xmax, double ymin, double ymax) {
    int iterations = 0;
    double real = xmin + (xmax - xmin) * x / WIDTH;
    double imag = ymin + (ymax - ymin) * y / HEIGHT;
    double temp_real, temp_imag;

    while (iterations < max_iterations && temp_real * temp_real + temp_imag * temp_imag < 4) {
        temp_real = real * real - imag * imag + xmin;
        temp_imag = 2 * real * imag + ymin;
        real = temp_real;
        imag = temp_imag;
        iterations++;
    }

    if (iterations == max_iterations) {
        printf("Black\n");
    } else {
        printf("%d\n", iterations);
    }
}

int main() {
    FILE *fp = fopen("mandelbrot.ppm", "wb");

    if (!fp) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            mandelbrot(x, y, MAX_ITERATIONS, -2.0, 1.0, -1.5, 1.5);
        }
    }

    fclose(fp);
    return 0;
}