//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

int main(int argc, char *argv[]) {
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    int pixels[width * height];
    for (int i = 0; i < width * height; i++) {
        pixels[i] = 0;
    }

    int x = 0;
    int y = 0;
    int iteration = 0;

    while (iteration < MAX_ITERATIONS) {
        if (x < 0 || x >= width || y < 0 || y >= height) {
            break;
        }

        int intensity = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int offsetX = x + i;
                int offsetY = y + j;
                if (offsetX >= 0 && offsetX < width && offsetY >= 0 && offsetY < height) {
                    intensity += pixels[offsetY * width + offsetX];
                }
            }
        }
        intensity /= 4;

        if (intensity < 1) {
            break;
        }

        pixels[y * width + x] = intensity;
        x += 1;
        iteration++;
    }

    for (int i = 0; i < width * height; i++) {
        printf("%d ", pixels[i]);
    }

    printf("\n");

    return 0;
}