//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    // Open the image file
    FILE *image = fopen("image.bmp", "rb");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return 1;
    }

    // Read the header information
    unsigned char header[54];
    fread(header, sizeof(header), 1, image);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Not a valid BMP file\n");
        return 1;
    }

    // Get the image dimensions
    unsigned int width = *(unsigned int *)(header + 18);
    unsigned int height = *(unsigned int *)(header + 22);

    // Allocate memory for the image data
    pixel *data = malloc(width * height * sizeof(pixel));
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        return 1;
    }

    // Read the image data
    fread(data, width * height * sizeof(pixel), 1, image);

    // Close the image file
    fclose(image);

    // Convert the image to ASCII art
    char *ascii = malloc(width * height * sizeof(char));
    if (ascii == NULL) {
        fprintf(stderr, "Error allocating memory for ASCII art\n");
        return 1;
    }

    for (int i = 0; i < width * height; i++) {
        // Get the RGB values of the pixel
        unsigned char r = data[i].r;
        unsigned char g = data[i].g;
        unsigned char b = data[i].b;

        // Calculate the ASCII character that corresponds to the pixel
        char c;
        if (r + g + b < 128) {
            c = '#';
        } else if (r + g + b < 256) {
            c = '.';
        } else {
            c = ' ';
        }

        // Set the ASCII character in the output array
        ascii[i] = c;
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i * width + j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image data and ASCII art
    free(data);
    free(ascii);

    return 0;
}