#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(unsigned char* img, int width, int height) {
    unsigned char* temp = (unsigned char*)malloc(width * height);
    if (!temp) return;

    // Simulate some image processing
    for (int i = 0; i < width * height; i++) {
        temp[i] = img[i];
    }

    // Use after free vulnerability
    for (int i = 0; i < width * height; i++) {
        img[i] = temp[i + width * height]; // Out-of-bounds access
    }

    free(temp);
}

int main() {
    int width = 100, height = 100;
    unsigned char* img = (unsigned char*)malloc(width * height);

    if (!img) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image data
    for (int i = 0; i < width * height; i++) {
        img[i] = rand() % 256;
    }

    apply_filter(img, width, height);

    // Free memory
    free(img);

    return 0;
}
