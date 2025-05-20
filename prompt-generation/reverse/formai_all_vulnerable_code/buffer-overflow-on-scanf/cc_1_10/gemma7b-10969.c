//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void pixel_art_generator()
{
    int width, height, x, y;

    printf("Enter the width of your pixel art: ");
    scanf("%d", &width);

    printf("Enter the height of your pixel art: ");
    scanf("%d", &height);

    int **pixels = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        pixels[i] = (int *)malloc(width * sizeof(int));
    }

    printf("Enter the pixel values (separated by commas): ");
    char *pixel_values = malloc(width * height);
    scanf("%s", pixel_values);

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            pixels[y][x] = pixel_values[y * width + x];
        }
    }

    printf("Your pixel art:\n");
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            if (pixels[y][x] == 1)
            {
                printf("■ ");
            }
            else
            {
                printf("□ ");
            }
        }
        printf("\n");
    }

    free(pixels);
    free(pixel_values);
}

int main()
{
    pixel_art_generator();

    return 0;
}