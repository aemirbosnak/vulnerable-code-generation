//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define WIDTH 800
#define HEIGHT 600
#define X_MIN -2.0
#define X_MAX 1.0
#define Y_MIN -1.5
#define Y_MAX 1.5
#define COLOR_MAX 255

typedef struct {
    int x, y;
    int color;
} Pixel;

void draw_pixel(Pixel *screen, int x, int y, int color) {
    screen[y * WIDTH + x].color = color;
}

int mandelbrot(double x, double y) {
    double zx = 0, zy = 0, temp;
    int iter = 0;

    while (iter < MAX_ITER && zx * zx + zy * zy < 4.0) {
        temp = zx * zx - zy * zy + x;
        zy = 2.0 * zx * zy + y;
        zx = temp;
        iter++;
    }

    return iter;
}

void generate_fractal(Pixel *screen) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double real = (X_MIN + (X_MAX - X_MIN) * x / (WIDTH - 1));
            double imag = (Y_MIN + (Y_MAX - Y_MIN) * y / (HEIGHT - 1));

            int color = mandelbrot(real, imag) % COLOR_MAX;
            draw_pixel(screen, x, y, color);
        }
    }
}

void save_image(char *filename, Pixel *screen) {
    FILE *fp;
    fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(screen, sizeof(Pixel), WIDTH * HEIGHT, fp);

    fclose(fp);
}

int main() {
    Pixel *screen = malloc(WIDTH * HEIGHT * sizeof(Pixel));

    generate_fractal(screen);
    save_image("mandelbrot.bmp", screen);

    free(screen);
    return 0;
}