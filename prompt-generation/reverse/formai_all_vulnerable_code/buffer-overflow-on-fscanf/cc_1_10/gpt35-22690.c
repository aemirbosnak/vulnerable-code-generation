//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define MAX_ASCII_SHADES 10

// pre-defined ASCII characters that represent different shades of grey
// 0-9 represent different levels, with 0 being the lightest and 9 being the darkest
char ascii_shades[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// function to read in a PGM image file
bool read_pgm(char filename[], int *width, int *height, unsigned char pixels[][MAX_WIDTH]) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
        return false;

    // read and discard the first two lines
    char buffer[MAX_WIDTH];
    fgets(buffer, MAX_WIDTH, file);
    fgets(buffer, MAX_WIDTH, file);

    // read the image dimensions
    fscanf(file, "%d %d", width, height);
    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) // check if image is too large
        return false;

    // read in the pixel values
    for (int row = 0; row < *height; row++) {
        for (int col = 0; col < *width; col++) {
            fscanf(file, "%c", &pixels[row][col]);
        }
    }

    fclose(file);
    return true;
}

// function to convert pixels to ASCII characters
void convert_to_ascii(int width, int height, unsigned char pixels[][MAX_WIDTH], char ascii_art[][MAX_WIDTH]) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int shade = (int)pixels[row][col] * MAX_ASCII_SHADES / 256;
            ascii_art[row][col] = ascii_shades[shade];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) // print usage instructions
        printf("Usage: %s filename.pgm\n", argv[0]);
    else {
        int width, height;
        unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];
        char ascii_art[MAX_HEIGHT][MAX_WIDTH];

        bool success = read_pgm(argv[1], &width, &height, pixels);
        if (success) {
            convert_to_ascii(width, height, pixels, ascii_art);
            for (int row = 0; row < height; row++) {
                for (int col = 0; col < width; col++) {
                    printf("%c", ascii_art[row][col]);
                }
                printf("\n");
            }
        }
        else {
            printf("Error reading file\n");
        }
    }

    return 0;
}