//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the ASCII characters to represent different brightness levels
const char asciiChars[] = "@%#*+=-:. "; // From darkest to brightest
#define ASCII_CHARS_LEN (sizeof(asciiChars) - 1)

void convertToASCII(FILE *imageFile) {
    int width, height, maxColorValue;
    // Read the header of the PPM file
    char format[3];
    fscanf(imageFile, "%s", format);
    if (format[0] != 'P' || format[1] != '3') {
        fprintf(stderr, "Unsupported file format. Only P3 PPM files are supported.\n");
        exit(1);
    }
    
    fscanf(imageFile, "%d %d", &width, &height);
    fscanf(imageFile, "%d", &maxColorValue);
    
    if (maxColorValue != 255) {
        fprintf(stderr, "Unsupported max color value. Only 255 is supported.\n");
        exit(1);
    }

    // Allocate memory for the pixels
    unsigned char *pixels = (unsigned char *)malloc(width * height * 3);
    if (pixels == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Read pixel data
    for (int i = 0; i < width * height * 3; i++) {
        fscanf(imageFile, "%hhu", &pixels[i]);
    }

    // Convert pixels to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixelIndex = (y * width + x) * 3; // Get index for the R, G, B values

            // Calculate the brightness of the pixel
            unsigned char r = pixels[pixelIndex];
            unsigned char g = pixels[pixelIndex + 1];
            unsigned char b = pixels[pixelIndex + 2];
            int brightness = (r + g + b) / 3; // Average brightness

            // Map brightness to an ASCII character
            int asciiIndex = (brightness * ASCII_CHARS_LEN) / 256; // Normalize to the ASCII array
            putchar(asciiChars[asciiIndex]);
        }
        putchar('\n'); // Move to the next line
    }

    // Free allocated memory and close file
    free(pixels);
    fclose(imageFile);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_ppm_image>\n", argv[0]);
        return 1;
    }

    FILE *imageFile = fopen(argv[1], "r");
    if (imageFile == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", argv[1]);
        return 1;
    }

    convertToASCII(imageFile);
    return 0;
}