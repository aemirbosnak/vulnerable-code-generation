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

    // Intentional out-of-bounds write vulnerability
    int out_of_bounds_index = width * height;
    buffer[out_of_bounds_index] = 123456789; // Writing to an invalid memory location

    free(buffer);
}

int main() {
    int width = 100;
    int height = 100;
    int* image = (int*)malloc(width * height * sizeof(int));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < width * height; i++) {
        image[i] = i % 256;
    }

    process_image(image, width, height);

    free(image);
    return 0;
}
