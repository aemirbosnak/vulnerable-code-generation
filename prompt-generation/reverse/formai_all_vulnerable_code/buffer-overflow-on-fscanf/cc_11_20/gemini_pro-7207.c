//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

int main() {
    // Read the image from a file
    FILE *fp = fopen("image.ppm", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Parse the header
    char header[100];
    if (fscanf(fp, "%s", header) != 1) {
        perror("Error reading header");
        return EXIT_FAILURE;
    }

    if (strcmp(header, "P3") != 0) {
        fprintf(stderr, "Error: Invalid header\n");
        return EXIT_FAILURE;
    }

    int width, height, maxval;
    if (fscanf(fp, "%d %d %d", &width, &height, &maxval) != 3) {
        perror("Error reading header");
        return EXIT_FAILURE;
    }

    // Read the image data
    unsigned char *data = malloc(width * height * 3);
    if (data == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    if (fread(data, 1, width * height * 3, fp) != width * height * 3) {
        perror("Error reading image data");
        return EXIT_FAILURE;
    }

    fclose(fp);

    // Convert the image to ASCII art
    char *ascii_art = malloc(width * height + 1);
    if (ascii_art == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the average color value
            int r = (int)data[3 * (y * width + x)];
            int g = (int)data[3 * (y * width + x) + 1];
            int b = (int)data[3 * (y * width + x) + 2];
            int avg = (r + g + b) / 3;

            // Convert the average color value to an ASCII character
            char c;
            if (avg < 64) {
                c = '#';
            } else if (avg < 128) {
                c = '=';
            } else if (avg < 192) {
                c = '-';
            } else {
                c = ' ';
            }

            // Add the ASCII character to the output string
            ascii_art[y * width + x] = c;
        }
    }

    // Add a newline character to the end of the output string
    ascii_art[width * height] = '\0';

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the memory allocated for the image data and the ASCII art
    free(data);
    free(ascii_art);

    return EXIT_SUCCESS;
}