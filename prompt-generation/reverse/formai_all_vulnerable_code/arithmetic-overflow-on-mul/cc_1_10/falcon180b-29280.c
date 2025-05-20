//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

// Function to convert a character to its ASCII value
int char_to_ascii(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 27;
    } else if (c >= '0' && c <= '9') {
        return c - '0' + 55;
    } else {
        return -1;
    }
}

// Function to convert an image to ASCII art
void image_to_ascii(FILE *input_file, FILE *output_file) {
    int width, height;
    unsigned char *data;

    // Read image dimensions
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    // Allocate memory for image data
    data = (unsigned char *) malloc(width * height * sizeof(unsigned char));

    // Read image data
    fread(data, sizeof(unsigned char), width * height, input_file);

    // Convert image to ASCII art
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int ascii_value = char_to_ascii(data[y * width + x]);
            if (ascii_value!= -1) {
                fprintf(output_file, "%c", ascii_value);
            } else {
                fprintf(output_file, " ");
            }
        }
        fprintf(output_file, "\n");
    }

    // Free memory
    free(data);
}

int main() {
    FILE *input_file, *output_file;

    // Open input and output files
    input_file = fopen("input.bmp", "rb");
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

    return 0;
}