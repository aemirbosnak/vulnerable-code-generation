#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void process_image(int *image, int width, int height) {
    int new_image[WIDTH][HEIGHT];
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == width - 1 && y == height - 1) {
                // Intentional out-of-bounds write vulnerability
                new_image[y + 1][x] = image[y * width + x]; // Writing to an out-of-bounds index
            } else {
                new_image[y][x] = image[y * width + x];
            }
        }
    }

    // Print the processed image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", new_image[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int image[WIDTH * HEIGHT];

    // Initialize the image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % 256;
    }

    process_image(image, WIDTH, HEIGHT);

    return 0;
}
