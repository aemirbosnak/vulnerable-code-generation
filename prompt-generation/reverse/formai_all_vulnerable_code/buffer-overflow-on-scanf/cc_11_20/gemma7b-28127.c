//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char img[1000];
    printf("Enter the image: ");
    scanf("%s", img);

    int width = 0, height = 0;
    for (int i = 0; img[i] != '\0'; i++)
    {
        if (img[i] == ' ')
        {
            width++;
        }
        else if (img[i] == '\n')
        {
            height++;
        }
    }

    char ascii_img[height][width];
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            ascii_img[r][c] = img[r * width + c];
        }
    }

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            switch (ascii_img[r][c])
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
                default:
                    printf("%c", ascii_img[r][c]);
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}