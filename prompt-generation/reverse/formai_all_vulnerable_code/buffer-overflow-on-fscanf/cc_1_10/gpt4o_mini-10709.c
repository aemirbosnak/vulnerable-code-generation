//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define an ASCII character set for brightness levels
const char *ASCII_CHARS = "@#S%?*+;:,. ";

// Function to map pixel brightness to ASCII characters
char map_pixel_to_ascii(uint8_t pixel) {
    int index = (pixel * (strlen(ASCII_CHARS) - 1)) / 255;
    return ASCII_CHARS[index];
}

// Function to load an image from a PGM file
void load_image(const char *filename, uint8_t image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read image header
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P2") != 0) {
        fprintf(stderr, "Unsupported file format!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read width and height
    fscanf(file, "%d %d", width, height);
    fgetc(file); // Read the newline after the dimensions
    
    // Ensure dimensions do not exceed limits
    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed maximum limits!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read maximum pixel value (should be 255)
    int max_pixel_value;
    fscanf(file, "%d", &max_pixel_value);
    fgetc(file); // Read the newline after the max pixel value

    // Read pixel data
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            int pixel;
            fscanf(file, "%d", &pixel);
            image[i][j] = (uint8_t) pixel;
        }
    }

    fclose(file);
}

// Function to convert image to ASCII art
void convert_to_ascii(uint8_t image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char ascii_char = map_pixel_to_ascii(image[i][j]);
            putchar(ascii_char);
        }
        putchar('\n'); // Move to the next line after each row
    }
}

// Main function to run the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Prepare the image array
    uint8_t image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    // Load the image
    load_image(argv[1], image, &width, &height);

    // Convert and display the ASCII art
    convert_to_ascii(image, width, height);

    return EXIT_SUCCESS;
}