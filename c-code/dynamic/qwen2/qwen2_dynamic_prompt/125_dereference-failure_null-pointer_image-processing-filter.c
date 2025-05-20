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

void applyFilter(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *p = &image[y * width + x];
            p->r = 255 - p->r;
            p->g = 255 - p->g;
            p->b = 255 - p->b;
        }
    }
}

int main() {
    Pixel *image = NULL;
    int width = WIDTH;
    int height = HEIGHT;

    // Simulate loading an image
    image = malloc(width * height * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Apply filter to the image
    applyFilter(image, width, height);

    // Free the allocated memory
    free(image);

    return 0;
}
