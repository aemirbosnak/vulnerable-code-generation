#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

void apply_filter(unsigned char *image, int width, int height) {
    unsigned char *filtered_image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (!filtered_image) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            filtered_image[index] = image[index];
        }
    }

    // Intentional out-of-bounds write to demonstrate vulnerability
    int out_of_bounds_index = height * width;
    filtered_image[out_of_bounds_index] = 255;

    free(filtered_image);
}

int main() {
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % 256;
    }

    apply_filter(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}
