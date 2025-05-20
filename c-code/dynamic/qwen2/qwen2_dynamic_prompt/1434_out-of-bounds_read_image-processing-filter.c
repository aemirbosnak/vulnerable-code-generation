#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(int* image, int width, int height) {
    int* buffer = (int*)malloc(width * height * sizeof(int));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Simulate image processing
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            buffer[index] = image[index];
        }
    }

    // Intentional out-of-bounds read vulnerability
    int out_of_bounds_value = buffer[width * height]; // This is out of bounds

    printf("Out of bounds value: %d\n", out_of_bounds_value);

    free(buffer);
}

int main() {
    int width = 10;
    int height = 10;
    int* image = (int*)malloc(width * height * sizeof(int));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < width * height; i++) {
        image[i] = i;
    }

    process_image(image, width, height);

    free(image);
    return 0;
}
