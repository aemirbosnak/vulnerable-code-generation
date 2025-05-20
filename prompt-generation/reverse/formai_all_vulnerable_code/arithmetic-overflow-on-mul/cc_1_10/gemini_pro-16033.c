//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the ASCII character set
char *ascii_chars = " .,-~:;*+=#@%&#$%@"
                    "ABCDEEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";

// Function to convert an image to ASCII art
void image_to_ascii(char *image_file, char *output_file) {
    // Open the image file
    FILE *image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Read the image header
    int width, height;
    fread(&width, sizeof(int), 1, image_fp);
    fread(&height, sizeof(int), 1, image_fp);

    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char *)malloc(width * height * 3);
    if (image_data == NULL) {
        perror("Error allocating memory for image data");
        exit(1);
    }

    // Read the image data
    fread(image_data, sizeof(unsigned char), width * height * 3, image_fp);

    // Close the image file
    fclose(image_fp);

    // Open the output file
    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Convert the image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the average color value for the pixel
            int r = image_data[(y * width + x) * 3 + 0];
            int g = image_data[(y * width + x) * 3 + 1];
            int b = image_data[(y * width + x) * 3 + 2];
            int avg = (r + g + b) / 3;

            // Map the average color value to an ASCII character
            char c = ascii_chars[avg / 8];

            // Write the ASCII character to the output file
            fprintf(output_fp, "%c", c);
        }
        fprintf(output_fp, "\n");
    }

    // Close the output file
    fclose(output_fp);

    // Free the memory allocated for the image data
    free(image_data);
}

// Main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_file>\n", argv[0]);
        exit(1);
    }

    // Convert the image to ASCII art
    image_to_ascii(argv[1], argv[2]);

    return 0;
}