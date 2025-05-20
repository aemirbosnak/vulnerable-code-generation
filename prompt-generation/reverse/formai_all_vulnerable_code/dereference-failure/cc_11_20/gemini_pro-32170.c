//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Read the image header
    unsigned char header[14];
    fread(header, 1, 14, fp);

    // Check if the file is a valid BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid BMP file\n");
        return 1;
    }

    // Read the image dimensions
    unsigned int width = *(unsigned int *)(header + 18);
    unsigned int height = *(unsigned int *)(header + 22);

    // Check if the image is too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image is too large (%dx%d)\n", width, height);
        return 1;
    }

    // Read the image data
    unsigned char *data = malloc(width * height * 3);
    fread(data, 1, width * height * 3, fp);

    // Close the image file
    fclose(fp);

    // Convert the image to ASCII art
    char *ascii_art = malloc(width * height + 1);
    for (int i = 0; i < width * height; i++) {
        // Calculate the average color of the pixel
        unsigned char r = data[i * 3];
        unsigned char g = data[i * 3 + 1];
        unsigned char b = data[i * 3 + 2];
        unsigned char avg = (r + g + b) / 3;

        // Convert the average color to an ASCII character
        char c;
        if (avg < 32) {
            c = '@';
        } else if (avg < 64) {
            c = '%';
        } else if (avg < 96) {
            c = '#';
        } else if (avg < 128) {
            c = '+';
        } else if (avg < 160) {
            c = '=';
        } else if (avg < 192) {
            c = '*';
        } else if (avg < 224) {
            c = ':';
        } else {
            c = ' ';
        }

        // Add the ASCII character to the output string
        ascii_art[i] = c;
    }

    // Add a newline character to the end of the output string
    ascii_art[width * height] = '\0';

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the memory allocated for the ASCII art
    free(ascii_art);

    return 0;
}