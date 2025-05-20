//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void flipImage(FILE *input, FILE *output);
void adjustBrightnessContrast(FILE *input, FILE *output, int brightness, int contrast);

// Main function
int main(int argc, char *argv[]) {
    // Check if correct number of arguments are provided
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        printf("Unable to open input file\n");
        return 1;
    }

    // Open output file
    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        printf("Unable to open output file\n");
        fclose(input);
        return 1;
    }

    // Flip the image horizontally
    flipImage(input, output);

    // Adjust the brightness and contrast of the image
    adjustBrightnessContrast(input, output, 50, 75);

    // Close the files
    fclose(input);
    fclose(output);

    return 0;
}

// Function to flip the image horizontally
void flipImage(FILE *input, FILE *output) {
    // Read header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input);

    // Write header to output file
    fwrite(header, sizeof(unsigned char), 54, output);

    // Read image data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;
    unsigned char pixel[3];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Read pixel from input image
            fread(pixel, sizeof(unsigned char), 3, input);

            // Write pixel to output image
            fwrite(pixel, sizeof(unsigned char), 3, output);
        }

        // Skip over padding bytes
        fseek(input, padding, SEEK_CUR);

        // Write padding bytes to output file
        for (int k = 0; k < padding; k++) {
            fputc(0x00, output);
        }
    }
}

// Function to adjust brightness and contrast of the image
void adjustBrightnessContrast(FILE *input, FILE *output, int brightness, int contrast) {
    // Read header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input);

    // Write header to output file
    fwrite(header, sizeof(unsigned char), 54, output);

    // Read image data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;
    unsigned char pixel[3];
    int gray;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Read pixel from input image
            fread(pixel, sizeof(unsigned char), 3, input);

            // Convert to grayscale
            gray = pixel[0] * 0.30 + pixel[1] * 0.59 + pixel[2] * 0.11;

            // Adjust brightness
            gray += brightness;

            // Adjust contrast
            gray = contrast * (gray - 128) + 128;

            // Clamp pixel value to [0, 255]
            if (gray < 0) {
                gray = 0;
            } else if (gray > 255) {
                gray = 255;
            }

            // Write pixel to output image
            pixel[0] = gray;
            pixel[1] = gray;
            pixel[2] = gray;
            fwrite(pixel, sizeof(unsigned char), 3, output);
        }

        // Skip over padding bytes
        fseek(input, padding, SEEK_CUR);

        // Write padding bytes to output file
        for (int k = 0; k < padding; k++) {
            fputc(0x00, output);
        }
    }
}