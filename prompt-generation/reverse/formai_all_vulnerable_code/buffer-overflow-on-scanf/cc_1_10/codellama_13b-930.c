//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
// C Image to ASCII art converter example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_HEIGHT 1000
#define MAX_WIDTH 1000
#define MAX_ASCII_CHARS 95
#define ASCII_OFFSET 33

int main() {
    // Initialize variables
    char image_file[100];
    char ascii_char[MAX_ASCII_CHARS];
    int image_height, image_width, ascii_height, ascii_width;
    int x, y, i, j;

    // Get input file name
    printf("Enter the name of the image file: ");
    scanf("%s", image_file);

    // Open the image file
    FILE *fp = fopen(image_file, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the image dimensions
    fscanf(fp, "%d %d", &image_width, &image_height);

    // Calculate the ASCII dimensions
    ascii_width = (int) round(image_width / 2.0);
    ascii_height = (int) round(image_height / 2.0);

    // Initialize the ASCII art string
    char ascii_art[ascii_height][ascii_width];
    for (i = 0; i < ascii_height; i++) {
        for (j = 0; j < ascii_width; j++) {
            ascii_art[i][j] = ' ';
        }
    }

    // Read the image data
    int rgb[3];
    for (y = 0; y < image_height; y++) {
        for (x = 0; x < image_width; x++) {
            fscanf(fp, "%d %d %d", &rgb[0], &rgb[1], &rgb[2]);

            // Calculate the ASCII character based on the pixel color
            int pixel_value = (rgb[0] + rgb[1] + rgb[2]) / 3;
            int ascii_index = (int) round(((float) pixel_value / 255.0) * (MAX_ASCII_CHARS - 1));
            ascii_char[ascii_index] = (char) (ASCII_OFFSET + ascii_index);

            // Add the ASCII character to the ASCII art string
            ascii_art[y / 2][x / 2] = ascii_char[ascii_index];
        }
    }

    // Print the ASCII art
    for (i = 0; i < ascii_height; i++) {
        for (j = 0; j < ascii_width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}