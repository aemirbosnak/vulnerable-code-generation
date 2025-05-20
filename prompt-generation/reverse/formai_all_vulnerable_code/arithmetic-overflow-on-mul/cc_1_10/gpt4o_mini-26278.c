//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Structure to represent a pixel
typedef struct {
    uint8_t r, g, b;
} Pixel;

// Function to get the brightness of a pixel
int get_brightness(Pixel pixel) {
    return (pixel.r + pixel.g + pixel.b) / 3;
}

// Mapping brightness to ASCII characters
char map_brightness_to_ascii(int brightness) {
    const char *ascii_chars = "@%#*+=-:. "; // Characters from dark to light
    return ascii_chars[brightness * 9 / 255]; // Scale 0-255 to 0-9
}

// Function to load a simple bitmap image (P6 format)
Pixel* load_bitmap(const char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error loading file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read P6 header
    char header[3];
    fscanf(fp, "%s %d %d %*d", header, width, height);
    fgetc(fp); // To skip the newline after the header
    
    // Allocate memory for pixel data
    Pixel *pixels = malloc((*width) * (*height) * sizeof(Pixel));
    if (!pixels) {
        fclose(fp);
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Read pixel data
    fread(pixels, sizeof(Pixel), (*width) * (*height), fp);
    fclose(fp);
    return pixels;
}

// Function to convert an image to ASCII art
void convert_to_ascii(Pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int brightness = get_brightness(pixels[index]);
            putchar(map_brightness_to_ascii(brightness));
        }
        putchar('\n'); // New line after each row
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    Pixel *pixels = load_bitmap(argv[1], &width, &height);
    convert_to_ascii(pixels, width, height);
    
    free(pixels); // Don't forget to free allocated memory
    return EXIT_SUCCESS;
}