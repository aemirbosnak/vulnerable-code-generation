//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define ASCII_LEN 70

const char asciiChars[ASCII_LEN + 1] = "@%#*+=-:. "; // Characters used for ASCII conversion

void load_image(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the image's header (assuming a simple PGM format for simplicity)
    char header[3];
    fscanf(file, "%s", header);
    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Consume the newline character after maxval

    // Load the image pixel data
    for (int i = 0; i < *height; ++i) {
        for (int j = 0; j < *width; ++j) {
            image[i][j] = fgetc(file); // Read pixel value
        }
    }

    fclose(file);
}

void convert_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height, char asciiArt[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // Scale pixel value to ASCII array index
            int index = (image[i][j] * ASCII_LEN) / 256; // Scale to 0 - ASCII_LEN
            asciiArt[i][j] = asciiChars[index];
        }
        asciiArt[i][width] = '\0'; // Null terminate each line
    }
}

void save_ascii_art(const char *output_file, char asciiArt[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    FILE *file = fopen(output_file, "w");
    if (!file) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Generated ASCII Art\n");
    fprintf(file, "Width: %d, Height: %d\n", width, height);
    
    for (int i = 0; i < height; ++i) {
        fprintf(file, "%s\n", asciiArt[i]); // Write each line of ASCII art
    }

    fclose(file);
}

void display_ascii_art(char asciiArt[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    printf("Generated ASCII Art:\n");
    for (int i = 0; i < height; ++i) {
        printf("%s\n", asciiArt[i]); // Print each line
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image.pgm> <output_ascii.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    char asciiArt[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    load_image(argv[1], image, &width, &height);
    convert_to_ascii(image, width, height, asciiArt);
    save_ascii_art(argv[2], asciiArt, width, height);
    display_ascii_art(asciiArt, width, height);

    return EXIT_SUCCESS;
}