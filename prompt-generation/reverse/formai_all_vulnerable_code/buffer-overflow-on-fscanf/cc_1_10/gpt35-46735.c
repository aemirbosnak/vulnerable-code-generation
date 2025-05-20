//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters to use
static char *ASCII_CHARS = " .:-=+*#%@";

// Define the dimensions of the ASCII art
const int WIDTH = 80;
const int HEIGHT = 80;

// Define a function to convert an RGB pixel to a grayscale value
unsigned char rgb_to_gray(unsigned char r, unsigned char g, unsigned char b) {
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check that the user provides a file path argument
    if (argc < 2) {
        printf("Error: No input file provided.\n");
        return 1;
    }

    // Open the input file
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read the image header
    int width, height, maxval;
    char magic[3];
    fscanf(input, "%2s\n%d %d\n%d\n", magic, &width, &height, &maxval);

    // Check that the image format is P6 (RGB)
    if (strcmp(magic, "P6") != 0) {
        printf("Error: Unsupported image format.\n");
        fclose(input);
        return 1;
    }

    // Check that the image dimensions match the ASCII art dimensions
    if (width != WIDTH || height != HEIGHT) {
        printf("Error: Image dimensions do not match ASCII art dimensions.\n");
        fclose(input);
        return 1;
    }

    // Allocate memory for the RGB pixel data
    unsigned char *rgb_data = (unsigned char *) malloc(width * height * 3);
    
    // Read the RGB pixel data from the input file
    fread(rgb_data, sizeof(unsigned char), width * height * 3, input);
    
    // Close the input file
    fclose(input);

    // Allocate memory for the grayscale pixel data
    unsigned char *gray_data = (unsigned char *) malloc(width * height);

    // Convert the RGB pixel data to grayscale
    for (int i = 0; i < width * height * 3; i += 3) {
        gray_data[i / 3] = rgb_to_gray(rgb_data[i], rgb_data[i + 1], rgb_data[i + 2]);
    }

    // Free the RGB pixel data
    free(rgb_data);

    // Create the output string
    char *output = (char *) malloc(WIDTH * HEIGHT + HEIGHT);

    // Loop over each pixel and convert it to the corresponding ASCII character
    for (int i = 0; i < width * height; i++) {
        int index = (gray_data[i] * 10) / 255;
        if (index > 9) {
            index = 9;
        }
        output[i % WIDTH + (i / WIDTH) * (WIDTH + 1)] = ASCII_CHARS[index];
    }
    output[WIDTH * HEIGHT + HEIGHT - 1] = '\0';

    // Output the ASCII art to the console
    printf("%s\n", output);

    // Free the grayscale pixel data and output string
    free(gray_data);
    free(output);

    return 0;
}