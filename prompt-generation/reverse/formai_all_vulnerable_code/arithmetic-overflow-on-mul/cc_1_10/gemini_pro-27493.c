//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

// Define the characters used to represent the different shades of gray
char *shades = " .:-=+*#%@";

// Read the image from a file
unsigned char *read_image(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Get the width and height of the image
    *width = header[18] + (header[19] << 8);
    *height = header[22] + (header[23] << 8);

    // Allocate memory for the image data
    unsigned char *data = malloc(*width * *height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(1);
    }

    // Read the image data
    fread(data, sizeof(unsigned char), *width * *height * 3, file);

    // Close the file
    fclose(file);

    return data;
}

// Convert the image to ASCII art
char *image_to_ascii(unsigned char *data, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii = malloc(width * height + 1);
    if (ascii == NULL) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        exit(1);
    }

    // Convert each pixel to an ASCII character
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Get the average of the red, green, and blue values
            unsigned char average = (data[i * width * 3 + j * 3] + data[i * width * 3 + j * 3 + 1] + data[i * width * 3 + j * 3 + 2]) / 3;

            // Convert the average to an ASCII character
            ascii[i * width + j] = shades[average / 32];
        }
    }

    // Add a newline character to the end of the ASCII art
    ascii[width * height] = '\n';

    // Return the ASCII art
    return ascii;
}

// Write the ASCII art to a file
void write_ascii(char *ascii, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Write the ASCII art to the file
    fputs(ascii, file);

    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output ASCII art>\n", argv[0]);
        exit(1);
    }

    // Read the image from a file
    int width, height;
    unsigned char *data = read_image(argv[1], &width, &height);

    // Convert the image to ASCII art
    char *ascii = image_to_ascii(data, width, height);

    // Write the ASCII art to a file
    write_ascii(ascii, argv[2]);

    // Free the memory allocated for the image data and ASCII art
    free(data);
    free(ascii);

    return 0;
}