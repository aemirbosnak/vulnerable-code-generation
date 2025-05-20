//FormAI DATASET v1.0 Category: Image Editor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

/**
 * This program is a cryptic image editor that reads an image file, performs some 
 * simple transformations, and saves the resulting image in a new file. All image 
 * pixels are represented as integers between 0 and 255 (inclusive).
 */

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int image_width, image_height, max_pixel_value;
    int i, j;

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: could not open input file: %s\n", argv[1]);
        exit(1);
    }

    // Read image header
    fscanf(input_file, "P2 %d %d %d ", &image_width, &image_height, &max_pixel_value);

    // Read image data
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            fscanf(input_file, "%d ", &image[i][j]);
        }
    }

    // Close input file
    fclose(input_file);

    // Invert image
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            image[i][j] = max_pixel_value - image[i][j];
        }
    }

    // Open output file
    output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Error: could not open output file: %s\n", argv[2]);
        exit(1);
    }

    // Write image header
    fprintf(output_file, "P2\n%d %d\n%d\n", image_width, image_height, max_pixel_value);

    // Write image data
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            fprintf(output_file, "%d ", image[i][j]);
        }
        fprintf(output_file, "\n");
    }

    // Close output file
    fclose(output_file);

    // Exit
    return 0;
}