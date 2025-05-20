//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET ".,-~:;=!*#@"

// Function to convert pixel value to ASCII character
char pixel_to_ascii(int pixel) {
    int ascii_index = (pixel * (sizeof(CHAR_SET) - 1)) / 255;
    return CHAR_SET[ascii_index];
}

// Function to convert image to ASCII art
void image_to_ascii(FILE *input_file, FILE *output_file) {
    int width, height, channels;
    unsigned char *data;

    // Read image dimensions and data
    fseek(input_file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    fread(&channels, sizeof(int), 1, input_file);

    data = malloc(width * height * channels);
    fread(data, width * height * channels, 1, input_file);

    // Convert image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * channels;
            int red = data[pixel_index];
            int green = data[pixel_index + 1];
            int blue = data[pixel_index + 2];

            int pixel_value = (red + green + blue) / 3;
            fprintf(output_file, "%c", pixel_to_ascii(pixel_value));
        }
        fprintf(output_file, "\n");
    }

    // Free memory
    free(data);
}

int main() {
    FILE *input_file, *output_file;

    // Open input and output files
    input_file = fopen("input.png", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Convert image to ASCII art
    image_to_ascii(input_file, output_file);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Image converted to ASCII art successfully.\n");
    return 0;
}