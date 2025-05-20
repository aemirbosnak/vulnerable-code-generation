//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAY_SCALE_FACTOR 255.0

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Open the input image
    FILE *image_file = fopen("input.jpg", "rb");
    if (!image_file) {
        printf("Error opening input image!\n");
        return 1;
    }

    // Read the image header
    unsigned char header[10];
    fread(header, sizeof(header), 1, image_file);

    // Check if the image is a valid JPEG
    if (header[0] != 0xFF || header[1] != 0xD8) {
        printf("Error: Not a valid JPEG image!\n");
        fclose(image_file);
        return 1;
    }

    // Get the image dimensions
    unsigned short width = header[7] << 8 | header[8];
    unsigned short height = header[9] << 8 | header[10];

    // Allocate memory for the image data
    pixel **image = malloc(sizeof(pixel *) * height);
    for (int i = 0; i < height; i++) {
        image[i] = malloc(sizeof(pixel) * width);
    }

    // Read the image data
    fread(image, sizeof(pixel), width * height, image_file);

    // Convert the image to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate the grayscale value of the pixel
            double grayscale = (image[i][j].red + image[i][j].green + image[i][j].blue) / GRAY_SCALE_FACTOR;

            // Choose an ASCII character based on the grayscale value
            char ascii_char;
            if (grayscale < 0.2) {
                ascii_char = ' ';
            } else if (grayscale < 0.4) {
                ascii_char = '.';
            } else if (grayscale < 0.6) {
                ascii_char = ':';
            } else if (grayscale < 0.8) {
                ascii_char = '~';
            } else {
                ascii_char = '=';
            }

            // Print the ASCII character
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    // Free the memory allocated for the image data
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    // Close the input image
    fclose(image_file);

    return 0;
}