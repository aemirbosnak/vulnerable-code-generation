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

void process_image(Pixel *image, int width, int height) {
    Pixel *ptr = image;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Intentional invalid pointer dereference
            ptr->r += 10;
            ptr->g += 20;
            ptr->b += 30;
            ptr++;
        }
    }
}

int main() {
    Pixel *image = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    process_image(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}
