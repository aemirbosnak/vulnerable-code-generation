//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[11];

    if (n >= 10)
    {
        itoa(n / 10, num);
        s = strcat(s, num);
        itoa(n % 10, num);
        s = strcat(s, num);
    }
    else
    {
        s = strcat(s, "0");
        s = strcat(s, num);
    }

    return;
}

void ascii_art(char **img, int w, int h)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%c ", img[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char **img = NULL;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    img = (char **)malloc(h * w * sizeof(char *));
    for (int i = 0; i < h; i++)
    {
        img[i] = (char *)malloc(w * sizeof(char));
    }

    printf("Enter the image data (each pixel as a number, separated by spaces): ");
    scanf("%s", img[0]);

    ascii_art(img, w, h);

    for (int i = 0; i < h; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}