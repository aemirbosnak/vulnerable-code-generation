//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VAL 255
#define MAX_ASCII_VAL 126
#define MIN_ASCII_VAL 32

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input image file> <output text file>\n", argv[0]);
        return 1;
    }

    char* in_filename = argv[1];
    char* out_filename = argv[2];

    FILE* in_file = fopen(in_filename, "rb");
    if (in_file == NULL) {
        printf("Error: could not open input file '%s'\n", in_filename);
        return 1;
    }

    FILE* out_file = fopen(out_filename, "w");
    if (out_file == NULL) {
        printf("Error: could not open output file '%s'\n", out_filename);
        return 1;
    }

    // Read image header
    char magic_number[3];
    int width, height, max_val;
    fscanf(in_file, "%s\n%d %d\n%d\n", magic_number, &width, &height, &max_val);

    if (strcmp(magic_number, "P6") != 0) {
        printf("Error: unsupported file format '%s'\n", magic_number);
        return 1;
    }

    if (max_val != MAX_PIXEL_VAL) {
        printf("Error: unsupported pixel value '%d'\n", max_val);
        return 1;
    }

    // Read image data
    unsigned char* image_data = malloc(sizeof(unsigned char) * width * height * 3);
    fread(image_data, sizeof(unsigned char), width * height * 3, in_file);

    // Convert image to ASCII art
    char* ascii_data = malloc(sizeof(char) * (width + 1) * height);
    int ascii_idx = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char r = image_data[(y * width + x) * 3];
            unsigned char g = image_data[(y * width + x) * 3 + 1];
            unsigned char b = image_data[(y * width + x) * 3 + 2];

            // Use luminance formula to convert RGB color to grayscale intensity
            int intensity = (int)(0.2126 * r + 0.7152 * g + 0.0722 * b);

            // Map intensity to ASCII value
            int ascii_value = ((intensity - 1) * (MAX_ASCII_VAL - MIN_ASCII_VAL)) / (MAX_PIXEL_VAL - 1) + MIN_ASCII_VAL;
            ascii_data[ascii_idx] = (char)ascii_value;
            ascii_idx++;
        }

        ascii_data[ascii_idx] = '\n';
        ascii_idx++;
    }

    // Write ASCII art to file
    fwrite(ascii_data, sizeof(char), (width + 1) * height, out_file);

    // Cleanup
    free(image_data);
    free(ascii_data);
    fclose(in_file);
    fclose(out_file);

    return 0;
}