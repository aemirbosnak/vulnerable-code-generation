//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>

// Change the values according to the image aspect ratio
#define WIDTH 120
#define HEIGHT 50

// Change the threshold value to adjust the brightness of the image
#define THRESHOLD 128

// Change the characters for each intensity level
const char *chars = " .:-=+*#%@";

// Function to get the grayscale value of a pixel
int getPixelGrayScaleValue(const unsigned char *image, int x, int y, int channels)
{
    // Formula to calculate grayscale value from RGB values
    int r = image[(y * WIDTH + x) * channels];
    int g = image[(y * WIDTH + x) * channels + 1];
    int b = image[(y * WIDTH + x) * channels + 2];
    
    return 0.21 * r + 0.72 * g + 0.07 * b;
}

int main(int argc, char *argv[])
{
    // Check if user provided the input image path
    if (argc != 2)
    {
        printf("Usage: %s [input image path]\n", argv[0]);
        exit(1);
    }

    // Open the input image file
    FILE *fp = fopen(argv[1], "rb");
    
    if (fp == NULL)
    {
        printf("Error: File not found\n");
        exit(1);
    }

    // Read the headers of the image file
    char magicNumber[3];
    fgets(magicNumber, 3, fp);

    int width, height, maxValue;
    fscanf(fp, "%d %d %d", &width, &height, &maxValue);
    
    // Check if the image is valid
    if (strcmp(magicNumber, "P6") != 0 || width != WIDTH || height != HEIGHT || maxValue > 255)
    {
        printf("Error: Invalid image format\n");
        fclose(fp);
        exit(1);
    }

    // Allocate memory for the image data
    unsigned char *imageData = malloc(WIDTH * HEIGHT * 3);

    // Read the image data from the file
    fread(imageData, 1, WIDTH * HEIGHT * 3, fp);

    // Close the input image file
    fclose(fp);

    // Create a new buffer for the ASCII art
    char asciiArt[HEIGHT][WIDTH];

    // Convert the image data to grayscale and generate the ASCII art
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int grayscaleValue = getPixelGrayScaleValue(imageData, x, y, 3);

            if (grayscaleValue >= THRESHOLD)
            {
                asciiArt[y][x] = chars[(int) round(((double) grayscaleValue / 255) * (strlen(chars) - 1))];
            }
            else
            {
                asciiArt[y][x] = ' ';
            }
        }
    }

    // Display the ASCII art on the console
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", asciiArt[y][x]);
        }

        printf("\n");
    }

    // Free the memory allocated for the image data
    free(imageData);

    return 0;
}