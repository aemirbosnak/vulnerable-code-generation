//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

// Converts individual pixels to ASCII characters
char* pixel_to_ascii(int r, int g, int b, int alpha) {
    if (alpha == 0) {
        return " ";
    }
    static char ascii_chars[] = " .,-~:;=!*#$@"; // ASCII character set ranging from light to dark
    int brightness = (int)(0.2126 * r + 0.7152 * g + 0.0722 * b); // Standard grayscale conversion formula
    int character_idx = (brightness / 256.0) * (strlen(ascii_chars) - 1);
    return &ascii_chars[character_idx];
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s [image file name]\n", argv[0]);
        return 1;
    }

    // Open image file
    FILE* fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }
    
    // Read image metadata
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bytes_per_pixel = *(int*)&header[28] / 8;
    int padding_size = (4 - (width * bytes_per_pixel) % 4) % 4; // Rows in BMP must be a multiple of 4 bytes; any extra bytes are padding

    // Make sure image is not too wide for console
    if (width > MAX_WIDTH) {
        printf("Error: image is too wide for console\n");
        return 1;
    }

    // Allocate memory for image data
    unsigned char* data = (unsigned char*)malloc((size_t)width * height * bytes_per_pixel);
    fread(data, sizeof(unsigned char), (size_t)width * height * bytes_per_pixel, fp);
    fclose(fp);

    // Print ASCII art
    for (int y = height - 1; y >= 0; y--) { // BMP stores data starting from the bottom row
        for (int x = 0; x < width; x++) {
            int idx = (y * width + x) * bytes_per_pixel;
            char* ascii_char = pixel_to_ascii(data[idx + 2], data[idx + 1], data[idx], bytes_per_pixel == 4 ? data[idx + 3] : 255);
            printf("%s", ascii_char);
        }
        printf("\n");
        fseek(fp, padding_size, SEEK_CUR); // Skip any padding bytes at the end of the row
    }

    // Clean up
    free(data);
    return 0;
}