//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024];
    printf("Enter image data (separated by spaces): ");
    gets(image);

    int width = 0;
    int height = 0;
    char **pixels = NULL;

    // Parse image data
    char *p = image;
    while (*p)
    {
        if (*p == ' ')
        {
            width++;
        }
        else if (*p == '\n')
        {
            height++;
        }
        else
        {
            pixels = realloc(pixels, (height + 1) * sizeof(char *));
            pixels[height] = malloc(width * sizeof(char));
            pixels[height][width] = *p;
        }
        p++;
    }

    // Convert pixels to ASCII art
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            switch (pixels[h][w])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("o ");
                    break;
                case 3:
                    printf("* ");
                    break;
            }
        }
        printf("\n");
    }

    // Free memory
    for (int h = 0; h < height; h++)
    {
        free(pixels[h]);
    }
    free(pixels);

    return 0;
}