#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

typedef unsigned char pixel_t;

void apply_filter(pixel_t* image, size_t width, size_t height) {
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            for (int offset = -10; offset <= 10; offset++) {
                size_t new_x = x + offset;
                if (new_x < 0 || new_x >= width) {
                    image[y * WIDTH + (x + offset) % WIDTH] = 0xFF; // Write out of bounds
                } else {
                    image[y * WIDTH + new_x] += offset * 3; // Modify pixel value for fun
                }
            }
        }
    }
}

int main() {
    pixel_t image[HEIGHT * WIDTH];
    memset(image, 0, HEIGHT * WIDTH);

    apply_filter(image, WIDTH, HEIGHT);

    FILE* output = fopen("filtered_image.raw", "wb");
    fwrite(image, sizeof(pixel_t), HEIGHT * WIDTH, output);
    fclose(output);

    return 0;
}
