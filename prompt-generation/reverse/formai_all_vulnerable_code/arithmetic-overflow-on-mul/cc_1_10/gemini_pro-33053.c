//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read the image data from a file
int readImage(char *filename, unsigned char **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    // Read the header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Get the width and height of the image
    *width = header[18] + (header[19] << 8);
    *height = header[22] + (header[23] << 8);

    // Allocate memory for the image data
    *image = (unsigned char *)malloc(*width * *height);

    // Read the image data
    fread(*image, sizeof(unsigned char), *width * *height, file);

    fclose(file);

    return 0;
}

// Function to convert the image data to ASCII art
void convertToAscii(unsigned char *image, int width, int height) {
    // Create a 2D array to store the ASCII art
    char **asciiArt = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        asciiArt[i] = (char *)malloc(width * sizeof(char));
    }

    // Convert each pixel to an ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the pixel value
            unsigned char pixel = image[i * width + j];

            // Convert the pixel value to an ASCII character
            char character = ' ';
            if (pixel < 32) {
                character = '@';
            } else if (pixel < 64) {
                character = '%';
            } else if (pixel < 96) {
                character = '#';
            } else if (pixel < 128) {
                character = '*';
            } else if (pixel < 160) {
                character = '+';
            } else if (pixel < 192) {
                character = '=';
            } else if (pixel < 224) {
                character = '-';
            } else {
                character = ' ';
            }

            // Store the ASCII character in the 2D array
            asciiArt[i][j] = character;
        }
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the 2D array
    for (int i = 0; i < height; i++) {
        free(asciiArt[i]);
    }
    free(asciiArt);
}

// Main function
int main() {
    // Declare the variables
    unsigned char *image;
    int width, height;

    // Read the image data from the file
    if (readImage("image.bmp", &image, &width, &height) != 0) {
        printf("Error reading image file\n");
        return -1;
    }

    // Convert the image data to ASCII art
    convertToAscii(image, width, height);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}