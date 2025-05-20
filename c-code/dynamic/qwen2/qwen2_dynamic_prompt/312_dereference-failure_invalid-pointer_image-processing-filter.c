#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void processImage(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *p = &image[y * width + x];
            p->r += 10;
            p->g += 20;
            p->b += 30;
        }
    }
}

int main() {
    Pixel *image = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Intentionally create an invalid pointer to cause a dereference failure
    Pixel *invalidPtr = NULL;
    invalidPtr[0].r = 255; // This will cause a segmentation fault

    processImage(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}
