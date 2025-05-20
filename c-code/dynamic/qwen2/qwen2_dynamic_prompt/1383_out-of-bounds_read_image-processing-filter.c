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

    // Print the first few pixels to verify
    printf("First few pixels after applying filter:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    free(image);
    return 0;
}
