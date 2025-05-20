#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void apply_filter(int *image, int width, int height) {
    for (int y = 0; y <= height; y++) { // Out-of-bounds write
        for (int x = 0; x <= width; x++) { // Out-of-bounds write
            image[y * width + x] += 10; // Modify adjacent pixels
        }
    }
}

int main() {
    int *image = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = i % 256;
    }

    apply_filter(image, WIDTH, HEIGHT);

    // Print modified image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", image[y * WIDTH + x]);
        }
        printf("\n");
    }

    free(image);
    return 0;
}
