//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    srand(time(NULL));

    int **pixels = malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = malloc(WIDTH * sizeof(int));
    }

    int max_iterations = 500;
    double zoom = 1.0;
    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;

    for (int y = 0; y < HEIGHT; y++) {
        double yc = (double)y / HEIGHT * (ymax - ymin) + ymin;
        for (int x = 0; x < WIDTH; x++) {
            double xc = (double)x / WIDTH * (xmax - xmin) + xmin;
            int iterations = 0;
            while (iterations < max_iterations && pow(xc, 2.0) + pow(yc, 2.0) < 4.0) {
                double new_xc = pow(xc, 2.0) - pow(yc, 2.0) + xc;
                double new_yc = 2.0 * xc * yc + yc;
                xc = new_xc;
                yc = new_yc;
                iterations++;
            }
            pixels[y][x] = iterations % 8;
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", pixels[y][x]);
        }
        printf("\n");
    }

    for (int y = 0; y < HEIGHT; y++) {
        free(pixels[y]);
    }
    free(pixels);

    return 0;
}