//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Read the header
    unsigned char header[14];
    fread(header, 14, 1, fp);

    // Check if it's a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Invalid BMP file\n");
        fclose(fp);
        return 1;
    }

    // Get the image dimensions
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (data == NULL) {
        perror("malloc");
        fclose(fp);
        return 1;
    }

    // Read the image data
    fread(data, width * height * 3, 1, fp);

    // Convert the image to ASCII art
    char *ascii = malloc(width * height + 1);
    if (ascii == NULL) {
        perror("malloc");
        free(data);
        fclose(fp);
        return 1;
    }

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            // Get the average color value
            unsigned char r = data[(y * width + x) * 3 + 2];
            unsigned char g = data[(y * width + x) * 3 + 1];
            unsigned char b = data[(y * width + x) * 3 + 0];
            unsigned char avg = (r + g + b) / 3;

            // Convert the average color value to an ASCII character
            char c;
            if (avg < 32) {
                c = ' ';
            } else if (avg < 64) {
                c = '.';
            } else if (avg < 96) {
                c = '*';
            } else if (avg < 128) {
                c = '#';
            } else if (avg < 160) {
                c = '&';
            } else if (avg < 192) {
                c = '@';
            } else {
                c = '%';
            }

            // Add the ASCII character to the output string
            ascii[y * width + x] = c;
        }
    }

    // Add a newline character to the end of the output string
    ascii[width * height] = '\0';

    // Print the ASCII art to the console
    printf("%s", ascii);

    // Free the memory allocated for the image data and the ASCII art
    free(data);
    free(ascii);

    // Close the file
    fclose(fp);

    return 0;
}