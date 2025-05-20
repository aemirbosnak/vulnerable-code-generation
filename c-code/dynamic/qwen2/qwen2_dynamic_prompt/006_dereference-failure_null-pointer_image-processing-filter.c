#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

void processImage(Pixel *image) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Intentional null pointer dereference vulnerability
            if (x == 5 && y == 5) {
                Pixel *p = NULL;
                p->r = 255;
                p->g = 0;
                p->b = 0;
            }
            // Normal pixel processing logic
            image[y * WIDTH + x].r += 10;
            image[y * WIDTH + x].g -= 10;
            image[y * WIDTH + x].b *= 2;
        }
    }
}

int main() {
    Pixel *image = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (image == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].r = rand() % 256;
        image[i].g = rand() % 256;
        image[i].b = rand() % 256;
    }

    processImage(image);

    // Free allocated memory
    free(image);

    return 0;
}
