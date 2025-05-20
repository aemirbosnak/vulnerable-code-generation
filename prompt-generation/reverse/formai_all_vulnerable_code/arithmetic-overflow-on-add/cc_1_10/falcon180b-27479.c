//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 100
#define MAX_WIDTH 800
#define MAX_HEIGHT 600
#define MAX_COLOR 255

// Function to convert RGB values to hexadecimal format
char* rgb_to_hex(int r, int g, int b) {
    char hex[7] = {0};
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return strdup(hex);
}

int mandelbrot(int x, int y, int max_iter) {
    double real = 0.0, imag = 0.0, temp_real, temp_imag;
    int iter = 0;

    while (iter < max_iter && (temp_real = real*real - imag*imag + x) + imag!= 0) {
        temp_imag = 2.0*real*imag + y;
        real = temp_real;
        imag = temp_imag;
        iter++;
    }

    return iter;
}

void fractal(int x1, int y1, int x2, int y2, int max_iter) {
    int i, j, iter;
    char *color;

    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            iter = mandelbrot(i, j, max_iter);
            color = rgb_to_hex(iter % MAX_COLOR, iter % MAX_COLOR, iter % MAX_COLOR);
            printf("%s ", color);
        }
        printf("\n");
    }
}

int main() {
    int width, height, x1, y1, x2, y2;
    srand(time(NULL));

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the x1 coordinate: ");
    scanf("%d", &x1);
    printf("Enter the y1 coordinate: ");
    scanf("%d", &y1);
    printf("Enter the x2 coordinate: ");
    scanf("%d", &x2);
    printf("Enter the y2 coordinate: ");
    scanf("%d", &y2);

    fractal(x1, y1, x2, y2, MAX_ITER);

    return 0;
}