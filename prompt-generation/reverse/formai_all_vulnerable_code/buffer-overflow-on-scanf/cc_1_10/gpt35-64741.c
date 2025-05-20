//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void generatePixelArt(int pixels[WIDTH][HEIGHT], int numColors);

int main()
{
    srand(time(NULL));
    int pixels[WIDTH][HEIGHT];
    int numColors;

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    generatePixelArt(pixels, numColors);

    printf("Generated Pixel Art: \n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void generatePixelArt(int pixels[WIDTH][HEIGHT], int numColors)
{
    // Initialize all pixels to -1
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            pixels[i][j] = -1;
        }
    }

    // Generate random colors for each pixel
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int color = rand() % numColors;
            pixels[i][j] = color;
        }
    }
}