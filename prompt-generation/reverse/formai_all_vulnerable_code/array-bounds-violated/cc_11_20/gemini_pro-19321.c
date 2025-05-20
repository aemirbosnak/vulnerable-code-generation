//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file_name = argv[1];

    FILE *file = fopen(file_name, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", file_name);
        return EXIT_FAILURE;
    }

    // Read the BMP file header
    unsigned char header[54];
    fread(header, 54, 1, file);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixel data
    unsigned char pixels[width * height * 3];
    fread(pixels, width * height * 3, 1, file);
    fclose(file);

    // Convert the pixel data to ASCII art
    char ascii_art[MAX_WIDTH * MAX_HEIGHT + 1];
    int i, j, k;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Get the pixel value
            int r = pixels[i * width * 3 + j * 3];
            int g = pixels[i * width * 3 + j * 3 + 1];
            int b = pixels[i * width * 3 + j * 3 + 2];

            // Convert the pixel value to an ASCII character
            char c;
            if (r > g && r > b) {
                c = '@';
            } else if (g > r && g > b) {
                c = '%';
            } else if (b > r && b > g) {
                c = '#';
            } else {
                c = ' ';
            }

            // Add the ASCII character to the output string
            ascii_art[i * width + j] = c;
        }
    }

    // Terminate the output string
    ascii_art[i * width + j] = '\0';

    // Print the ASCII art to the console
    printf("%s\n", ascii_art);

    return EXIT_SUCCESS;
}