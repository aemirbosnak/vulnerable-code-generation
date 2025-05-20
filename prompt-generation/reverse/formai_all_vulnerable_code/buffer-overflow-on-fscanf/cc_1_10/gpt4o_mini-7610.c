//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define ASCII_CHARS "@#S%?*+;:,. "
#define ASCII_CHAR_COUNT (sizeof(ASCII_CHARS) - 1)

// Function to read the image from a PGM file
void read_pgm_image(const char *filename, int *width, int *height, int image[MAX_HEIGHT][MAX_WIDTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P2") != 0) {
        fprintf(stderr, "Not a valid PGM file.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);

    for (int i = 0; i < *height; ++i) {
        for (int j = 0; j < *width; ++j) {
            fscanf(file, "%d", &image[i][j]);
        }
    }

    fclose(file);
}

// Function to convert pixel value to ASCII character
char pixel_to_ascii(int pixel_value, int maxval) {
    float normalized = (float)pixel_value / maxval;
    int index = normalized * (ASCII_CHAR_COUNT - 1);
    return ASCII_CHARS[index];
}

// Function to convert the image to ASCII art
void convert_to_ascii_art(int width, int height, int image[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char ascii_char = pixel_to_ascii(image[i][j], 255); // Assuming 255 is the max pixel value
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.pgm>\n", argv[0]);
        return 1;
    }

    int width, height;
    int image[MAX_HEIGHT][MAX_WIDTH] = {0};
    
    // Step 1: Read the image
    read_pgm_image(argv[1], &width, &height, image);

    // Step 2: Convert and display ASCII art
    convert_to_ascii_art(width, height, image);

    return 0;
}