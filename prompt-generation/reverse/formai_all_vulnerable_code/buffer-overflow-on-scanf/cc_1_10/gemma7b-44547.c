//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int width, height, seed, x, y, pixel;
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);
    printf("Enter the seed for the random number generator: ");
    scanf("%d", &seed);
    srand(seed);

    // Allocate memory for the pixel art
    int **pixels = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++)
    {
        pixels[i] = (int*)malloc(width * sizeof(int));
    }

    // Generate pixels
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            pixel = rand() % 2;
            pixels[y][x] = pixel;
        }
    }

    // Print the pixel art
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            printf("%d ", pixels[y][x]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < height; i++)
    {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}