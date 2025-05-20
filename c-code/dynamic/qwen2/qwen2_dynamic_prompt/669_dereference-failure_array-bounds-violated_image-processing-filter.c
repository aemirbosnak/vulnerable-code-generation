#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void applyFilter(int* image, int width, int height) {
    int* output = (int*)malloc(width * height * sizeof(int));
    if (!output) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            output[index] = image[index];
        }
    }

    // Intentional out-of-bounds write
    output[width * height] = 255;

    free(output);
}

int main() {
    int width = 100;
    int height = 100;
    int* image = (int*)malloc(width * height * sizeof(int));
    if (!image) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < width * height; i++) {
        image[i] = i % 256;
    }

    applyFilter(image, width, height);

    free(image);
    return 0;
}
