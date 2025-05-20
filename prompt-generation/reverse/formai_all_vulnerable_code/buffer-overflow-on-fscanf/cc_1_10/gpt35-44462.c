//FormAI DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "input_image.ppm";
    char output_filename[] = "artistic_image.ppm";
    int rows, cols, max_value;
    int r, g, b;
    int x, y;

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", input_filename);
        return 1;
    }

    // Read image header
    fscanf(input_file, "P3\n%d %d\n%d\n", &cols, &rows, &max_value);

    // Open output file
    output_file = fopen(output_filename, "w+");
    if (output_file == NULL) {
        printf("Error: Could not open output file %s\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Write image header to output file
    fprintf(output_file, "P3\n%d %d\n%d\n", cols, rows, max_value);

    // Apply artistic filter to image pixels
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            fscanf(input_file, "%d %d %d", &r, &g, &b);

            // Apply artistic filter to RGB values
            r = (int) round(r / 2.0);
            g = (int) round(g / 1.5);
            b = (int) round(b / 2.5);

            // Adjust pixel values if they exceed maximum
            if (r > MAX_PIXEL_VALUE) r = MAX_PIXEL_VALUE;
            if (g > MAX_PIXEL_VALUE) g = MAX_PIXEL_VALUE;
            if (b > MAX_PIXEL_VALUE) b = MAX_PIXEL_VALUE;

            // Write filtered pixel values to output file
            fprintf(output_file, "%d %d %d ", r, g, b);
        }
        fprintf(output_file, "\n");
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Artistic filter applied to image. Output file: %s\n", output_filename);

    return 0;
}