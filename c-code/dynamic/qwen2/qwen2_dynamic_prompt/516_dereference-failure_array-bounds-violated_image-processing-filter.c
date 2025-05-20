#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void process_image(int *image, int width, int height) {
    int new_image[WIDTH][HEIGHT];
    for (int y = 0; y <= height; y++) { // Deliberate off-by-one error
        for (int x = 0; x <= width; x++) { // Deliberate off-by-one error
            new_image[y][x] = image[y * width + x]; // Potential out-of-bounds access
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", new_image[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int image[WIDTH][HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x] = rand() % 256;
        }
    }

    process_image((int *)image, WIDTH, HEIGHT);

    return 0;
}
