//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 256

unsigned char buffer[WIDTH * HEIGHT];

void mandelbrot(double cx, double cy, int max_iter) {
    double zx = 0.0, zy = 0.0, zx2 = 0.0, zy2 = 0.0;
    int iter = 0;
    while (iter < max_iter && zx2 + zy2 < 4.0) {
        zy = 2.0 * zx * zy + cy;
        zx = zx2 - zy2 + cx;
        zx2 = zx * zx;
        zy2 = zy * zy;
        iter++;
    }
    buffer[iter] = iter;
}

void write_pgm(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(buffer, sizeof(buffer), 1, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    double xmin = -2.0, xmax = 1.0, ymin = -1.5, ymax = 1.5;
    if (argc > 4) {
        xmin = atof(argv[1]);
        xmax = atof(argv[2]);
        ymin = atof(argv[3]);
        ymax = atof(argv[4]);
    }
    double dx = (xmax - xmin) / WIDTH;
    double dy = (ymax - ymin) / HEIGHT;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cx = xmin + x * dx;
            double cy = ymin + y * dy;
            mandelbrot(cx, cy, MAX_ITER);
        }
    }
    write_pgm("mandelbrot.pgm");
    return 0;
}