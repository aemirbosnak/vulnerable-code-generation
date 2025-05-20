//Code Llama-13B DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
/*
 * Unique C Pixel Art Generator
 *
 * Usage: ./pixelart <width> <height> <filename>
 *
 * Generates a pixel art image with the given dimensions and saves it to the
 * specified file.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <width> <height> <filename>\n", argv[0]);
        return 1;
    }

    // Get the width and height from the command line arguments
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char *filename = argv[3];

    // Check the dimensions
    if (width <= 0 || height <= 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Invalid dimensions: %dx%d\n", width, height);
        return 1;
    }

    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return 1;
    }

    // Generate the pixel art image
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Generate a random pixel color
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;

            // Write the pixel to the file
            fprintf(file, "%d %d %d\n", r, g, b);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}