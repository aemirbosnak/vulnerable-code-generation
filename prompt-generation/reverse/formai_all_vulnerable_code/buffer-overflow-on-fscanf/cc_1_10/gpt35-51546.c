//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000 // maximum width of image
#define MAX_HEIGHT 1000 // maximum height of image
#define MAX_PIXEL_VAL 255 // maximum RGB value

// function to convert pixel RGB value to corresponding grayscale value
int getGrayScale(unsigned char red, unsigned char green, unsigned char blue) {
    return 0.2989 * red + 0.5870 * green + 0.1140 * blue; // formula for calculating grayscale value
}

int main(int argc, char *argv[]) {
    // check if valid number of arguments given
    if (argc != 2) {
        printf("Invalid number of arguments!\nUsage: ./convert <image_file_name>\n");
        return 1;
    }

    // open image file for reading in binary mode
    FILE *fptr = fopen(argv[1], "rb");
    if (fptr == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // read image header
    char format[3];
    int width, height, max_pixel_val;
    fscanf(fptr, "%s %d %d %d", format, &width, &height, &max_pixel_val);

    // check if image format is valid
    if (strcmp(format, "P6") != 0 || max_pixel_val > MAX_PIXEL_VAL || width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Invalid image format or size!\n");
        return 1;
    }

    // declare character array to store ASCII art
    char ascii_art[MAX_HEIGHT][MAX_WIDTH];

    // read image data and convert to grayscale and ASCII art
    int i, j, k;
    unsigned char red, green, blue;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&red, 1, 1, fptr); // read red value
            fread(&green, 1, 1, fptr); // read green value
            fread(&blue, 1, 1, fptr); // read blue value

            int grayscale = getGrayScale(red, green, blue); // convert to grayscale
            if (grayscale >= 230) { // if pixel is very light, assign a space character
                ascii_art[i][j] = ' ';
            }
            else if (grayscale >= 200) { // if pixel is light, assign a period character
                ascii_art[i][j] = '.';
            }
            else if (grayscale >= 180) { // if pixel is medium light, assign a hyphen character
                ascii_art[i][j] = '-';
            }
            else if (grayscale >= 160) { // if pixel is medium dark, assign an equal sign character
                ascii_art[i][j] = '=';
            }
            else if (grayscale >= 130) { // if pixel is dark, assign a plus sign character
                ascii_art[i][j] = '+';
            }
            else if (grayscale >= 100) { // if pixel is very dark, assign an asterisk character
                ascii_art[i][j] = '*';
            }
            else { // if pixel is almost black, assign a pound sign character
                ascii_art[i][j] = '#';
            }
        }
    }

    // print ASCII art to console
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // close image file
    fclose(fptr);

    return 0;
}