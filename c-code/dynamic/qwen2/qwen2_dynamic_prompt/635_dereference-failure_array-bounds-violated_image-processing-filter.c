#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

void apply_filter(unsigned char *image, int width, int height) {
    unsigned char *output = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            output[index] = image[index];
        }
    }

    // Intentional out-of-bounds write to demonstrate dereference failure
    output[width * height] = 255;

    free(output);
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
