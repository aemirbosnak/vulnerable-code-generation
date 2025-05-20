//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 100

int mandelbrot(double x, double y) {
    int iterations = 0;
    double real = 0, imag = 0;

    while (iterations < MAX_ITERATIONS && (real*real + imag*imag) < 4) {
        real = real*real - imag*imag + x;
        imag = 2*real*imag + y;
        iterations++;
    }

    return iterations;
}

void generate_fractal(double x0, double y0, double x1, double y1) {
    FILE *fp = fopen("fractal.pbm", "wb");

    if (!fp) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = HEIGHT - 1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            double cx = x0 + (x1 - x0) * x / WIDTH;
            double cy = y0 + (y1 - y0) * y / HEIGHT;

            int iterations = mandelbrot(cx, cy);

            if (iterations == MAX_ITERATIONS) {
                fprintf(fp, "0\n");
            } else {
                int value = iterations % 8;
                fprintf(fp, "%d\n", value);
            }
        }
    }

    fclose(fp);
}

int main() {
    double x0, y0, x1, y1;

    printf("Enter the coordinates of the top-left corner: ");
    scanf("%lf %lf", &x0, &y0);

    printf("Enter the coordinates of the bottom-right corner: ");
    scanf("%lf %lf", &x1, &y1);

    generate_fractal(x0, y0, x1, y1);

    printf("Fractal generated successfully!\n");

    return 0;
}