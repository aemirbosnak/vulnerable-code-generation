//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1000];
    printf("Enter the image data: ");
    fgets(image, 1000, stdin);

    int width = 0;
    int height = 0;
    char **pixels = NULL;

    // Parse the image data to extract the width and height
    char *p = image;
    while (*p)
    {
        if (*p == ' ')
        {
            width++;
            p++;
            break;
        }
        p++;
    }
    height = atoi(p);

    // Allocate memory for the pixels
    pixels = (char**)malloc(height * sizeof(char *) * width);
    for (int i = 0; i < height; i++)
    {
        pixels[i] = (char *)malloc(width * sizeof(char));
    }

    // Convert the image data to pixels
    p = image;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixels[i][j] = *p++;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch (pixels[i][j])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("o ");
                    break;
                default:
                    printf("X ");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < height; i++)
    {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}