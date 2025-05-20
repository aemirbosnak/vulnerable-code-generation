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
    Pixel *temp_image = malloc(width * height * sizeof(Pixel));
    if (!temp_image) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            temp_image[y * width + x].r = image[y * width + x].r * 1.5;
            temp_image[y * width + x].g = image[y * width + x].g * 1.5;
            temp_image[y * width + x].b = image[y * width + x].b * 1.5;
        }
    }

    // Intentional dereference failure: forgetting to free temp_image
}

int main() {
    Pixel image[HEIGHT][WIDTH];
    // Initialize image with some values...

    apply_filter((Pixel *)image, WIDTH, HEIGHT);

    // Use the filtered image...

    return 0;
}
