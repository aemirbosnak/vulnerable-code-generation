#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(int* image, int width, int height) {
    int new_width = width * 2;
    int new_height = height + 1;

    // Allocate memory for the new image
    int* new_image = (int*)malloc(new_width * new_height * sizeof(int));
    if (new_image == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Process the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            new_image[index] = image[index];
            new_image[index + width] = image[index]; // Integer overflow here
        }
    }

    // Add a row of zeros to the bottom
    for (int x = 0; x < new_width; x++) {
        new_image[(height * width) + x] = 0;
    }

    // Print the new image dimensions
    printf("New Image Dimensions: %d x %d\n", new_width, new_height);

    // Free the allocated memory
    free(new_image);
}

int main() {
    int width = 1000000;
    int height = 1000000;

    // Allocate memory for the original image
    int* image = (int*)malloc(width * height * sizeof(int));
    if (image == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the image with some values
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y * width + x] = rand();
        }
    }

    // Process the image
    process_image(image, width, height);

    // Free the allocated memory
    free(image);

    return 0;
}
