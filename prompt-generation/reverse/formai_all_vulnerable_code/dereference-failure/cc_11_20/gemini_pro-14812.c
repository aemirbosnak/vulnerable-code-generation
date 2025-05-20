//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define WIDTH  800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel image[WIDTH][HEIGHT];

int main() {
    // Load the image from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return 1;
    }

    // Read the header information
    unsigned char header[54];
    fread(header, 54, 1, file);

    // Check that the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file\n");
        return 1;
    }

    // Read the image data
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fread(&image[x][y], sizeof(pixel), 1, file);
        }
    }

    // Close the file
    fclose(file);

    // Process the image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Invert the colors
            image[x][y].r = 255 - image[x][y].r;
            image[x][y].g = 255 - image[x][y].g;
            image[x][y].b = 255 - image[x][y].b;
        }
    }

    // Save the image to a file
    file = fopen("inverted.bmp", "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }

    // Write the header information
    fwrite(header, 54, 1, file);

    // Write the image data
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fwrite(&image[x][y], sizeof(pixel), 1, file);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}