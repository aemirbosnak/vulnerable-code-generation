//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Read the header
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if the file is a BMP file
    if (memcmp(header, "BM", 2) != 0) {
        fprintf(stderr, "Error: File is not a BMP file\n");
        fclose(fp);
        return 1;
    }

    // Get the image dimensions
    int width = *(int *)(header + 18);
    int height = *(int *)(header + 22);

    // Create a buffer for the image data
    pixel *image = malloc(width * height * sizeof(pixel));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return 1;
    }

    // Read the image data
    fread(image, sizeof(pixel), width * height, fp);
    fclose(fp);

    // Convert the image to ASCII art
    char *asciiArt = malloc(WIDTH * HEIGHT * sizeof(char));
    if (asciiArt == NULL) {
        perror("malloc");
        free(image);
        return 1;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the pixel value
            pixel p = image[y * width + x];

            // Convert the pixel value to an ASCII character
            char c;
            if (p.r > 255 * 0.75) {
                c = '#';
            } else if (p.r > 255 * 0.5) {
                c = '&';
            } else if (p.r > 255 * 0.25) {
                c = '@';
            } else {
                c = ' ';
            }

            // Add the character to the ASCII art buffer
            asciiArt[y * WIDTH + x] = c;
        }
    }

    // Print the ASCII art to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", asciiArt[y * WIDTH + x]);
        }
        printf("\n");
    }

    // Free the memory
    free(image);
    free(asciiArt);

    return 0;
}