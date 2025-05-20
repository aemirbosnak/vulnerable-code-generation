//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    FILE *image, *output;
    int width, height;
    pixel **pixels;

    image = fopen("image.bmp", "rb");
    if (image == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read the header information
    fread(&width, sizeof(int), 1, image);
    fread(&height, sizeof(int), 1, image);

    // Allocate memory for the pixels
    pixels = malloc(height * sizeof(pixel *));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(pixel));
    }

    // Read the pixel data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&pixels[i][j].b, sizeof(unsigned char), 1, image);
            fread(&pixels[i][j].g, sizeof(unsigned char), 1, image);
            fread(&pixels[i][j].r, sizeof(unsigned char), 1, image);
        }
    }

    fclose(image);

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Convert the pixels to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double brightness = (pixels[i][j].r + pixels[i][j].g + pixels[i][j].b) / 3.0;
            char character;

            if (brightness < 32) {
                character = ' ';
            } else if (brightness < 64) {
                character = '.';
            } else if (brightness < 96) {
                character = ',';
            } else if (brightness < 128) {
                character = '-';
            } else if (brightness < 160) {
                character = '=';
            } else if (brightness < 192) {
                character = '+';
            } else if (brightness < 224) {
                character = '*';
            } else {
                character = '#';
            }

            fprintf(output, "%c", character);
        }
        fprintf(output, "\n");
    }

    fclose(output);

    return 0;
}