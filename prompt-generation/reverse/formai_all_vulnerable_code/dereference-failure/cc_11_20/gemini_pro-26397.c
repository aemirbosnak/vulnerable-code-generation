//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel_t;

int main() {
    // Open the input image file
    FILE *input_file = fopen("input.jpg", "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return 1;
    }

    // Read the image header
    unsigned int header_size;
    fread(&header_size, sizeof(unsigned int), 1, input_file);
    unsigned int width;
    fread(&width, sizeof(unsigned int), 1, input_file);
    unsigned int height;
    fread(&height, sizeof(unsigned int), 1, input_file);

    // Check if the image is too large
    if (width > WIDTH || height > HEIGHT) {
        fprintf(stderr, "Error: Image is too large\n");
        return 1;
    }

    // Allocate memory for the image data
    pixel_t *image_data = malloc(width * height * sizeof(pixel_t));
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        return 1;
    }

    // Read the image data
    fread(image_data, sizeof(pixel_t), width * height, input_file);

    // Close the input image file
    fclose(input_file);

    // Open the output text file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }

    // Convert the image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the average color of the pixel
            unsigned char avg_color = (image_data[y * width + x].r + image_data[y * width + x].g + image_data[y * width + x].b) / 3;

            // Convert the average color to a character
            char character;
            if (avg_color < 32) {
                character = '#';
            } else if (avg_color < 64) {
                character = '8';
            } else if (avg_color < 96) {
                character = '&';
            } else if (avg_color < 128) {
                character = 'o';
            } else if (avg_color < 160) {
                character = 'a';
            } else if (avg_color < 192) {
                character = '*';
            } else if (avg_color < 224) {
                character = '-';
            } else {
                character = ' ';
            }

            // Write the character to the output file
            fprintf(output_file, "%c", character);
        }

        // Newline
        fprintf(output_file, "\n");
    }

    // Close the output text file
    fclose(output_file);

    // Free the memory allocated for the image data
    free(image_data);

    return 0;
}