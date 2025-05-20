//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *ASCII_CHARS = " .:-=+*#%@";

void generate_ascii_art(unsigned char *image_data, int width, int height) {
    // Create a buffer for the ASCII art
    char *ascii_art = calloc(width * height + 1, sizeof(char));
    if (!ascii_art) {
        perror("Error: Failed to allocate memory for ASCII art buffer");
        exit(EXIT_FAILURE);
    }

    // Convert each pixel value in the image to its corresponding ASCII character
    for (int i = 0; i < width * height; i++) {
        int pixel_value = image_data[i];
        int ascii_index = (pixel_value * strlen(ASCII_CHARS)) / 256;
        ascii_art[i] = ASCII_CHARS[ascii_index];
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i * width + j]);
        }
        printf("\n");
    }

    free(ascii_art);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: No image file specified\n");
        printf("Usage: %s <image file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *image_file = argv[1];
    FILE *fp = fopen(image_file, "rb");
    if (!fp) {
        perror("Error: Failed to open image file");
        exit(EXIT_FAILURE);
    }

    int width, height;
    unsigned char *image_data;

    // Read the image header
    if (fscanf(fp, "P6\n%d %d\n255\n", &width, &height) != 2) {
        printf("Error: Invalid PPM file format\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the image data
    image_data = malloc(width * height * sizeof(unsigned char) * 3);
    if (!image_data) {
        perror("Error: Failed to allocate memory for image data");
        exit(EXIT_FAILURE);
    }

    // Read the image data
    if (fread(image_data, sizeof(unsigned char), width * height * 3, fp) != width * height * 3) {
        printf("Error: Failed to read image data\n");
        exit(EXIT_FAILURE);
    }

    // Close the image file
    fclose(fp);

    // Convert the image to ASCII art
    generate_ascii_art(image_data, width, height);

    // Free the image data
    free(image_data);

    return EXIT_SUCCESS;
}