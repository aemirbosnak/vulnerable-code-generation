//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mandelbrot(int *x, int *y, int max_iterations) {
    int i, cx, cy;
    double real, imag, a, b, c, d, e, f;

    for (i = 0; i < max_iterations; i++) {
        real = *x * 0.01;
        imag = *y * 0.01;
        a = 0.0;
        b = 0.0;
        c = 0.0;
        d = 0.0;
        e = 0.0;
        f = 0.0;

        for (cx = 0; cx < 200; cx++) {
            for (cy = 0; cy < 200; cy++) {
                a = real * real - imag * imag + c;
                b = 2.0 * real * imag + d;
                c = 2.0 * real * real + e;
                d = 2.0 * imag * imag + f;
                real = (a * real + b) * real + c;
                imag = (d * imag + e) * imag + f;
            }
        }

        if (c * c + d * d > 4.0) {
            *x += 1;
            *y += 0;
            *x += 0;
            *y += 1;
            *x += -1;
            *y += -1;
            *x += -1;
            *y += 1;
            *x += 1;
            *y += -1;
        } else {
            *x -= 1;
            *y += 0;
            *x -= 0;
            *y += 1;
            *x -= 1;
            *y += 1;
            *x -= 1;
            *y += -1;
            *x += 1;
            *y -= -1;
        }
    }
}

int main() {
    int x, y, max_iterations;
    FILE *fp;

    printf("Enter the number of iterations: ");
    scanf("%d", &max_iterations);

    printf("Enter the starting x and y coordinates: ");
    scanf("%d %d", &x, &y);

    fp = fopen("mandelbrot.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (y = 0; y < 800; y++) {
        for (x = 0; x < 800; x++) {
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
        }

        for (x = 0; x < 800; x++) {
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
            mandelbrot(&x, &y, max_iterations);
        }

        fwrite(x, sizeof(int), 1, fp);
        fwrite(y, sizeof(int), 1, fp);
    }

    fclose(fp);
    printf("Mandelbrot set generated successfully.\n");

    return 0;
}