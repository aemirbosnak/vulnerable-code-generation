//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    // Open the image file
    FILE *image_file = fopen("image.jpg", "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error: could not open image file\n");
        return 1;
    }

    // Read the image data
    unsigned char *image_data = malloc(WIDTH * HEIGHT * 3);
    fread(image_data, 1, WIDTH * HEIGHT * 3, image_file);
    fclose(image_file);

    // Convert the image data to ASCII art
    char *ascii_art = malloc(WIDTH * HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get the RGB values of the pixel
            unsigned char r = image_data[(y * WIDTH + x) * 3];
            unsigned char g = image_data[(y * WIDTH + x) * 3 + 1];
            unsigned char b = image_data[(y * WIDTH + x) * 3 + 2];

            // Convert the RGB values to a grayscale value
            double grayscale = 0.2126 * r + 0.7152 * g + 0.0722 * b;

            // Convert the grayscale value to an ASCII character
            char character;
            if (grayscale < 32) {
                character = '#';
            } else if (grayscale < 64) {
                character = '$';
            } else if (grayscale < 96) {
                character = 'O';
            } else if (grayscale < 128) {
                character = '*';
            } else if (grayscale < 160) {
                character = 'o';
            } else if (grayscale < 192) {
                character = '-';
            } else if (grayscale < 224) {
                character = ':';
            } else {
                character = ' ';
            }

            // Add the ASCII character to the ASCII art string
            ascii_art[y * WIDTH + x] = character;
        }
    }

    // Print the ASCII art to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", ascii_art[y * WIDTH + x]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(image_data);
    free(ascii_art);

    return 0;
}