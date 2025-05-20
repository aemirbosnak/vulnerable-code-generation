//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the ASCII characters used for the conversion
char ascii_chars[] = " .,-~:;=!*#$@";

// Get the brightness of a pixel
int get_brightness(int r, int g, int b) {
    return (r + g + b) / 3;
}

// Convert an image to ASCII art
char *image_to_ascii(unsigned char *image, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii_art = malloc(width * height + 1);

    // Convert each pixel to an ASCII character
    for (int i = 0; i < width * height; i++) {
        // Get the pixel's brightness
        int brightness = get_brightness(image[i * 3], image[i * 3 + 1], image[i * 3 + 2]);

        // Convert the brightness to an ASCII character
        ascii_art[i] = ascii_chars[brightness * (sizeof(ascii_chars) - 1) / 255];
    }

    // Add a newline character to the end of the ASCII art
    ascii_art[width * height] = '\0';

    // Return the ASCII art
    return ascii_art;
}

// Print the ASCII art to the console
void print_ascii_art(char *ascii_art, int width, int height) {
    // Print each line of the ASCII art
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art + i * width);
    }
}

// Free the memory allocated for the ASCII art
void free_ascii_art(char *ascii_art) {
    free(ascii_art);
}

// Load an image from a file
unsigned char *load_image(char *filename, int *width, int *height) {
    // Open the image file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the image header
    unsigned char header[18];
    fread(header, 18, 1, file);

    // Check if the image is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image width and height
    *width = header[18] + (header[19] << 8);
    *height = header[22] + (header[23] << 8);

    // Check if the image is too large
    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Error: image %s is too large\n", filename);
        fclose(file);
        return NULL;
    }

    // Allocate memory for the image data
    unsigned char *image = malloc(*width * *height * 3);
    if (image == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(image, *width * *height * 3, 1, file);

    // Close the image file
    fclose(file);

    // Return the image data
    return image;
}

// Save an image to a file
void save_image(char *filename, unsigned char *image, int width, int height) {
    // Open the image file
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the image header
    unsigned char header[18];
    header[0] = 'B';
    header[1] = 'M';
    header[2] = (width * height * 3) & 0xFF;
    header[3] = ((width * height * 3) >> 8) & 0xFF;
    header[4] = 0;
    header[5] = 0;
    header[6] = 0;
    header[7] = 0;
    header[8] = 40;
    header[9] = 0;
    header[10] = 0;
    header[11] = 0;
    header[12] = width & 0xFF;
    header[13] = (width >> 8) & 0xFF;
    header[14] = height & 0xFF;
    header[15] = (height >> 8) & 0xFF;
    header[16] = 24;
    header[17] = 0;
    fwrite(header, 18, 1, file);

    // Write the image data
    fwrite(image, width * height * 3, 1, file);

    // Close the image file
    fclose(file);
}

// The main function
int main(int argc, char **argv) {
    // Check if the user specified an input image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image file>\n", argv[0]);
        return 1;
    }

    // Load the input image file
    int width, height;
    unsigned char *image = load_image(argv[1], &width, &height);
    if (image == NULL) {
        return 1;
    }

    // Convert the image to ASCII art
    char *ascii_art = image_to_ascii(image, width, height);

    // Print the ASCII art to the console
    print_ascii_art(ascii_art, width, height);

    // Free the memory allocated for the ASCII art
    free_ascii_art(ascii_art);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}