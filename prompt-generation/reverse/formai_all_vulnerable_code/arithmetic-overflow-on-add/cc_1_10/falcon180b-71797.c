//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

void draw_pixel(int x, int y, unsigned char color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        printf("%c", color);
    }
}

void fractal(int x, int y, int iter, unsigned char color) {
    if (iter == 0) {
        draw_pixel(x, y, color);
        return;
    }

    int real = x - 400;
    int imag = y - 300;
    int real_new, imag_new;

    for (int i = 0; i < iter; i++) {
        real_new = real * real - imag * imag + 400;
        imag_new = 2 * real * imag + 300;

        real = real_new;
        imag = imag_new;

        if (real * real + imag * imag > 1000000) {
            fractal(x, y, iter - 1, color);
            return;
        }
    }

    fractal(x, y, iter - 1, color);
}

int main() {
    int x, y;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            x = j - 400;
            y = i - 300;

            fractal(j, i, MAX_ITER, 0);
        }
    }

    return 0;
}