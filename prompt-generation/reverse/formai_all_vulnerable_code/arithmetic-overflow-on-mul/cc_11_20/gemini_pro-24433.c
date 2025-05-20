//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    // Read the image file
    FILE *fp = fopen("image.ppm", "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Get the image dimensions
    int width, height;
    fscanf(fp, "P3 %d %d\n255\n", &width, &height);

    // Allocate memory for the image data
    pixel *image = malloc(sizeof(pixel) * width * height);
    if (image == NULL) {
        perror("Error allocating memory for image data");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the image data
    fread(image, sizeof(pixel), width * height, fp);
    fclose(fp);

    // Convert the image to ASCII art
    char *ascii_art = malloc(sizeof(char) * width * height * 2);
    if (ascii_art == NULL) {
        perror("Error allocating memory for ASCII art");
        free(image);
        return EXIT_FAILURE;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the pixel value
            pixel p = image[y * width + x];

            // Convert the pixel value to a grayscale value
            int grayscale = (p.r + p.g + p.b) / 3;

            // Convert the grayscale value to an ASCII character
            char c;
            if (grayscale < 32) {
                c = ' ';
            } else if (grayscale < 64) {
                c = '.';
            } else if (grayscale < 96) {
                c = ':';
            } else if (grayscale < 128) {
                c = '+';
            } else if (grayscale < 160) {
                c = '=';
            } else if (grayscale < 192) {
                c = '*';
            } else if (grayscale < 224) {
                c = '#';
            } else {
                c = '@';
            }

            // Add the ASCII character to the ASCII art string
            ascii_art[y * width * 2 + x * 2] = c;
            ascii_art[y * width * 2 + x * 2 + 1] = ' ';
        }
    }

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the memory allocated for the image data and the ASCII art string
    free(image);
    free(ascii_art);

    return EXIT_SUCCESS;
}