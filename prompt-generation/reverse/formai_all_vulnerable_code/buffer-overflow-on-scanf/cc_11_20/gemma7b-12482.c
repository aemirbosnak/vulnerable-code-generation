//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x, y, w, h, r;
    char **a;

    printf("Enter the width of the canvas: ");
    scanf("%d", &w);

    printf("Enter the height of the canvas: ");
    scanf("%d", &h);

    a = (char **)malloc(h * sizeof(char *) + 1);
    for (y = 0; y < h; y++)
    {
        a[y] = (char *)malloc(w * sizeof(char) + 1);
    }

    printf("Enter the radius of the crater: ");
    scanf("%d", &r);

    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            if (x >= r && x < w - r && y >= r && y < h - r)
            {
                a[y][x] = '*';
            }
            else
            {
                a[y][x] = ' ';
            }
        }
    }

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            printf("%c", a[y][x]);
        }
        printf("\n");
    }

    for (y = 0; y < h; y++)
    {
        free(a[y]);
    }
    free(a);
}