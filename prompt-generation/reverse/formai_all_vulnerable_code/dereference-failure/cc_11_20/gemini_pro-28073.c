//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.jpg>\n", argv[0]);
        return 1;
    }

    // Load the image from file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    // Read the image header
    unsigned char header[10];
    fread(header, sizeof(unsigned char), 10, fp);

    // Check if the image is a JPEG
    if (header[0] != 0xFF || header[1] != 0xD8) {
        fprintf(stderr, "File %s is not a JPEG\n", argv[1]);
        return 1;
    }

    // Read the image dimensions
    unsigned short width, height;
    fread(&width, sizeof(unsigned short), 1, fp);
    fread(&height, sizeof(unsigned short), 1, fp);

    // Check if the image is too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image %s is too large\n", argv[1]);
        return 1;
    }

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height);
    if (data == NULL) {
        fprintf(stderr, "Could not allocate memory for image data\n");
        return 1;
    }

    // Read the image data
    fread(data, sizeof(unsigned char), width * height, fp);

    // Close the file
    fclose(fp);

    // Convert the image to ASCII art
    char *ascii_art = malloc(width * height + 1);
    if (ascii_art == NULL) {
        fprintf(stderr, "Could not allocate memory for ASCII art\n");
        return 1;
    }

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the pixel value
            unsigned char pixel = data[y * width + x];

            // Convert the pixel value to an ASCII character
            char character;
            if (pixel < 32) {
                character = ' ';
            } else if (pixel < 64) {
                character = '.';
            } else if (pixel < 96) {
                character = ':';
            } else if (pixel < 128) {
                character = 'o';
            } else if (pixel < 160) {
                character = '8';
            } else if (pixel < 192) {
                character = '#';
            } else {
                character = '@';
            }

            // Add the character to the ASCII art string
            ascii_art[index++] = character;
        }

        // Add a newline character to the ASCII art string
        ascii_art[index++] = '\n';
    }

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the memory allocated for the ASCII art
    free(ascii_art);

    // Free the memory allocated for the image data
    free(data);

    return 0;
}