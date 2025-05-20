//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

int mandelbrot(double x, double y) {
    double real = 0, imag = 0, temp;
    int iter = 0;

    while (iter < MAX_ITER && pow(real * real + imag * imag, 2) <= 4) {
        temp = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp;
        ++iter;
    }

    return iter == MAX_ITER? 0 : iter;
}

void render(double x1, double y1, double x2, double y2, int* buffer) {
    double dx = (x2 - x1) / WIDTH;
    double dy = (y2 - y1) / HEIGHT;

    for (int i = 0; i < HEIGHT; ++i) {
        double y = y1 + i * dy;

        for (int j = 0; j < WIDTH; ++j) {
            double x = x1 + j * dx;
            int value = mandelbrot(x, y);

            if (value == 0) {
                buffer[i * WIDTH + j] = 0;
            } else {
                buffer[i * WIDTH + j] = value % 8;
            }
        }
    }
}

int main() {
    double x1, y1, x2, y2;
    int* buffer = malloc(WIDTH * HEIGHT * sizeof(int));

    printf("Enter the coordinates of the top-left corner: ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the bottom-right corner: ");
    scanf("%lf %lf", &x2, &y2);

    render(x1, y1, x2, y2, buffer);

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (buffer[i * WIDTH + j] == 0) {
                printf("  ");
            } else {
                printf("%c", "0123456789abcdef"[buffer[i * WIDTH + j]]);
            }
        }
        printf("\n");
    }

    free(buffer);

    return 0;
}