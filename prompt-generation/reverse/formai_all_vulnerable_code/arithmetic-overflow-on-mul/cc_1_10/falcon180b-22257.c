//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SET ".,-*+@%#&!?="

// Convert an image pixel to an ASCII character
char pixel_to_ascii(int pixel) {
    int index = pixel * 8 / (256 - 32); // Map pixel value to ASCII index
    return CHAR_SET[index];
}

// Convert an image to ASCII art
void image_to_ascii(FILE *input_file, FILE *output_file) {
    int width, height, max_value;
    unsigned char *data;

    // Read image header
    fseek(input_file, 0, SEEK_SET);
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    fread(&max_value, sizeof(int), 1, input_file);

    // Allocate memory for image data
    data = (unsigned char *) malloc(width * height * sizeof(unsigned char));
    fread(data, width * height, 1, input_file);

    // Convert image to ASCII art
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int index = y * width + x;
            int pixel_value = data[index] * 8 / max_value;
            fprintf(output_file, "%c", pixel_to_ascii(pixel_value));
        }
        fprintf(output_file, "\n");
    }

    // Free memory
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii.txt\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    image_to_ascii(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}