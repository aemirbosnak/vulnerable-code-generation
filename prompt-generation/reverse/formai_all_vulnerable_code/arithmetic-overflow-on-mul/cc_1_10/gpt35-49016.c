//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>

#define MAX_PIXELS 100000

// Define the ASCII characters that correspond to the shade of grey for the image.
// The charmap variable maps the shade of gray to the corresponding ASCII character.
char charmap[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Define the struct for a single pixel in the image
typedef struct {
    unsigned char r, g, b; // red, green, and blue values for a single pixel
} pixel;

// Function to convert a pixel to greyscale
unsigned char get_greyscale(pixel p) {
    return 0.30 * p.r + 0.59 * p.g + 0.11 * p.b;
}

// Main function
int main() {
    // Open the input file
    FILE *input_file = fopen("image.bmp", "rb");
    if (input_file == NULL) {
        printf("Could not open input file.");
        return 1;
    }

    // Read the header of the BMP file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // Get the width and height of the image from the header
    int width = *(int*)(header + 18);
    int height = *(int*)(header + 22);

    // Allocate memory for the image data
    pixel *image_data = malloc(width * height * sizeof(pixel));
    if (image_data == NULL) {
        printf("Could not allocate memory for image.");
        return 1;
    }

    // Read the image data from the input file
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel p;
            fread(&p, sizeof(pixel), 1, input_file);
            image_data[i * width + j] = p;
        }
    }
    fclose(input_file);

    // Allocate memory for the ASCII art
    char *ascii_art = malloc(width * height + height + 1);
    if (ascii_art == NULL) {
        printf("Could not allocate memory for ASCII art.");
        return 1;
    }

    // Convert the image to ASCII art
    int pixel_count = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            unsigned char gray_value = get_greyscale(image_data[i * width + j]);
            int char_index = (int)(gray_value / 25.5);
            char ascii_char = charmap[char_index];
            ascii_art[pixel_count++] = ascii_char;
        }
        ascii_art[pixel_count++] = '\n';
    }
    ascii_art[pixel_count] = '\0';

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the allocated memory
    free(image_data);
    free(ascii_art);

    return 0;
}