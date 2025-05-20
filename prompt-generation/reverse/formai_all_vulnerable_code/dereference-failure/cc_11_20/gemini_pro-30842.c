//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

int main() {
    // Read the image file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Get the image dimensions
    unsigned int width, height;
    fread(&width, sizeof(unsigned int), 1, fp);
    fread(&height, sizeof(unsigned int), 1, fp);

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the image data
    fread(data, sizeof(unsigned char), width * height * 3, fp);

    // Close the image file
    fclose(fp);

    // Convert the image to ASCII art
    char *art = malloc(WIDTH * HEIGHT);
    if (art == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get the average color of the pixel
            unsigned char r = data[(y * WIDTH + x) * 3 + 2];
            unsigned char g = data[(y * WIDTH + x) * 3 + 1];
            unsigned char b = data[(y * WIDTH + x) * 3 + 0];
            unsigned char avg = (r + g + b) / 3;

            // Convert the average color to an ASCII character
            char c;
            if (avg < 32) {
                c = '#';
            } else if (avg < 64) {
                c = '@';
            } else if (avg < 96) {
                c = '%';
            } else if (avg < 128) {
                c = '*';
            } else if (avg < 160) {
                c = '+';
            } else if (avg < 192) {
                c = '=';
            } else if (avg < 224) {
                c = '-';
            } else {
                c = ' ';
            }

            // Add the character to the ASCII art string
            art[y * WIDTH + x] = c;
        }
    }

    // Print the ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", art[y * WIDTH + x]);
        }
        printf("\n");
    }

    // Free the memory
    free(data);
    free(art);

    return EXIT_SUCCESS;
}