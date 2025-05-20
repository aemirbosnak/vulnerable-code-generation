//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

// ASCII art characters from lightest to darkest
const char *chars = " .:-=+*#%@";

// Read an image file into a 2D array of pixels
unsigned char **read_image(const char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening image file");
        exit(1);
    }

    // Read the header information
    unsigned char header[18];
    fread(header, 1, 18, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid BMP file\n");
        exit(1);
    }

    // Get the image dimensions
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    // Allocate memory for the pixel data
    unsigned char **pixels = malloc(*height * sizeof(unsigned char *));
    for (int i = 0; i < *height; i++) {
        pixels[i] = malloc(*width * sizeof(unsigned char));
    }

    // Read the pixel data
    fread(pixels[0], *width * *height, 1, fp);

    fclose(fp);

    return pixels;
}

// Convert an image to ASCII art
char **image_to_ascii(unsigned char **pixels, int width, int height) {
    char **ascii_art = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = malloc((width + 1) * sizeof(char));
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the pixel value
            unsigned char pixel = pixels[y][x];

            // Convert the pixel value to an ASCII character
            int index = pixel * (strlen(chars) - 1) / 255;
            ascii_art[y][x] = chars[index];
        }
        ascii_art[y][width] = '\0';
    }

    return ascii_art;
}

// Print the ASCII art to the console
void print_ascii_art(char **ascii_art, int height) {
    for (int y = 0; y < height; y++) {
        printf("%s\n", ascii_art[y]);
    }
}

// Free the memory allocated for the image and ASCII art
void free_memory(unsigned char **pixels, int height, char **ascii_art) {
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
        free(ascii_art[i]);
    }
    free(pixels);
    free(ascii_art);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    // Read the image file
    int width, height;
    unsigned char **pixels = read_image(argv[1], &width, &height);

    // Convert the image to ASCII art
    char **ascii_art = image_to_ascii(pixels, width, height);

    // Print the ASCII art to the console
    print_ascii_art(ascii_art, height);

    // Free the memory allocated for the image and ASCII art
    free_memory(pixels, height, ascii_art);

    return 0;
}