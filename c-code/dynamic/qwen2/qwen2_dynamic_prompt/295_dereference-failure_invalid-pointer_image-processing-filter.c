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

void applyFilter(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *p = &image[y * width + x];
            p->r += 100;
            p->g -= 50;
            p->b *= 2;
        }
    }
}

int main() {
    Pixel *image = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Simulate an invalid pointer usage
    Pixel *invalidPtr = NULL;
    applyFilter(invalidPtr, WIDTH, HEIGHT);

    free(image);
    return 0;
}
