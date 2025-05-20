//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a pixel to its ASCII representation
char pixel_to_ascii(int pixel) {
    if (pixel < 16) {
        return '.';
    } else if (pixel < 32) {
        return '+';
    } else if (pixel < 48) {
        return '*';
    } else {
        return '#';
    }
}

// Function to convert an image to ASCII art
void image_to_ascii(FILE *input_file, FILE *output_file) {
    int width, height, max_value;
    fscanf(input_file, "P6\n%d %d\n%d\n", &width, &height, &max_value);
    printf("P6\n%d %d\n%d\n", width, height, max_value);

    int *pixels = malloc(width * height * sizeof(int));
    fread(pixels, sizeof(int), width * height, input_file);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(output_file, "%c", pixel_to_ascii(pixels[y * width + x]));
        }
        fprintf(output_file, "\n");
    }

    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    image_to_ascii(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}