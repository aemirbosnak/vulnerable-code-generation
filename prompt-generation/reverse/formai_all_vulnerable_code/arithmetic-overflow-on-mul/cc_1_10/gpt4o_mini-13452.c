//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ASCII_CHAR 70 // Number of ASCII characters to map brightness levels
#define MAX_WIDTH 1000     // Maximum width of the output ASCII art
#define MAX_HEIGHT 1000    // Maximum height of the output ASCII art

// Function prototypes
void print_ascii_art(unsigned char *image, int width, int height);
unsigned char *read_pgm(const char *filename, int *width, int *height);
void free_image(unsigned char *image);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_image.pgm>\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char *image = read_pgm(argv[1], &width, &height);
    if (!image) {
        fprintf(stderr, "Failed to read the image.\n");
        return 1;
    }

    print_ascii_art(image, width, height);
    free_image(image);
    return 0;
}

// Function to read a PGM file
unsigned char *read_pgm(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Read the PGM header
    char header[3];
    fscanf(file, "%s", header);
    if (header[0] != 'P' || header[1] != '5') {
        fprintf(stderr, "Unsupported PGM format.\n");
        fclose(file);
        return NULL;
    }

    // Read image dimensions and maximum grayscale value
    fscanf(file, "%d %d", width, height);
    int max_gray;
    fscanf(file, "%d", &max_gray);

    // Allocate memory for the image data
    unsigned char *image = (unsigned char *)malloc((*width) * (*height));
    if (!image) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(image, sizeof(unsigned char), (*width) * (*height), file);
    fclose(file);
    return image;
}

// Function to print ASCII art based on image brightness levels
void print_ascii_art(unsigned char *image, int width, int height) {
    const char ascii_chars[MAX_ASCII_CHAR] = " .:-=+*%@#";
    double step = 256.0 / MAX_ASCII_CHAR; // Create a mapping from grayscale values to ASCII chars

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = y * width + x;
            unsigned char pixel_value = image[pixel_index];

            // Map the pixel value to an ASCII character
            int ascii_index = (int)(pixel_value / step);
            ascii_index = ascii_index >= MAX_ASCII_CHAR ? MAX_ASCII_CHAR - 1 : ascii_index;
            putchar(ascii_chars[ascii_index]);
        }
        putchar('\n'); // Move to the next line after one row is printed
    }
}

// Function to free image memory
void free_image(unsigned char *image) {
    free(image);
}