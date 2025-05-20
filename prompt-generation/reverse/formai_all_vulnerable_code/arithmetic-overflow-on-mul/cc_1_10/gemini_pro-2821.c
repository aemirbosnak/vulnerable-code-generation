//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Define the number of ASCII characters to use
#define NUM_CHARS 70

// Define the ASCII characters to use
char chars[] = " .:-=+*#%@";

// Convert an image to ASCII art
void image_to_ascii(const char *filename) {
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return;
    }

    // Read the image header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Check if the image is too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image is too large (%dx%d)\n", width, height);
        fclose(fp);
        return;
    }

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height);
    if (data == NULL) {
        perror("Error allocating memory for image data");
        fclose(fp);
        return;
    }

    // Read the image data
    fread(data, sizeof(unsigned char), width * height, fp);

    // Close the image file
    fclose(fp);

    // Convert the image data to ASCII art
    char *ascii = malloc(width * height);
    if (ascii == NULL) {
        perror("Error allocating memory for ASCII art");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the brightness of the pixel
            int brightness = data[y * width + x];

            // Map the brightness to an ASCII character
            int index = (int) round(((double) brightness / 255) * (NUM_CHARS - 1));
            ascii[y * width + x] = chars[index];
        }
    }

    // Print the ASCII art to the console
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii[y * width + x]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(data);
    free(ascii);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified an image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Convert the image to ASCII art
    image_to_ascii(argv[1]);

    return 0;
}