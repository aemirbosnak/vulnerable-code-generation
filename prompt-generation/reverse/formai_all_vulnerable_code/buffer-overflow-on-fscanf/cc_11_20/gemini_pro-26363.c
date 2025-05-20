//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an image file
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error opening image file: %s\n", argv[1]);
        return 1;
    }

    // Read the image header
    int width, height;
    if (fscanf(image_file, "P2\n%d %d\n255\n", &width, &height) != 3) {
        printf("Error reading image header\n");
        fclose(image_file);
        return 1;
    }

    // Allocate memory for the image data
    unsigned char *image_data = malloc(width * height * sizeof(unsigned char));
    if (image_data == NULL) {
        printf("Error allocating memory for image data\n");
        fclose(image_file);
        return 1;
    }

    // Read the image data
    if (fread(image_data, width * height, sizeof(unsigned char), image_file) != width * height) {
        printf("Error reading image data\n");
        fclose(image_file);
        free(image_data);
        return 1;
    }

    // Close the image file
    fclose(image_file);

    // Convert the image to ASCII art
    char *ascii_art = malloc(width * height * sizeof(char));
    if (ascii_art == NULL) {
        printf("Error allocating memory for ASCII art\n");
        free(image_data);
        return 1;
    }

    for (int i = 0; i < width * height; i++) {
        // Calculate the ASCII character for this pixel
        int pixel_value = image_data[i];
        char ascii_character = ' ';
        if (pixel_value >= 200) {
            ascii_character = '@';
        } else if (pixel_value >= 150) {
            ascii_character = '%';
        } else if (pixel_value >= 100) {
            ascii_character = '#';
        } else if (pixel_value >= 50) {
            ascii_character = '+';
        }

        // Store the ASCII character in the ASCII art string
        ascii_art[i] = ascii_character;
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i * width + j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image data and ASCII art
    free(image_data);
    free(ascii_art);

    return 0;
}