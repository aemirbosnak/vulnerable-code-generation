//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
/*
 * C Image to ASCII Art Converter
 * By [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

void print_ascii_art(char ascii_art[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void convert_image_to_ascii(FILE *image_file);

int main()
{
    FILE *image_file;
    char file_name[100];
    
    printf("Welcome to the C Image to ASCII Art Converter!\n");
    printf("Please enter the name of the image file you wish to convert: ");
    scanf("%s", file_name);

    image_file = fopen(file_name, "r");

    if (image_file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    convert_image_to_ascii(image_file);

    fclose(image_file);

    return 0;
}

void convert_image_to_ascii(FILE *image_file)
{
    int width, height, i, j;
    char ascii_art[MAX_HEIGHT][MAX_WIDTH];
    unsigned char pixel[MAX_HEIGHT][MAX_WIDTH];

    printf("Converting image to ASCII...\n");

    // Read the width and height of the image
    fscanf(image_file, "%d%d", &width, &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions too large\n");
        return;
    }

    // Read the pixel values of the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(image_file, "%hhu", &pixel[i][j]);
        }
    }

    // Convert the pixel values to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (pixel[i][j] < 50) {
                ascii_art[i][j] = '@';
            } else if (pixel[i][j] < 100) {
                ascii_art[i][j] = '#';
            } else if (pixel[i][j] < 150) {
                ascii_art[i][j] = '*';
            } else if (pixel[i][j] < 200) {
                ascii_art[i][j] = '+';
            } else if (pixel[i][j] < 250) {
                ascii_art[i][j] = '-';
            } else {
                ascii_art[i][j] = ' ';
            }
        }
    }

    // Print the ASCII art
    print_ascii_art(ascii_art, width, height);
}

void print_ascii_art(char ascii_art[MAX_HEIGHT][MAX_WIDTH], int width, int height)
{
    int i, j;

    printf("\n");
    printf("Here is your ASCII art:\n");
    printf("\n");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}