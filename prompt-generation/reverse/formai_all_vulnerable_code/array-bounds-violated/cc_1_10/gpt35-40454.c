//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of shades to use in ASCII art
#define NUM_SHADES 10

// ASCII shades from darkest to lightest
char* shades[NUM_SHADES] = {
    " ", ".", "-", "+", "*", "#", "=", "@", "%", "W"
};

// Function to convert pixel value to ASCII character
char pixel_to_ascii(int pixel_val, int max_pixel_val)
{
    int shade_step = max_pixel_val / NUM_SHADES;
    int shade_index = pixel_val / shade_step;
    return shades[shade_index];
}

// Function to convert image to ASCII art
void image_to_ascii(int rows, int cols, int** pixels)
{
    int max_pixel_val = 255; // Maximum pixel value assumed to be 255
    char ascii_art[rows][cols*2]; // ASCII art matrix to store characters

    // Loop through each pixel in the image
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Convert pixel value to corresponding ASCII character
            char ascii_char = pixel_to_ascii(pixels[i][j], max_pixel_val);
            // Store the ASCII character in matrix
            ascii_art[i][j*2] = ascii_char;
            ascii_art[i][j*2 + 1] = ascii_char;
        }
    }

    // Print the ASCII art matrix
    for (int i = 0; i < rows; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

int main()
{
    // Sample image (4 x 4 pixels)
    int sample_pixels[4][4] = {
        {0, 63, 127, 255},
        {63, 127, 191, 255},
        {127, 191, 255, 127},
        {191, 255, 127, 0}
    };

    // Convert sample image to ASCII art and display
    printf("Sample Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", sample_pixels[i][j]);
        }
        printf("\n");
    }
    printf("\nASCII Art:\n");
    image_to_ascii(4, 4, (int**)sample_pixels);

    return 0;
}