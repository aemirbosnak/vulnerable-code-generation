//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPixel(int pixel)
{
    if (pixel == 0) printf(" ");
    else printf("%c", pixel);
}

void generatePixelArt(int width, int height)
{
    int pixelArt[width][height];
    int i, j;

    srand(time(NULL)); // initialize random seed

    // generate pixel art array
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            pixelArt[i][j] = rand() % 2; // assign 0 or 1 randomly
        }
    }

    // print pixel art
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printPixel(pixelArt[j][i]);
        }
        printf("\n"); // new line for next row
    }
}

int main()
{
    int width, height;

    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);

    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    generatePixelArt(width, height);

    return 0;
}