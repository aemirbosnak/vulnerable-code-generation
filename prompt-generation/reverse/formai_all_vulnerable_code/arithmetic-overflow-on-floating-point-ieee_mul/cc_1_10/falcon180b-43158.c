//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

// Function to calculate the Mandelbrot set
int mandelbrot(double x, double y) {
    int iter = 0;
    double real = 0;
    double imag = 0;

    for (int i = 0; i < MAX_ITER && iter == 0; i++) {
        real = pow(real, 2) - pow(imag, 2) + x;
        imag = 2 * real * imag + y;

        if (pow(real, 2) + pow(imag, 2) > 4) {
            iter = i;
        }
    }

    return iter;
}

// Function to generate fractal image
void generate_fractal(double x_min, double x_max, double y_min, double y_max) {
    FILE *fp = fopen("fractal.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double c_real = x_min + (x_max - x_min) * x / (WIDTH - 1);
            double c_imag = y_min + (y_max - y_min) * y / (HEIGHT - 1);

            int value = mandelbrot(c_real, c_imag);

            if (value == MAX_ITER) {
                fprintf(fp, "0 0 0\n");
            } else {
                int r = value % 8;
                int g = (value / 8) % 8;
                int b = ((value / 64) % 8) * 16;

                fprintf(fp, "%d %d %d\n", r, g, b);
            }
        }
    }

    fclose(fp);
}

int main() {
    generate_fractal(-2, 1, -1.5, 1.5);

    return 0;
}