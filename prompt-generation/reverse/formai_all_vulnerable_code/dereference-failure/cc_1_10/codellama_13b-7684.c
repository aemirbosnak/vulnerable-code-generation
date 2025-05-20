//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
// Light-weight C Image to ASCII art converter example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define ASCII characters for different shades of gray
const char* GRAYSCALE = " .:-=+*#%@";

// Define a struct for the image data
typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

// Function to convert an image to ASCII art
void image_to_ascii(Image* image, int scale) {
    int i, j, k;
    int pixel;
    char* ascii_art;

    // Allocate memory for the ASCII art string
    ascii_art = (char*)malloc(image->width * image->height * sizeof(char));

    // Loop through each pixel in the image
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            // Get the pixel value
            pixel = image->pixels[i * image->width + j];

            // Convert the pixel value to a character
            k = (pixel * (strlen(GRAYSCALE) - 1)) / 255;
            ascii_art[i * image->width + j] = GRAYSCALE[k];
        }
    }

    // Print the ASCII art
    printf("%s\n", ascii_art);

    // Free the memory
    free(ascii_art);
}

// Function to read an image from a file
Image* read_image(char* filename) {
    Image* image;
    FILE* file;
    int width, height;
    int* pixels;

    // Open the file
    file = fopen(filename, "r");

    // Read the image dimensions
    fscanf(file, "%d %d", &width, &height);

    // Allocate memory for the image data
    pixels = (int*)malloc(width * height * sizeof(int));

    // Read the image pixels
    for (int i = 0; i < width * height; i++) {
        fscanf(file, "%d", &pixels[i]);
    }

    // Create the image struct
    image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;

    // Close the file
    fclose(file);

    return image;
}

// Function to write an image to a file
void write_image(Image* image, char* filename) {
    FILE* file;

    // Open the file
    file = fopen(filename, "w");

    // Write the image dimensions
    fprintf(file, "%d %d\n", image->width, image->height);

    // Write the image pixels
    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%d ", image->pixels[i]);
    }

    // Close the file
    fclose(file);
}

int main() {
    // Read an image from a file
    Image* image = read_image("image.txt");

    // Convert the image to ASCII art
    image_to_ascii(image, 3);

    // Write the ASCII art to a file
    write_image(image, "ascii_art.txt");

    // Free the memory
    free(image->pixels);
    free(image);

    return 0;
}