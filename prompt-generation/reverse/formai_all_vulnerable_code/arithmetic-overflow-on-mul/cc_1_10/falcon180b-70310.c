//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHARSET_SIZE 256

/* Character set used for ASCII art */
char charset[] = ".:-=+*#%@";

/* Convert a pixel value to its corresponding ASCII character */
char pixel_to_ascii(int pixel) {
    return charset[pixel % CHARSET_SIZE];
}

/* Convert an image to ASCII art */
void image_to_ascii(FILE *input_file, FILE *output_file) {
    int width, height, depth;
    unsigned char *data;
    int x, y, i;

    /* Read image header */
    fseek(input_file, 0, SEEK_SET);
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    fread(&depth, sizeof(int), 1, input_file);

    /* Allocate memory for image data */
    data = (unsigned char *) malloc(width * height * depth);

    /* Read image data */
    fseek(input_file, 0, SEEK_SET);
    fread(data, width * height * depth, 1, input_file);

    /* Convert image to ASCII art */
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            i = (y * width + x) * depth;
            fprintf(output_file, "%c", pixel_to_ascii(data[i]));
        }
        fprintf(output_file, "\n");
    }

    /* Free memory */
    free(data);
}

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char *input_filename, *output_filename;

    /* Check command line arguments */
    if (argc!= 4) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    /* Open input and output files */
    input_filename = argv[1];
    output_filename = argv[2];
    input_file = fopen(input_filename, "rb");
    output_file = fopen(output_filename, "w");

    /* Check if files were opened successfully */
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    /* Convert image to ASCII art */
    image_to_ascii(input_file, output_file);

    /* Close files */
    fclose(input_file);
    fclose(output_file);

    return 0;
}