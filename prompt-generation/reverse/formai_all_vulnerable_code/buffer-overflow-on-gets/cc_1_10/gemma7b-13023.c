//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1000];
    printf("Enter image data (separate pixels with spaces): ");
    gets(image);

    int width = 0;
    int height = 0;
    char pixel;
    for (pixel = image[0]; pixel != '\0'; pixel++)
    {
        if (pixel == ' ')
        {
            width++;
            height++;
        }
    }

    int **ascii_art = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++)
    {
        ascii_art[i] = (int*)malloc(width * sizeof(int));
    }

    pixel = image[0];
    int y = 0;
    while (pixel != '\0')
    {
        if (pixel == ' ')
        {
            ascii_art[y][width - 1] = '\0';
            y++;
        }
        else
        {
            ascii_art[y][width - 1] = pixel - 'a' + 32;
        }
        pixel++;
    }

    printf("ASCII art:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    free(ascii_art);

    return 0;
}