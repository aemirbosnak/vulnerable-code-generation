//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define MAX_IMAGE_WIDTH 1024
#define MAX_IMAGE_HEIGHT 1024

// Define ascii symbols to be used for text art
const char *ascii_symbols = " .,:irsXA253hMHGS#9B&@";

// Define corresponding brightness levels
const int symbol_brightness[] = { 0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164, 168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220, 224, 228, 232, 236, 240, 244, 248, 252, 255 };

int pixel_to_brightness(unsigned char pixel_value, int num_symbols) {
    int brightness_scale_factor = MAX_PIXEL_VALUE / num_symbols;

    // Map pixel value to ascii brightness level
    for (int i = 0; i < num_symbols; i++) {
        if (pixel_value < (i + 1) * brightness_scale_factor) {
            return symbol_brightness[i];
        }
    }
    return symbol_brightness[num_symbols - 1];
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s image_file_path num_symbols output_file_path\n", argv[0]);
        return 1;
    }

    // Read in command line arguments
    char *image_file_path = argv[1];
    int num_symbols = atoi(argv[2]);
    char *output_file_path = argv[3];

    // Open file for reading
    FILE *image_file = fopen(image_file_path, "rb");

    if (image_file == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Load image header information
    char magic_number[3];
    int image_width, image_height, max_pixel_value;

    fscanf(image_file, "%2s\n", magic_number);
    fscanf(image_file, "%d %d\n", &image_width, &image_height);
    fscanf(image_file, "%d\n", &max_pixel_value);

    // Check if image is valid
    if (strcmp(magic_number, "P5") != 0 || image_width > MAX_IMAGE_WIDTH || image_height > MAX_IMAGE_HEIGHT) {
        printf("Invalid image format.\n");
        fclose(image_file);
        return 1;
    }

    // Allocate memory for image data
    unsigned char image_data[image_height][image_width];

    // Read image data into memory
    fread(image_data, sizeof(unsigned char), image_height * image_width, image_file);

    // Close image file
    fclose(image_file);

    // Open file for writing
    FILE *output_file = fopen(output_file_path, "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Convert image to ascii art and write to file
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            int brightness = pixel_to_brightness(image_data[i][j], num_symbols);
            char ascii_char = ascii_symbols[num_symbols - brightness - 1];
            fprintf(output_file, "%c", ascii_char);
        }
        fprintf(output_file, "\n");
    }

    // Close output file
    fclose(output_file);

    printf("Image converted to ascii art successfully.\n");

    return 0;
}