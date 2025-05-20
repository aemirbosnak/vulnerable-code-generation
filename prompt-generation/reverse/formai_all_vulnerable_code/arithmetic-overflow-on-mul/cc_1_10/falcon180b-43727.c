//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert image to ASCII art
void image_to_ascii(FILE *input_file, FILE *output_file) {
    int width, height, max_value;
    unsigned char *image_data;
    int x, y, k, i, j, value;

    // Read image dimensions and data from input file
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    fread(&max_value, sizeof(int), 1, input_file);
    image_data = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    fread(image_data, width * height, sizeof(unsigned char), input_file);

    // Convert image data to ASCII art
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            value = image_data[y * width + x];
            k = round(value / max_value * 256);
            for (i = 0; i < 8; i++) {
                j = 7 - i;
                fprintf(output_file, "%c", ".:-=+*#@"[k >> (i * 3) & 7]);
            }
        }
        fprintf(output_file, "\n");
    }

    // Free memory and close files
    free(image_data);
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    FILE *input_file, *output_file;

    // Check if correct number of arguments were provided
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Open input and output files
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Convert image to ASCII art
    image_to_ascii(input_file, output_file);

    fclose(input_file);
    fclose(output_file);
    return 0;
}