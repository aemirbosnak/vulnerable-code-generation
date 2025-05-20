//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

unsigned char image[WIDTH * HEIGHT];

int main() {
    // Load the image from a file
    FILE *fp = fopen("image.jpg", "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Convert the image to ASCII art
    char *ascii = malloc(WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        // Get the brightness of the pixel
        int brightness = image[i];

        // Convert the brightness to a character
        char character;
        if (brightness < 32) {
            character = ' ';
        } else if (brightness < 64) {
            character = '.';
        } else if (brightness < 96) {
            character = ',';
        } else if (brightness < 128) {
            character = ':';
        } else if (brightness < 160) {
            character = ';';
        } else if (brightness < 192) {
            character = '#';
        } else {
            character = '@';
        }

        // Save the character to the ASCII array
        ascii[i] = character;
    }

    // Print the ASCII art to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii[i * WIDTH + j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII array
    free(ascii);

    return EXIT_SUCCESS;
}