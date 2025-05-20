//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Constants defining the ASCII characters to use for brightness levels
#define ASCII_CHARS "@%#*+=-:. " // Descending order of brightness

// Function to read the image file and return pixel data and dimensions
uint8_t* read_image(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return NULL;
    }

    // Read image dimensions (assumed to be a simple gray format)
    fseek(file, 18, SEEK_SET); // Width offset
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);

    // Allocate memory for the pixel data
    uint8_t* pixels = (uint8_t*)malloc((*width) * (*height));
    fseek(file, 54, SEEK_SET); // Pixel data offset

    // Read pixel data
    fread(pixels, 1, (*width) * (*height), file);
    
    fclose(file);
    return pixels;
}

// Function to convert pixel values into ASCII characters
char pixel_to_ascii(uint8_t pixel) {
    int index = (pixel * (sizeof(ASCII_CHARS) - 1)) / 255; // Map to ASCII chars
    return ASCII_CHARS[index];
}

// Function to convert the pixel data into ASCII art
void image_to_ascii(uint8_t* pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t pixel = pixels[y * width + x]; // Access pixel
            putchar(pixel_to_ascii(pixel)); // Print ASCII character
        }
        putchar('\n'); // New line after each row
    }
}

// Main function to orchestrate the image to ASCII conversion
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    uint8_t* pixels = read_image(argv[1], &width, &height);
    if (pixels == NULL) {
        return EXIT_FAILURE;
    }

    // Perform the conversion and print the result
    image_to_ascii(pixels, width, height);

    free(pixels); // Memory cleanup
    return EXIT_SUCCESS;
}