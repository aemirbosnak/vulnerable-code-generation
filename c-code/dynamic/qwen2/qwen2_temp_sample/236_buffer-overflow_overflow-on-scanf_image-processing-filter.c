#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void apply_filter(char* image_data, int width, int height) {
    // Simulate image processing
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char pixel = image_data[y * width + x];
            if (pixel > 128) {
                image_data[y * width + x] = pixel - 32;
            } else {
                image_data[y * width + x] = pixel + 32;
            }
        }
    }
}

int main() {
    char image[64]; // Fixed-size array to simulate an image buffer

    printf("Enter image data (up to 64 characters): ");
    scanf("%s", image); // Vulnerable to buffer overflow

    int width = 8;
    int height = 8;

    apply_filter(image, width, height);

    printf("Processed image: %s\n", image);

    return 0;
}
