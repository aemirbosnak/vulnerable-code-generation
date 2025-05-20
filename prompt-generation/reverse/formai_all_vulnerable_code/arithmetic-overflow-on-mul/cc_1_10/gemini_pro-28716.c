//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Define the number of ASCII characters to use
#define NUM_CHARS 256

// Define the ASCII characters to use
char *chars = " .-~:;#*=%@";

// Convert an image to ASCII art
void image_to_ascii(char *filename) {
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the image header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Create an array to store the image data
    unsigned char *data = (unsigned char *)malloc(width * height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(1);
    }

    // Read the image data
    fread(data, sizeof(unsigned char), width * height * 3, fp);

    // Close the image file
    fclose(fp);

    // Convert the image data to ASCII art
    char *ascii_art = (char *)malloc(width * height * sizeof(char));
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the RGB values of the pixel
            int r = data[3 * (y * width + x)];
            int g = data[3 * (y * width + x) + 1];
            int b = data[3 * (y * width + x) + 2];

            // Calculate the luminance of the pixel
            double luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b;

            // Map the luminance to an ASCII character
            int index = (int)(luminance / 255.0 * (NUM_CHARS - 1));
            char c = chars[index];

            // Store the ASCII character in the output array
            ascii_art[y * width + x] = c;
        }
    }

    // Print the ASCII art to the console
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii_art[y * width + x]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image data and the ASCII art
    free(data);
    free(ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided an image filename
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Convert the image to ASCII art
    image_to_ascii(argv[1]);

    return 0;
}