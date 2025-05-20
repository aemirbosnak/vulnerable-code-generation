//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_ITERATIONS 1000
#define THRESHOLD 0.0001

int main() {
    srand(time(NULL));

    int width, height;
    printf("Enter the width and height of the Mandelbrot set: ");
    scanf("%d %d", &width, &height);

    int max_iterations = MAX_ITERATIONS;
    double threshold = THRESHOLD;

    double scale_x = (double)width / 2.0;
    double scale_y = (double)height / 2.0;
    double xmin = -scale_x;
    double xmax = scale_x;
    double ymin = -scale_y;
    double ymax = scale_y;

    FILE *file = fopen("mandelbrot.ppm", "wb");

    fprintf(file, "P6\n%d %d\n%d\n", width, height, 255);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double c_re = xmin + (double)x * (xmax - xmin) / (double)width;
            double c_im = ymin + (double)y * (ymax - ymin) / (double)height;

            int iterations = 0;
            double z_re = 0.0;
            double z_im = 0.0;

            while (iterations < max_iterations && (z_re * z_re + z_im * z_im) < threshold) {
                double z_re_new = z_re * z_re - z_im * z_im + c_re;
                double z_im_new = 2.0 * z_re * z_im + c_im;
                z_re = z_re_new;
                z_im = z_im_new;
                iterations++;
            }

            int color = iterations % 8;

            fprintf(file, "%c%c%c", (char)(color << 5), (char)(color << 5), (char)(color << 5));
        }
    }

    fclose(file);

    printf("Mandelbrot set saved to mandelbrot.ppm\n");

    return 0;
}