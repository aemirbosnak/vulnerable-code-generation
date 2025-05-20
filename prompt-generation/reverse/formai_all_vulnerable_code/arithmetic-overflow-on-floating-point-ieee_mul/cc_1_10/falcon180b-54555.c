//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int max_iterations = 1000;
    int width = 800, height = 600;
    int x, y, iterations;
    double real, imag, mag;
    double dx, dy;
    double zoom = 1.0;
    double pan_x = -0.75, pan_y = -0.156;
    double fractal_x, fractal_y;
    FILE *fp;
    char filename[100];
    time_t t;
    struct tm *tm;
    srand(time(NULL));
    printf("Generating fractal...\n");
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            real = (double)x / width * 3.0 - 2.0;
            imag = (double)y / height * 2.0 - 1.0;
            mag = 0.0;
            for (iterations = 0; iterations < max_iterations; iterations++) {
                dx = real * real - imag * imag + pan_x;
                dy = 2.0 * real * imag + pan_y;
                real = dx + zoom * pan_x;
                imag = dy + zoom * pan_y;
                mag += pow(dx, 2.0) + pow(dy, 2.0);
            }
            if (mag > 1000.0) {
                fractal_x = (double)x / width * 3.0 - 2.0;
                fractal_y = (double)y / height * 2.0 - 1.0;
                fractal_x += pan_x;
                fractal_y += pan_y;
                fractal_x *= zoom;
                fractal_y *= zoom;
                fractal_x += 1.5;
                fractal_y += 0.5;
                fractal_x /= 2.0;
                fractal_y /= 2.0;
                fractal_x -= 0.5;
                fractal_y -= 0.5;
                fractal_x *= width;
                fractal_y *= height;
                fractal_x = floor(fractal_x);
                fractal_y = floor(fractal_y);
                if (fractal_x >= 0 && fractal_y >= 0 && fractal_x < width && fractal_y < height) {
                    fprintf(fp, "%d %d %d\n", 0, 0, iterations);
                }
            }
        }
    }
    printf("Fractal generated.\n");
    return 0;
}