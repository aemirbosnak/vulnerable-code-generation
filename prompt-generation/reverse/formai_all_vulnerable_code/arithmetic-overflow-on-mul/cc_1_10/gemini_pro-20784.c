//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ASCII_CHARS 100

// Define the ASCII characters to use for the image
char ascii_chars[MAX_ASCII_CHARS] = {
    ' ', '.', ',', '-', '_', ':', ';', '|', '/', '\\',
    '(', ')', '[', ']', '{', '}', 'L', '1', 'I', '!',
    'o', '0', 'a', 'A', '8', 'g', '@', '#', '%', '?',
    'M', 'W', 'E', 'q', '$', 'u', 'n', 'c', 'r', 'x',
    'v', 'k', 'b', 'j', 'h', 'f', 'p', 'z', 'd', 's',
    'y', 't', 'X', 'Q', 'O', 'Y', 'G', 'J', 'P', 'Z',
    'F', 'U', 'N', 'C', 'R', 'B', 'D', 'H', 'V', 'K',
    'W', '1', 'L', '0', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

// Function to convert an image to ASCII art
char *image_to_ascii(unsigned char *image_data, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii_art = malloc(width * height + 1);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return NULL;
    }

    // Convert the image data to ASCII art
    for (int i = 0; i < width * height; i++) {
        // Get the pixel value
        unsigned char pixel_value = image_data[i];

        // Map the pixel value to an ASCII character
        int index = (int) ((pixel_value / 255.0) * (MAX_ASCII_CHARS - 1));
        ascii_art[i] = ascii_chars[index];
    }

    // Add a newline character to the end of the ASCII art
    ascii_art[width * height] = '\0';

    // Return the ASCII art
    return ascii_art;
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided an image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Read the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error: fopen failed\n");
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);

    // Check if the image dimensions are valid
    if (width <= 0 || height <= 0) {
        fprintf(stderr, "Error: invalid image dimensions\n");
        return 1;
    }

    // Read the image data
    unsigned char *image_data = malloc(width * height);
    if (image_data == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return 1;
    }
    fread(image_data, sizeof(unsigned char), width * height, image_file);

    // Close the image file
    fclose(image_file);

    // Convert the image to ASCII art
    char *ascii_art = image_to_ascii(image_data, width, height);
    if (ascii_art == NULL) {
        return 1;
    }

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the memory allocated for the ASCII art
    free(ascii_art);
    free(image_data);

    return 0;
}