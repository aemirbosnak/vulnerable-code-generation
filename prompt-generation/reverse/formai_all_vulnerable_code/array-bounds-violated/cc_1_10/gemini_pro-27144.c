//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

// Define the ASCII character set
char *ASCII_CHARS = " .,-~:;=*#%@";

// Load an image from a file
unsigned char *load_image(char *filename, int *width, int *height) {
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        return NULL;
    }

    // Read the image header
    unsigned char header[18];
    fread(header, 1, 18, fp);

    // Check if the image is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Image is not a BMP file\n");
        fclose(fp);
        return NULL;
    }

    // Get the image width and height
    *width = header[18] + (header[19] << 8);
    *height = header[22] + (header[23] << 8);

    // Allocate memory for the image data
    unsigned char *data = malloc(*width * *height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, 1, *width * *height * 3, fp);

    // Close the image file
    fclose(fp);

    // Return the image data
    return data;
}

// Convert an image to ASCII art
char *image_to_ascii(unsigned char *data, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii = malloc(width * height + 1);
    if (ascii == NULL) {
        fprintf(stderr, "Error allocating memory for ASCII art\n");
        return NULL;
    }

    // Convert the image data to ASCII art
    for (int i = 0; i < width * height; i++) {
        // Get the average color value
        int color = (data[i * 3] + data[i * 3 + 1] + data[i * 3 + 2]) / 3;

        // Map the color value to an ASCII character
        ascii[i] = ASCII_CHARS[color * strlen(ASCII_CHARS) / 256];
    }

    // Add a newline character to the end of the ASCII art
    ascii[width * height] = '\n';

    // Return the ASCII art
    return ascii;
}

// Save the ASCII art to a file
void save_ascii(char *ascii, char *filename) {
    // Open the ASCII art file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening ASCII art file: %s\n", filename);
        return;
    }

    // Write the ASCII art to the file
    fprintf(fp, "%s", ascii);

    // Close the ASCII art file
    fclose(fp);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified an input image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image file> <output ASCII art file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the image from the file
    int width, height;
    unsigned char *data = load_image(argv[1], &width, &height);
    if (data == NULL) {
        return EXIT_FAILURE;
    }

    // Convert the image to ASCII art
    char *ascii = image_to_ascii(data, width, height);
    if (ascii == NULL) {
        return EXIT_FAILURE;
    }

    // Save the ASCII art to the output file
    save_ascii(ascii, argv[2]);

    // Free the memory allocated for the image data and ASCII art
    free(data);
    free(ascii);

    return EXIT_SUCCESS;
}