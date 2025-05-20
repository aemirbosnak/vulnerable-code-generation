//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_WIDTH 800
#define MAX_HEIGHT 600
#define MIN_WIDTH 1
#define MIN_HEIGHT 1
#define MAX_COLOR 255
#define MIN_COLOR 0
#define DEFAULT_COLOR 0
#define RED(c) (((c) >> 16) & 0xFF)
#define GREEN(c) (((c) >> 8) & 0xFF)
#define BLUE(c) ((c) & 0xFF)
#define COLOR_DISTANCE(c1, c2) (RED(c1) - RED(c2)) * (RED(c1) - RED(c2)) + (GREEN(c1) - GREEN(c2)) * (GREEN(c1) - GREEN(c2)) + (BLUE(c1) - BLUE(c2)) * (BLUE(c1) - BLUE(c2))

void set_pixel(int x, int y, int color) {
    if (x >= 0 && x < MAX_WIDTH && y >= 0 && y < MAX_HEIGHT) {
        printf("1");
    }
}

int main() {
    int width, height, max_iterations;
    int x, y, iterations, color;
    double real, imag;

    printf("Enter the width: ");
    scanf("%d", &width);
    printf("Enter the height: ");
    scanf("%d", &height);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            real = (double)x / width;
            imag = (double)y / height;
            iterations = 0;
            while (iterations < max_iterations && (real * real + imag * imag < 4)) {
                real = real * real - imag * imag + (double)x / width;
                imag = 2 * real * imag + (double)y / height;
                ++iterations;
            }
            color = iterations % 8;
            set_pixel(x, y, color);
        }
    }

    return 0;
}