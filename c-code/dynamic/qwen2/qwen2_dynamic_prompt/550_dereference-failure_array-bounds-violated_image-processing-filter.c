#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void apply_filter(int *image, int width, int height) {
    int new_image[width][height];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int sum = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int ny = y + ky;
                    int nx = x + kx;
                    if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
                        sum += image[ny * width + nx];
                    }
                }
            }
            new_image[y][x] = sum / 9;
        }
    }
    // Deliberate dereference failure: out-of-bounds access
    new_image[HEIGHT][WIDTH] = 255;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", new_image[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int image[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x] = rand() % 256;
        }
    }

    apply_filter((int *)image, WIDTH, HEIGHT);

    return 0;
}
