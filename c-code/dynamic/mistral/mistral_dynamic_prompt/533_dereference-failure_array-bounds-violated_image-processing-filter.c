#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 3
#define HEIGHT 2
#define MAX_PIXEL 255

void process_image(unsigned char image[HEIGHT][WIDTH]) {
    unsigned char* pixel = malloc(WIDTH * HEIGHT);
    unsigned int index = 0;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel[index++] = image[y][x] * 2; // Double the pixel value
            if (index == WIDTH * HEIGHT) break; // Exit loop after processing all pixels

            // Violating bounds by accessing non-existent pixels in the image
            if (y + 1 < HEIGHT)
                pixel[index++] = image[y + 1][x];
            if (x + 1 < WIDTH)
                pixel[index++] = image[y][x + 1];
            if (y + 1 < HEIGHT && x + 1 < WIDTH)
                pixel[index++] = image[y + 1][x + 1];
        }
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (pixel[i] > MAX_PIXEL)
            pixel[i] = MAX_PIXEL; // Clamping the pixel value to a maximum of 255
        printf("%d ", pixel[i]);
    }

    free(pixel);
}

int main() {
    unsigned char image[HEIGHT][WIDTH] = {
        { 5, 10, 15 },
        { 20, 25, 30 }
    };

    process_image(image);

    return 0;
}
