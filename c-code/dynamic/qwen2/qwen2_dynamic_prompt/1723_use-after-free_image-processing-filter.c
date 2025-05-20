#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(unsigned char* image, int width, int height) {
    unsigned char* temp = (unsigned char*)malloc(width * height);
    if (!temp) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Simulate some image processing
    for (int i = 0; i < width * height; i++) {
        temp[i] = image[i];
    }

    // Use after free vulnerability
    for (int i = 0; i < width * height; i++) {
        image[i] = temp[i + width * height]; // Out-of-bounds access
    }

    free(temp);
}

int main() {
    int width = 100, height = 100;
    unsigned char* image = (unsigned char*)malloc(width * height);

    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image data
    for (int i = 0; i < width * height; i++) {
        image[i] = rand() % 256;
    }

    apply_filter(image, width, height);

    free(image);

    return 0;
}
