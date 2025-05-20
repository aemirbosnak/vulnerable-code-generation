//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_DENSITY 256

// This function takes a 2D integer array of image pixels and its dimensions as input
// It then converts the image to ASCII art by mapping each pixel to an ASCII character
void convertToASCII(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height)
{
    char asciiArt[MAX_HEIGHT][MAX_WIDTH + 1]; // 2D character array to store the ASCII art

    char asciiChars[CHAR_DENSITY + 1] = " .:-=+*#%@";
    // The above string contains a set of ASCII characters arranged in decreasing order of density

    int charDensity[CHAR_DENSITY] = { 0 };
    // An array to store the density of each ASCII character in the image

    int maxDensity = 0; // The density of the most dense ASCII character in the image

    // Compute the density of each ASCII character in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel = image[i][j];
            charDensity[pixel]++;
            if (charDensity[pixel] > maxDensity) maxDensity = charDensity[pixel];
        }
    }

    // Map each pixel to an ASCII character based on its density
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel = image[i][j];
            int density = charDensity[pixel];
            int index = (int)floor(((float)density / (float)maxDensity) * CHAR_DENSITY);
            asciiArt[i][j] = asciiChars[index];
        }
        asciiArt[i][width] = '\0'; // Terminate the string with a null character
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++)
    {
        printf("%s\n", asciiArt[i]);
    }
}

int main()
{
    int image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    printf("Enter the width of the image (maximum %d): ", MAX_WIDTH);
    scanf("%d", &width);

    printf("Enter the height of the image (maximum %d): ", MAX_HEIGHT);
    scanf("%d", &height);

    printf("Enter the image pixel values (0-255):\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Here is the ASCII art representation of the image:\n");
    convertToASCII(image, width, height);

    return 0;
}