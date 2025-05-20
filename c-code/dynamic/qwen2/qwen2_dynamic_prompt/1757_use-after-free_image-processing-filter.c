#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(unsigned char* image, int width, int height) {
    unsigned char* temp = (unsigned char*)malloc(width * height);
    if (!temp) return;

    // Simulate some image processing
    for (int i = 0; i < width * height; ++i) {
        temp[i] = image[i];
    }

    // Use after free vulnerability
    for (int i = 0; i < width * height; ++i) {
        image[i] = temp[i + width * height]; // Out-of-bounds access
    }

    free(temp); // Freeing the memory
}

int main() {
    int width = 100;
    int height = 100;
    unsigned char* image = (unsigned char*)malloc(width * height);

    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image data
    for (int i = 0; i < width * height; ++i) {
        image[i] = rand() % 256;
    }

    apply_filter(image, width, height);

    // Print first few pixels to verify
    printf("First pixel: %d\n", image[0]);
    printf("Second pixel: %d\n", image[1]);

    free(image);
    return 0;
}
