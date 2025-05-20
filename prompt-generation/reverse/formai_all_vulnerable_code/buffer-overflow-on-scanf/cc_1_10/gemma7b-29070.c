//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main() {
    int x, y, i, n, m;
    double dx, dy, x1, x2, y1, y2, r;
    double complex_number_a, complex_number_b;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    dx = (double)m / MAX;
    dy = (double)m / MAX;

    x1 = -1.5;
    x2 = 1.5;
    y1 = -1.0;
    y2 = 1.0;

    for (i = 0; i < n; i++) {
        for (x = 0; x < m; x++) {
            for (y = 0; y < m; y++) {
                complex_number_a = x1 + dx * (double)x;
                complex_number_b = y1 + dy * (double)y;

                if (Mandelbrot(complex_number_a, complex_number_b) == 0) {
                    printf(" ");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }
    }

    return 0;
}

int Mandelbrot(double a, double b) {
    int i, z, c, n_iter;
    double x, y, z_re, z_im, c_re, c_im;

    n_iter = 0;
    z = 0;

    x = 0.0;
    y = 0.0;

    for (i = 0; z == 0 && i < n_iter; i++) {
        c_re = a + x * x + y * y;
        c_im = b + 2 * x * y;
        z_re = x * x + y * y;
        z_im = 2 * x * y;
        x = z_re - c_re * x - c_im * y;
        y = z_im - c_re * y - c_im * x;
        z = (int)sqrt(x * x + y * y);
    }

    return z;
}