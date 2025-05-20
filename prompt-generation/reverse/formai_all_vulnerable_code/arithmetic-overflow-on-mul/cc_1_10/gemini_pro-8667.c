//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert an image to ASCII art
void image_to_ascii(char *filename) {
    // Open the image file
    FILE *image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        printf("Error opening image file: %s\n", filename);
        return;
    }

    // Read the image header
    unsigned char header[26];
    fread(header, sizeof(header), 1, image_file);

    // Check if the image is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: Invalid BMP file\n");
        fclose(image_file);
        return;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Create a 2D array to store the pixel data
    unsigned char **pixels = (unsigned char **)malloc(height * sizeof(unsigned char *));
    for (int i = 0; i < height; i++) {
        pixels[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
    }

    // Read the pixel data
    fread(pixels, width * height, 1, image_file);

    // Close the image file
    fclose(image_file);

    // Convert the pixel data to ASCII art
    char **ascii_art = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = (char *)malloc(width * sizeof(char));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the pixel value
            unsigned char pixel = pixels[i][j];

            // Convert the pixel value to an ASCII character
            char character;
            if (pixel < 32) {
                character = ' ';
            } else if (pixel < 64) {
                character = '.';
            } else if (pixel < 96) {
                character = ':';
            } else if (pixel < 128) {
                character = '*';
            } else if (pixel < 160) {
                character = 'O';
            } else if (pixel < 192) {
                character = '@';
            } else if (pixel < 224) {
                character = '#';
            } else {
                character = '$';
            }

            // Store the ASCII character in the ASCII art array
            ascii_art[i][j] = character;
        }
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    // Free the memory allocated for the pixel data and the ASCII art array
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
        free(ascii_art[i]);
    }
    free(pixels);
    free(ascii_art);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified an image file
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Convert the image file to ASCII art
    image_to_ascii(argv[1]);

    return 0;
}