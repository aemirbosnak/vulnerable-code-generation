//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of characters per line
#define MAX_LINE_LENGTH 80

// Define the grayscale values for each ASCII character
#define ASCII_SCALE " .,-~:;=@#%*"

// Read the image file into a buffer
unsigned char *read_image(char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Read the header information
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Extract the width and height from the header
    *width = header[18] | (header[19] << 8);
    *height = header[22] | (header[23] << 8);

    // Allocate memory for the image data
    unsigned char *data = malloc(*width * *height);

    // Read the image data
    fread(data, 1, *width * *height, fp);

    // Close the file
    fclose(fp);

    return data;
}

// Convert the image data to ASCII art
char *image_to_ascii(unsigned char *data, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii = malloc(width * height * sizeof(char));

    // Convert each pixel to an ASCII character
    for (int i = 0; i < width * height; i++) {
        // Calculate the grayscale value of the pixel
        int grayscale = data[i];

        // Find the corresponding ASCII character
        int index = (int) round((double) grayscale / 255 * (strlen(ASCII_SCALE) - 1));
        char c = ASCII_SCALE[index];

        // Store the ASCII character in the buffer
        ascii[i] = c;
    }

    return ascii;
}

// Print the ASCII art to the console
void print_ascii(char *ascii, int width, int height) {
    // Loop through each line of the ASCII art
    for (int i = 0; i < height; i++) {
        // Print the line to the console
        printf("%.*s\n", MAX_LINE_LENGTH, &ascii[i * width]);
    }
}

// Free the memory allocated for the image data and ASCII art
void free_memory(unsigned char *data, char *ascii) {
    free(data);
    free(ascii);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        exit(1);
    }

    // Read the image file
    int width, height;
    unsigned char *data = read_image(argv[1], &width, &height);

    // Convert the image data to ASCII art
    char *ascii = image_to_ascii(data, width, height);

    // Print the ASCII art to the console
    print_ascii(ascii, width, height);

    // Free the memory allocated for the image data and ASCII art
    free_memory(data, ascii);

    return 0;
}