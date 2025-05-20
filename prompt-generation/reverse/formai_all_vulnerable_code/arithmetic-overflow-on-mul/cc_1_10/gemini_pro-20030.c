//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load an image from a file
Image *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a valid BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP image\n", filename);
        fclose(file);
        return NULL;
    }

    // Read the width and height of the image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the image data
    unsigned char *data = malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);

    // Close the file
    fclose(file);

    // Create an image struct and return it
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to convert an image to ASCII art
char *image_to_ascii(Image *image) {
    // Create a 2D array to store the ASCII art
    char **ascii_art = malloc(image->height * sizeof(char *));
    for (int i = 0; i < image->height; i++) {
        ascii_art[i] = malloc(image->width * sizeof(char));
    }

    // Convert each pixel to an ASCII character
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Get the pixel's color
            unsigned char r = image->data[3 * (i * image->width + j)];
            unsigned char g = image->data[3 * (i * image->width + j) + 1];
            unsigned char b = image->data[3 * (i * image->width + j) + 2];

            // Convert the color to a grayscale value
            double grayscale = (r + g + b) / 3.0;

            // Map the grayscale value to an ASCII character
            char c = " .,-=+*#%@"[(int)(grayscale / 25.5)];

            // Set the ASCII character in the 2D array
            ascii_art[i][j] = c;
        }
    }

    // Convert the 2D array to a single string
    char *ascii_art_string = malloc(image->width * image->height * sizeof(char));
    for (int i = 0; i < image->height; i++) {
        strcat(ascii_art_string, ascii_art[i]);
        strcat(ascii_art_string, "\n");
    }

    // Free the memory allocated for the 2D array
    for (int i = 0; i < image->height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);

    // Return the ASCII art string
    return ascii_art_string;
}

// Function to print the ASCII art to the console
void print_ascii_art(char *ascii_art) {
    printf("%s", ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified an image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Load the image from the file
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Convert the image to ASCII art
    char *ascii_art = image_to_ascii(image);

    // Print the ASCII art to the console
    print_ascii_art(ascii_art);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    // Free the memory allocated for the ASCII art
    free(ascii_art);

    return 0;
}