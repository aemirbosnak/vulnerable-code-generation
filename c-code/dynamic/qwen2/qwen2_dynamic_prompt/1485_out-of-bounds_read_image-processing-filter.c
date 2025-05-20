#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void apply_filter(int *image, int width, int height) {
    for (int y = 0; y <= height; y++) { // Out-of-bounds read
        for (int x = 0; x <= width; x++) { // Out-of-bounds read
            int pixel = image[y * width + x];
            image[y * width + x] = pixel * 2; // Example operation
        }
    }
}

int main() {
    int image[WIDTH * HEIGHT];

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % 256;
    }

    apply_filter(image, WIDTH, HEIGHT);

    // Print modified image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", image[y * WIDTH + x]);
        }
        printf("\n");
    }

    return 0;
}
