//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define MAX_PIXEL_VALUE 255

char ascii_art[MAX_HEIGHT][MAX_WIDTH];

void convert_image_to_ascii_art(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height)
{
    int i, j;

    // Compute the ratio of one ASCII character to the vertical and horizontal pixels
    double pixel_ratio = (double)height / (double)width;

    // Define the ASCII character set
    char ascii_chars[] = {' ', '.', ',', ':', ';', '!', '*', '#', '$', '@'};

    // Compute the pixel intensity that corresponds to each ASCII character
    double pixel_intensity_step = (double)MAX_PIXEL_VALUE / (double)(sizeof(ascii_chars)/sizeof(ascii_chars[0]) - 1);
    double pixel_intensity = 0;

    // Generate the ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Scale the pixel intensity to the range of ASCII characters
            int ascii_char_index = (int)floor((double)pixels[i][j] / pixel_intensity_step);

            // Ensure that the ASCII character index is not out of range
            if (ascii_char_index < 0) {
                ascii_char_index = 0;
            } else if (ascii_char_index >= sizeof(ascii_chars)/sizeof(ascii_chars[0])) {
                ascii_char_index = sizeof(ascii_chars)/sizeof(ascii_chars[0]) - 1;
            }

            // Set the ASCII character for this pixel
            ascii_art[(int)floor(pixel_ratio * i)][j] = ascii_chars[ascii_char_index];

            // Update the pixel intensity
            pixel_intensity += pixel_intensity_step;
        }
        pixel_intensity = 0;
    }
}

int main(void)
{
    int i, j;
    int pixels[MAX_HEIGHT][MAX_WIDTH];
    int width, height, max_pixel_value;

    // Read in the image
    scanf("P2\n%d %d\n%d\n", &width, &height, &max_pixel_value);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf("%d", &pixels[i][j]);
        }
    }

    // Convert the image to ASCII art
    convert_image_to_ascii_art(pixels, width, height);

    // Print the ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}