#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

void process_image(unsigned char *image) {
    unsigned char *output = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            output[index] = image[index];
        }
    }

    // Intentional out-of-bounds write to demonstrate vulnerability
    output[WIDTH * HEIGHT] = 255;

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

    process_image(image);

    free(image);
    return 0;
}
