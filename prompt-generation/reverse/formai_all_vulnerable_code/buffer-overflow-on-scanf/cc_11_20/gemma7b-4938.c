//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char image[1024];
    printf("Enter the image data (separated by spaces): ");
    scanf("%s", image);

    int width = 0;
    for (int i = 0; image[i] != '\0'; i++)
    {
        if (image[i] == ' ')
        {
            width++;
        }
    }

    int height = 1;
    for (int i = 0; image[i] != '\0'; i++)
    {
        if (image[i] == '\n')
        {
            height++;
        }
    }

    char ascii_image[height][width];

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            ascii_image[r][c] = image[r * width + c];
        }
    }

    printf("ASCII Image:\n");
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            switch (ascii_image[r][c])
            {
                case '.':
                    printf(".");
                    break;
                case '#':
                    printf("#");
                    break;
                case ' ':
                    printf(" ");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}