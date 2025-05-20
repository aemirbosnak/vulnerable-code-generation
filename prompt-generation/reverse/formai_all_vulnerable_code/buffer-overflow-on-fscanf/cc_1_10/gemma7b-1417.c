//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024];
    int i, j, r, g, b;
    FILE *fp;

    printf("Enter image file name: ");
    scanf("%s", image);

    fp = fopen(image, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d %d %d", &r, &g, &b);

    printf("Number of rows: ");
    scanf("%d", &i);

    printf("Number of columns: ");
    scanf("%d", &j);

    char **ascii_art = (char**)malloc(i * sizeof(char *) + 1);
    for (int n = 0; n < i; n++)
    {
        ascii_art[n] = (char *)malloc(j * sizeof(char) + 1);
    }

    for (i = 0; i < i; i++)
    {
        for (j = 0; j < j; j++)
        {
            int pixel_value = fgetc(fp);
            ascii_art[i][j] = (pixel_value - 0) / 32 + 32;
        }
    }

    fclose(fp);

    for (i = 0; i < i; i++)
    {
        for (j = 0; j < j; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    free(ascii_art);

    return 0;
}