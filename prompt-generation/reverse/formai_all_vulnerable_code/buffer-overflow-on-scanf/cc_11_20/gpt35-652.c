//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define MAX_PIXEL_VALUE 255

void printAsciiArt(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height);

int main(void)
{
    int image[MAX_WIDTH][MAX_HEIGHT];
    int width, height, maxPixelValue, pixelValue;

    char fileType[3];

    printf("Please enter the file type (P2): ");
    scanf("%s", fileType);

    if(strcmp(fileType, "P2") != 0)
    {
        printf("Error: Invalid file type. Program only supports '.pgm' files.\n");
        return 1;
    }

    printf("Please enter the width of the image: ");
    scanf("%d", &width);

    printf("Please enter the height of the image: ");
    scanf("%d", &height);

    printf("Please enter the maximum pixel value: ");
    scanf("%d", &maxPixelValue);

    if(maxPixelValue > MAX_PIXEL_VALUE)
    {
        printf("\nError: The maximum pixel value exceeds the maximum allowable value of %d.\n", MAX_PIXEL_VALUE);
        return 1;
    }

    printf("Please input the pixel values of the image, separated by spaces:\n");

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            scanf("%d", &pixelValue);

            if(pixelValue > maxPixelValue)
            {
                printf("\nError: One or more pixel values exceeded the maximum allowable value of %d.\n", maxPixelValue);
                return 1;
            }

            image[j][i] = pixelValue;
        }
    }

    printf("\n");

    printAsciiArt(image, width, height);

    return 0;
}

void printAsciiArt(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height)
{
    int grayscaleValue;
    char asciiPixel;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            grayscaleValue = (int)(image[j][i] / 3.0);

            if(grayscaleValue >= 0 && grayscaleValue <= 25) asciiPixel = '#';
            else if(grayscaleValue >= 26 && grayscaleValue <= 51) asciiPixel = 'A';
            else if(grayscaleValue >= 52 && grayscaleValue <= 77) asciiPixel = 'H';
            else if(grayscaleValue >= 78 && grayscaleValue <= 103) asciiPixel = 'M';
            else if(grayscaleValue >= 104 && grayscaleValue <= 129) asciiPixel = 'N';
            else if(grayscaleValue >= 130 && grayscaleValue <= 155) asciiPixel = 'T';
            else if(grayscaleValue >= 156 && grayscaleValue <= 181) asciiPixel = 'V';
            else if(grayscaleValue >= 182 && grayscaleValue <= 207) asciiPixel = 'Y';
            else if(grayscaleValue >= 208 && grayscaleValue <= 233) asciiPixel = '+';
            else if(grayscaleValue >= 234 && grayscaleValue <= 255) asciiPixel = '"';
            else asciiPixel = ' ';

            putchar(asciiPixel);
        }

        putchar('\n');
    }
}