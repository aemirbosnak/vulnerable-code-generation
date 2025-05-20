//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define MAX_GREY 255

char ascii_art[MAX_HEIGHT][MAX_WIDTH];

void convert_image_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int height, int width, int grey_level)
{
    int i, j;

    // Loop over each pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {

            // Check if the pixel is white, grey or black
            if (image[i][j] >= (grey_level / 2)) {
                ascii_art[i][j] = '#';
            } else if (image[i][j] >= (grey_level / 3)) {
                ascii_art[i][j] = '=';
            } else {
                ascii_art[i][j] = '-';
            }
        }
    }
}

void print_ascii_art(int height, int width)
{
    int i, j;

    // Print the ASCII art to the screen
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int i, j, width, height, grey_level;

    if (argc != 2) {
        printf("Usage: ./ascii_art_converter [filename]\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the height, width and grey level of the image
    fscanf(fp, "%d %d %d", &width, &height, &grey_level);

    // Read the pixel values of the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(fp, "%hhu", &image[i][j]);
        }
    }

    fclose(fp);

    // Convert the image to ascii art
    convert_image_to_ascii(image, height, width, grey_level);

    // Print the ascii art to the screen
    print_ascii_art(height, width);

    return 0;
}