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

void apply_filter(Pixel *image, int width, int height) {
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
    Pixel *image = malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Simulate an error by not freeing the allocated memory
    apply_filter(image, WIDTH, HEIGHT);

    free(image); // This line is missing to cause a dangling pointer issue

    return 0;
}
