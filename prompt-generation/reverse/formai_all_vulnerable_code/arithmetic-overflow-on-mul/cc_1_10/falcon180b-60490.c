//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// Function to convert image to ASCII art
void image_to_ascii(FILE *image_file, FILE *ascii_file) {
    int width, height, pixel;
    char ascii_char;
    unsigned char *image_data;

    // Read image dimensions
    fseek(image_file, 18, SEEK_SET);
    fread(&width, 4, 1, image_file);
    fread(&height, 4, 1, image_file);

    // Allocate memory for image data
    image_data = (unsigned char *)malloc(width * height * 3);
    if (image_data == NULL) {
        printf("Error allocating memory for image data.\n");
        exit(1);
    }

    // Read image data
    fseek(image_file, 54, SEEK_SET);
    fread(image_data, 1, width * height * 3, image_file);

    // Convert image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = (int)image_data[(y * width + x) * 3];
            ascii_char = '@';

            if (pixel > 128) {
                ascii_char = '.';
            } else if (pixel > 64) {
                ascii_char = '*';
            } else if (pixel > 32) {
                ascii_char = '+';
            }

            fprintf(ascii_file, "%c", ascii_char);
        }
        fprintf(ascii_file, "\n");
    }

    // Free memory for image data
    free(image_data);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii.txt\n", argv[0]);
        return 1;
    }

    FILE *image_file, *ascii_file;
    image_file = fopen(argv[1], "rb");
    ascii_file = fopen(argv[2], "w");

    if (image_file == NULL || ascii_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    image_to_ascii(image_file, ascii_file);

    fclose(image_file);
    fclose(ascii_file);

    return 0;
}