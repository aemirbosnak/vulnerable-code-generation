//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    // Create an image buffer
    unsigned char *image = malloc(WIDTH * HEIGHT);

    // Load an image from a file
    FILE *fp = fopen("image.ppm", "rb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Create an ASCII art buffer
    char *ascii = malloc(WIDTH * HEIGHT);

    // Convert the image to ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get the pixel value
            unsigned char pixel = image[y * WIDTH + x];

            // Convert the pixel value to an ASCII character
            char c;
            if (pixel < 32) {
                c = ' ';
            } else if (pixel < 64) {
                c = '.';
            } else if (pixel < 96) {
                c = ',';
            } else if (pixel < 128) {
                c = '-';
            } else if (pixel < 160) {
                c = '=';
            } else if (pixel < 192) {
                c = '+';
            } else if (pixel < 224) {
                c = '*';
            } else {
                c = '#';
            }

            // Store the ASCII character in the buffer
            ascii[y * WIDTH + x] = c;
        }
    }

    // Print the ASCII art to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(ascii[y * WIDTH + x]);
        }
        putchar('\n');
    }

    // Free the memory
    free(image);
    free(ascii);

    return EXIT_SUCCESS;
}