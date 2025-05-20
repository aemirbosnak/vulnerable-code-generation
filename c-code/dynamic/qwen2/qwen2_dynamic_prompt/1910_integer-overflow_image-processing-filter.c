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

    // Print the new image
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            printf("%d ", new_image[y * new_width + x]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(new_image);
}

int main() {
    int width = 3;
    int height = 3;
    int image[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    process_image(image, width, height);

    return 0;
}
