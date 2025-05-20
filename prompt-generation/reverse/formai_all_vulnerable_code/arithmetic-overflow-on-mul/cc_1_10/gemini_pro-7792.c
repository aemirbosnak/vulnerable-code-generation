//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t pixels[MAX_WIDTH * MAX_HEIGHT];
} image_t;

void read_image(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: '%s' is not a BMP file\n", filename);
        exit(1);
    }

    // Read the image dimensions
    image->width = *(int *)&header[18];
    image->height = *(int *)&header[22];

    // Read the image data
    fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);

    fclose(fp);
}

void to_ascii_art(image_t *image, char *ascii_art) {
    // Create a character map
    char *character_map = " .,-:;=!*#%@";

    // Convert the image to ASCII art
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Get the average color of the pixel
            pixel_t pixel = image->pixels[y * image->width + x];
            int average = (pixel.r + pixel.g + pixel.b) / 3;

            // Convert the average color to a character
            char character = character_map[average / 32];

            // Append the character to the ASCII art string
            strncat(ascii_art, &character, 1);
        }

        // Append a newline character to the ASCII art string
        strcat(ascii_art, "\n");
    }
}

void save_ascii_art(const char *filename, const char *ascii_art) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Write the ASCII art to the file
    fputs(ascii_art, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Read the image
    image_t image;
    read_image(&image, argv[1]);

    // Convert the image to ASCII art
    char ascii_art[MAX_WIDTH * MAX_HEIGHT];
    to_ascii_art(&image, ascii_art);

    // Save the ASCII art to a file
    save_ascii_art(argv[2], ascii_art);

    return 0;
}