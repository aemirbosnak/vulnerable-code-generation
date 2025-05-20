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

void processImage(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Intentional invalid pointer dereference
            Pixel *p = &image[(y + 1) * width + x];
            p->r += 10;
            p->g += 20;
            p->b += 30;
        }
    }
}

int main() {
    Pixel image[HEIGHT][WIDTH];

    // Initialize image with some values
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x].r = rand() % 256;
            image[y][x].g = rand() % 256;
            image[y][x].b = rand() % 256;
        }
    }

    processImage((Pixel *)image, WIDTH, HEIGHT);

    return 0;
}
