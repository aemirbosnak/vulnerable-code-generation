#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void processImage(Pixel *image) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            Pixel *pixel = &image[index];
            pixel->r += 10;
            pixel->g -= 20;
            pixel->b *= 2;
        }
    }
}

int main() {
    Pixel *image = malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Simulate an invalid pointer usage
    Pixel *invalidPtr = NULL;
    invalidPtr->r = 255; // Dereferencing invalid pointer

    free(image);
    return 0;
}
