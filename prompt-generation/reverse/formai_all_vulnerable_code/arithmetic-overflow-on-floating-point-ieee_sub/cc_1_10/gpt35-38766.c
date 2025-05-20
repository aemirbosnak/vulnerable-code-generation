//FormAI DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define ITERATION 500

void render(int iterations[HEIGHT][WIDTH]) {
    char display[HEIGHT][WIDTH+1];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            display[y][x] = (iterations[y][x] == ITERATION) ? ' ' : ('a' + iterations[y][x] % 26);
        }
        display[y][WIDTH] = '\0';
    }
    for (int y = 0; y < HEIGHT; y++) {
        puts(display[y]);
    }
}

int main() {
    double x0, x1, y0, y1, dx, dy;
    scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);
    dx = (x1 - x0) / WIDTH;
    dy = (y1 - y0) / HEIGHT;

    int iterations[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double c_re = x0 + x * dx;
            double c_im = y0 + y * dy;
            double z_re = c_re, z_im = c_im;

            int i = 0;
            for (; i < ITERATION; i++) {
                if (z_re * z_re + z_im * z_im > 4) {
                    break;
                }
                double new_z_re = z_re * z_re - z_im * z_im;
                double new_z_im = 2 * z_re * z_im;
                z_re = new_z_re + c_re;
                z_im = new_z_im + c_im;
            }
            iterations[y][x] = i;
        }
    }

    render(iterations);

    return 0;
}