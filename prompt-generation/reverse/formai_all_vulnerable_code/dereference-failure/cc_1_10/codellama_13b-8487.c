//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
/*
 * Image to ASCII art converter example program in a multivariable style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a single pixel to an ASCII character
char pixel_to_ascii(int pixel) {
    // Convert the pixel value to a character
    char ascii = (char) (pixel + 33);

    // If the character is outside the ASCII range, return a space
    if (ascii < 33 || ascii > 126) {
        ascii = ' ';
    }

    return ascii;
}

// Function to convert an image to ASCII art
void image_to_ascii(const char *image, int width, int height, int scale) {
    // Allocate memory for the ASCII art string
    char *ascii = (char *) malloc(width * height * scale * sizeof(char));

    // Loop through each pixel in the image
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Get the pixel value at the current position
            int pixel = (int) image[i * width + j];

            // Convert the pixel to an ASCII character
            char ascii_char = pixel_to_ascii(pixel);

            // Add the ASCII character to the ASCII art string
            ascii[i * width + j] = ascii_char;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < width * height; i++) {
        printf("%c", ascii[i]);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    // Free the memory allocated for the ASCII art string
    free(ascii);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were passed
    if (argc != 4) {
        printf("Usage: %s <image file> <width> <height>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open image file\n");
        return 1;
    }

    // Read the image data into a buffer
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    char *image = (char *) malloc(width * height * sizeof(char));
    fread(image, sizeof(char), width * height, file);
    fclose(file);

    // Convert the image to ASCII art
    image_to_ascii(image, width, height, 2);

    // Free the memory allocated for the image buffer
    free(image);

    return 0;
}