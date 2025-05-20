//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define X_MIN -2.0
#define X_MAX 1.0
#define Y_MIN -1.5
#define Y_MAX 1.5
#define ZOOM 0.5

typedef struct {
    double x;
    double y;
} Point;

void fractal(int x, int y, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double real = X_MIN + (X_MAX - X_MIN) * j / (width - 1);
            double imag = Y_MIN + (Y_MAX - Y_MIN) * i / (height - 1);
            Point c = { real, imag };
            int iterations = mandelbrot(c, MAX_ITERATIONS);
            double color = (double)iterations / MAX_ITERATIONS;
            printf("%d ", iterations % 8);
        }
        printf("\n");
    }
}

int mandelbrot(Point c, int max_iterations) {
    Point z = { 0, 0 };
    for (int i = 0; i < max_iterations; i++) {
        Point temp = { z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y };
        if (temp.x * temp.x + temp.y * temp.y > 4.0) {
            return i;
        }
        z = temp;
    }
    return max_iterations;
}

int main() {
    int width, height;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    fractal(0, 0, width, height);

    return 0;
}