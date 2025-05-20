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
            int r = image[index] & 0xFF;
            int g = (image[index] >> 8) & 0xFF;
            int b = (image[index] >> 16) & 0xFF;

            // Apply a simple brightness increase
            r += 30;
            g += 30;
            b += 30;

            // Clamp values to ensure they don't exceed 255
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;

            output[index] = (r << 16) | (g << 8) | b;
        }
    }

    // Copy output back to input image
    for (int i = 0; i < width * height; i++) {
        image[i] = output[i];
    }

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

    // Initialize image with random pixel values
    for (int i = 0; i < width * height; i++) {
        image[i] = rand();
    }

    applyFilter(image, width, height);

    // Free allocated memory
    free(image);

    return 0;
}
