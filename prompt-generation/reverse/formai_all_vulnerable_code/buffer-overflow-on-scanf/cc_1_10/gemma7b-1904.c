//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024];
    printf("Enter image data (separate pixels with spaces): ");
    scanf("%s", image);

    int width = 0;
    int height = 0;
    char pixel;

    // Determine image dimensions
    for (int i = 0; image[i] != '\0'; i++)
    {
        if (image[i] == ' ')
        {
            width++;
        }
        else if (image[i] == '\n')
        {
            height++;
        }
    }

    // Convert image data to ASCII art
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixel = image[x + y * width];

            switch (pixel)
            {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("=");
                    break;
                case '2':
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }

        printf("\n");
    }

    return 0;
}