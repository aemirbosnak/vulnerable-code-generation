//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
    int color;
} Pixel;

void putpixel(Pixel *screen, int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        screen[y * WIDTH + x].color = color;
    }
}

void drawline(Pixel *screen, int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx);
    int err = dx / 2;
    int ystep;

    if (y1 < y2) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (int i = 0; i <= steps; i++) {
        putpixel(screen, x1, y1, color);
        if (dx > 0) {
            x1++;
        } else {
            x1--;
        }
        y1 += ystep;
        err -= dy;
        if (err < 0) {
            y1 += ystep;
            err += dx;
        }
    }
}

void drawmandelbrot(Pixel *screen, int xmin, int xmax, int ymin, int ymax, int maxiter) {
    int x, y, iter;
    double real, imag;
    double dx, dy;

    for (y = ymin; y <= ymax; y++) {
        dy = (double)y / HEIGHT * 3.0 - 2.0;
        for (x = xmin; x <= xmax; x++) {
            dx = (double)x / WIDTH * 3.0 - 2.0;
            real = dx;
            imag = dy;
            iter = 0;

            while (iter < maxiter && (real * real + imag * imag) <= 4.0) {
                double temp = real * real - imag * imag + dx;
                imag = 2.0 * real * imag + dy;
                real = temp;
                iter++;
            }

            putpixel(screen, x, y, iter % 8);
        }
    }
}

int main() {
    Pixel *screen = malloc(WIDTH * HEIGHT * sizeof(Pixel));

    drawmandelbrot(screen, -2.0, 1.0, -1.5, 1.5, 256);

    FILE *fp = fopen("fractal.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(fp, "%d %d %d ", screen[y * WIDTH + x].color, screen[y * WIDTH + x].color, screen[y * WIDTH + x].color);
        }
    }

    fclose(fp);

    free(screen);

    return 0;
}