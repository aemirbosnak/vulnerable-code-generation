#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void applyFilter(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Invalid pointer dereference
            Pixel *p = &image[(y + 1) * width + x];
            p->r += 10;
            p->g += 10;
            p->b += 10;
        }
    }
}

int main() {
    Pixel *image = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].r = i % 256;
        image[i].g = (i / 256) % 256;
        image[i].b = (i / 65536) % 256;
    }

    applyFilter(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}
