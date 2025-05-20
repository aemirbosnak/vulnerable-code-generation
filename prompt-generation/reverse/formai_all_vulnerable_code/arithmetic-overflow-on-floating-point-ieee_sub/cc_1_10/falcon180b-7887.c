//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int mandelbrot(double x, double y) {
    double real = 0;
    double imag = 0;
    int iterations = 0;

    for (iterations = 0; iterations < 100 && (real * real + imag * imag) < 4; iterations++) {
        double temp = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp;
    }

    return iterations;
}

void draw_mandelbrot(double xmin, double xmax, double ymin, double ymax) {
    int i, j;
    double x, y;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            x = xmin + (xmax - xmin) * j / (WIDTH - 1);
            y = ymin + (ymax - ymin) * i / (HEIGHT - 1);

            int color = mandelbrot(x, y);

            printf("%c", (color % 8) + '0');
        }
        printf("\n");
    }
}

int main() {
    double xmin, xmax, ymin, ymax;

    printf("Enter the coordinates of the left bottom corner: ");
    scanf("%lf%lf", &xmin, &ymin);

    printf("Enter the coordinates of the right top corner: ");
    scanf("%lf%lf", &xmax, &ymax);

    draw_mandelbrot(xmin, xmax, ymin, ymax);

    return 0;
}