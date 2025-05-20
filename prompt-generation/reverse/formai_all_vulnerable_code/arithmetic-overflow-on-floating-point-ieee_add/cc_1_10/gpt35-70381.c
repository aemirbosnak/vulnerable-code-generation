//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int max_iterations = 1000;

void generate_fractal(int X, int Y, double zoom) {
    int i, j, iter;
    double x, y, x_new, y_new, zx, zy, temp;
    unsigned char color;
    FILE *f;
    char filename[20];

    sprintf(filename, "fractal_%d_%d.bmp", X, Y);
    f = fopen(filename, "wb");

    unsigned char header[54] = {
        0x42, 0x4D, 0x36, 0x06, 0x15, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x04, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x20, 0x03, 0x00, 0x00, 0xE0, 0x01,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x48, 0x06, 0x15, 0x00, 0x13, 0x0B,
        0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00
    };

    fwrite(header, sizeof(unsigned char), 54, f);

    unsigned char *pixels = (unsigned char*)calloc(3 * WIDTH * HEIGHT, sizeof(unsigned char));

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            zx = (i - WIDTH / 2.0) / (0.5 * zoom * WIDTH);
            zy = (j - HEIGHT / 2.0) / (0.5 * zoom * HEIGHT);
            x = zx;
            y = zy;
            iter = 0;
            while (x*x + y*y < 4 && iter < max_iterations) {
                x_new = x*x - y*y + zx;
                y_new = 2*x*y + zy;
                x = x_new;
                y = y_new;
                iter++;
            }
            if (iter == max_iterations) {
                color = 0;
            } else {
                color = (unsigned char)((double)iter / max_iterations * 255);
            }
            pixels[(i + j * WIDTH) * 3] = color;
            pixels[(i + j * WIDTH) * 3 + 1] = color;
            pixels[(i + j * WIDTH) * 3 + 2] = color;
        }
    }

    fwrite(pixels, sizeof(unsigned char), 3 * WIDTH * HEIGHT, f);

    free(pixels);
    fclose(f);

    printf("Fractal saved in %s\n", filename);
}

int main(int argc, char *argv[]) {
    int X, Y;
    double zoom;

    printf("Enter X coordinate: ");
    scanf("%d", &X);
    printf("Enter Y coordinate: ");
    scanf("%d", &Y);
    printf("Enter zoom level: ");
    scanf("%lf", &zoom);

    generate_fractal(X, Y, zoom);

    return 0;
}