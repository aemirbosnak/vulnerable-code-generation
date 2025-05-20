//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: failed to open input file.\n");
        return 1;
    }

    // Read image header
    char magic_number[3];
    int width, height, max_val;
    fscanf(input_file, "%s\n%d %d\n%d\n", magic_number, &width, &height, &max_val);

    // Check image type
    if (strcmp(magic_number, "P6") != 0) {
        printf("Error: unsupported image type '%s'.\n", magic_number);
        return 1;
    }

    // Check image dimensions
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image dimensions too large.\n");
        return 1;
    }

    // Allocate memory for image data
    unsigned char *data = (unsigned char *) malloc(sizeof(unsigned char) * 3 * width * height);
    if (data == NULL) {
        printf("Error: failed to allocate memory.\n");
        return 1;
    }

    // Read image data
    int num_pixels = fread(data, sizeof(unsigned char), 3 * width * height, input_file);
    if (num_pixels != 3 * width * height) {
        printf("Error: failed to read image data.\n");
        return 1;
    }

    // Close input file
    fclose(input_file);

    // Open output file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: failed to open output file.\n");
        return 1;
    }

    // Convert image to ASCII art
    char ascii_art[height][width+1];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            unsigned char r = data[index];
            unsigned char g = data[index+1];
            unsigned char b = data[index+2];
            int intensity = (int) (0.21 * r + 0.72 * g + 0.07 * b);
            if (intensity < 64) {
                ascii_art[y][x] = '@';
            } else if (intensity < 128) {
                ascii_art[y][x] = '#';
            } else if (intensity < 192) {
                ascii_art[y][x] = '&';
            } else if (intensity < 256) {
                ascii_art[y][x] = '.';
            }
        }
        ascii_art[y][width] = '\0';
        fprintf(output_file, "%s\n", ascii_art[y]);
    }

    // Close output file
    fclose(output_file);

    // Free memory
    free(data);

    return 0;
}