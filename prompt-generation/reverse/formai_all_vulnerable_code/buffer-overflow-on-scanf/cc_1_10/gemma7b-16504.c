//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024];
    int i, j, r, c;
    printf("Enter image data (separate pixels with spaces): ");
    scanf("%s", image);

    r = countRows(image);
    c = countCols(image);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            int pixel = image[i * c + j] - 48;
            switch (pixel)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
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

int countRows(char *image)
{
    int i = 0, rows = 0;
    while (image[i] != '\0')
    {
        if (image[i] != ' ' && image[i] != '\n')
        {
            rows++;
        }
        i++;
    }
    return rows;
}

int countCols(char *image)
{
    int i = 0, cols = 0;
    while (image[i] != '\0')
    {
        if (image[i] != ' ' && image[i] != '\n')
        {
            cols++;
        }
        i++;
    }
    return cols;
}