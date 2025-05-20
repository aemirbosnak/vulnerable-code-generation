//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define ESCAPE_TIME 4.0

void draw_fractal(int x, int y, int width, int height, int max_iterations, double escape_time) {
    int i, j;
    double c_real, c_imag, z_real, z_imag;
    int iterations;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            c_real = (double)j / width * 3.0 - 2.0;
            c_imag = (double)i / height * 2.0 - 1.0;

            z_real = 0;
            z_imag = 0;

            iterations = 0;

            while (iterations < max_iterations && z_real * z_real + z_imag * z_imag < escape_time) {
                z_real = z_real * z_real - z_imag * z_imag + c_real;
                z_imag = 2 * z_real * z_imag + c_imag;

                iterations++;
            }

            if (iterations >= max_iterations) {
                printf("%.6f,%.6f\n", c_real, c_imag);
            }
        }
    }
}

int main() {
    int width, height;

    printf("Enter the width of the fractal: ");
    scanf("%d", &width);

    printf("Enter the height of the fractal: ");
    scanf("%d", &height);

    draw_fractal(0, 0, width, height, MAX_ITERATIONS, ESCAPE_TIME);

    return 0;
}