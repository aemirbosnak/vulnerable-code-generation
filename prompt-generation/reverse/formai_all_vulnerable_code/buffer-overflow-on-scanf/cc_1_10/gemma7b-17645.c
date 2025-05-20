//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

int main()
{
    char image[1024];
    printf("Enter image data (separate pixels with spaces): ");
    scanf("%s", image);

    int width = 0;
    for (int i = 0; image[i] != '\0'; i++)
    {
        if (image[i] != ' ')
        {
            width++;
        }
    }

    int height = 1;
    for (int i = 0; image[i] != '\0'; i++)
    {
        if (image[i] == ' ')
        {
            height++;
        }
    }

    char ascii_image[height][MAX_WIDTH];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            ascii_image[h][w] = image[h * width + w] == ' ' ? '.' : '#';
        }
    }

    printf("ASCII Image:\n");
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            printf("%c ", ascii_image[h][w]);
        }
        printf("\n");
    }

    return 0;
}