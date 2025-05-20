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
            Pixel *pixel = &image[y * WIDTH + x];
            if (x == 5 && y == 5) {
                // Deliberate null pointer dereference vulnerability
                pixel->r = 255;
                pixel->g = 0;
                pixel->b = 0;
            }
        }
    }
}

int main() {
    Pixel *image = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    processImage(image);

    free(image);
    return 0;
}
