//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define ASCII_CHARACTERS " .,-~:;=!*#$@" // ASCII characters sorted by intensity, from low to high
#define NUM_ASCII 13 // number of ASCII characters used in conversion

// function to convert RGB value of pixel to grayscale value
int rgbToGray(int r, int g, int b)
{
    return (int)(0.2989 * r + 0.5870 * g + 0.1140 * b);
}

int main(int argc, char **argv)
{
    // check for valid input
    if (argc != 2)
    {
        printf("Usage: %s <input_image_name>\n", argv[0]);
        return 1;
    }

    // open input image file in binary mode
    FILE *imageFile = fopen(argv[1], "rb");
    if (imageFile == NULL)
    {
        printf("Error opening image file %s.\n", argv[1]);
        return 1;
    }

    // read header information from input image
    char magicNumber[3];
    int width, height, maxVal;
    fscanf(imageFile, "%s\n%d %d\n%d\n", magicNumber, &width, &height, &maxVal);

    // check for valid image format (P6)
    if (strcmp(magicNumber, "P6") != 0)
    {
        printf("Invalid image format.\n");
        fclose(imageFile);
        return 1;
    }

    // check for valid image dimensions
    if (width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        printf("Image dimensions exceed maximum allowable size (%d x %d).\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(imageFile);
        return 1;
    }

    // initialize variables for image data
    unsigned char red, green, blue;
    int grayscale;
    char asciiArt[MAX_HEIGHT][MAX_WIDTH + 1]; // +1 for null termination

    // read image data and convert to grayscale
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // read RGB values from image file
            fread(&red, sizeof(unsigned char), 1, imageFile);
            fread(&green, sizeof(unsigned char), 1, imageFile);
            fread(&blue, sizeof(unsigned char), 1, imageFile);

            // convert RGB values to grayscale value
            grayscale = rgbToGray(red, green, blue);

            // convert grayscale value to ASCII character
            int index = round((double)grayscale / (double)maxVal * (double)(NUM_ASCII - 1));
            asciiArt[i][j] = ASCII_CHARACTERS[index];
        }
        asciiArt[i][width] = '\0'; // null terminate each line
    }
    fclose(imageFile);

    // print ASCII art to console
    for (int i = 0; i < height; i++)
    {
        printf("%s\n", asciiArt[i]);
    }

    return 0;
}