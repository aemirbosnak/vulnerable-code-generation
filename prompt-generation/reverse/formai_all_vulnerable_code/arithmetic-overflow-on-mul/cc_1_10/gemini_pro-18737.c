//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // Read the BMP header
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", argv[1]);
        return 1;
    }

    // Get the image dimensions
    int width = header[18] + (header[19] << 8);
    int height = header[22] + (header[23] << 8);

    // Allocate memory for the image data
    pixel *data = malloc(width * height * sizeof(pixel));
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        return 1;
    }

    // Read the image data
    fread(data, width * height * sizeof(pixel), 1, fp);

    // Close the file
    fclose(fp);

    // Convert the image data to ASCII art
    char *art = malloc(width * height * sizeof(char));
    if (art == NULL) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        return 1;
    }

    for (int i = 0; i < width * height; i++) {
        art[i] = " .-:=+*#%@";
        art[i] = (data[i].r + data[i].g + data[i].b) / 3 / 256 * 7;
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", art[i * width + j]);
        }
        printf("\n");
    }

    // Free the memory
    free(data);
    free(art);

    return 0;
}