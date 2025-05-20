//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

int main(int argc, char *argv[]) {
    // Check whether user provided correct number of arguments
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        exit(1);
    }

    // Open image file in binary mode
    FILE *image_file = fopen(argv[1], "rb");

    if(!image_file) {
        fprintf(stderr, "Unable to open image file %s\n", argv[1]);
        exit(1);
    }

    // Read image dimensions from header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Compute padding
    int padding = (4 - (width * 3) % 4) % 4;

    // Allocate memory for image data
    unsigned char *data = malloc(width * height * 3);

    if(!data) {
        fprintf(stderr, "Unable to allocate memory for image data\n");
        exit(1);
    }

    // Read image data into memory
    for(int i = 0; i < height; i++) {
        fread(data + (i * width * 3), sizeof(unsigned char), width * 3, image_file);
        fseek(image_file, padding, SEEK_CUR);
    }

    // Close image file
    fclose(image_file);

    // Convert image data into ASCII art
    char ascii_art[MAX_HEIGHT][MAX_WIDTH];

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int offset = y * width * 3 + x * 3;

            // Compute grayscale value of pixel
            char gray_value = (data[offset] + data[offset+1] + data[offset+2]) / 3;

            // Map grayscale value to ASCII character
            if(gray_value < 51) { // Dark
                ascii_art[y][x] = '@';
            } else if(gray_value < 102) { // Medium-dark
                ascii_art[y][x] = '#';
            } else if(gray_value < 153) { // Medium-light
                ascii_art[y][x] = '%';
            } else if(gray_value < 204) { // Light
                ascii_art[y][x] = '=';
            } else { // White
                ascii_art[y][x] = ' ';
            }
        }
    }

    // Print ASCII art to console
    for(int y = 0; y < height; y++) {
        fprintf(stdout, "%s\n", ascii_art[y]);
    }

    // Free memory allocated for image data
    free(data);

    return 0;
}