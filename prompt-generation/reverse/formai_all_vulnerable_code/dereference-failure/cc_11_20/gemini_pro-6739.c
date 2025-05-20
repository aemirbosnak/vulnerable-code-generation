//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

void main() {
    char *image = "image.bmp";
    FILE *f = fopen(image, "rb");
    if (f == NULL) {
        printf("Error opening file %s\n", image);
        exit(1);
    }

    // Read header
    unsigned char header[54];
    fread(header, sizeof(header), 1, f);

    // Check if file is a valid BMP
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: %s is not a valid BMP file\n", image);
        exit(1);
    }

    // Read image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Check if image is within bounds
    if (width > WIDTH || height > HEIGHT) {
        printf("Error: Image dimensions are too large\n");
        exit(1);
    }

    // Read color palette
    unsigned char palette[1024];
    fread(palette, sizeof(palette), 1, f);

    // Create output image
    char *output = malloc(WIDTH * HEIGHT);
    memset(output, ' ', WIDTH * HEIGHT);

    // Convert image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Read pixel color
            unsigned char color[3];
            fread(color, sizeof(color), 1, f);

            // Convert color to grayscale
            int gray = (int)(color[0] * 0.2126 + color[1] * 0.7152 + color[2] * 0.0722);

            // Choose ASCII character based on grayscale value
            char c;
            if (gray < 32) {
                c = '#';
            } else if (gray < 64) {
                c = '&';
            } else if (gray < 96) {
                c = '@';
            } else if (gray < 128) {
                c = ':';
            } else if (gray < 160) {
                c = '*';
            } else if (gray < 192) {
                c = '.';
            } else {
                c = ' ';
            }

            // Write ASCII character to output image
            output[y * WIDTH + x] = c;
        }
    }

    // Print output image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", output[y * WIDTH + x]);
        }
        printf("\n");
    }

    // Free memory
    free(output);
    fclose(f);
}