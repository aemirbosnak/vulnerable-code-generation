//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024];
    printf("Enter image data (separate pixels with spaces): ");
    fgets(image, 1024, stdin);

    int w, h;
    printf("Enter image width: ");
    scanf("%d", &w);

    printf("Enter image height: ");
    scanf("%d", &h);

    int pixel_size = w * h;
    char **ascii_art = (char **)malloc(pixel_size * sizeof(char *));
    for (int i = 0; i < pixel_size; i++)
    {
        ascii_art[i] = (char *)malloc(20 * sizeof(char));
    }

    char pixel_values[3] = {'o', '.', ' '};
    int i = 0;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            ascii_art[i][0] = pixel_values[image[i] / 3];
            ascii_art[i][1] = pixel_values[image[i] / 3];
            ascii_art[i][2] = pixel_values[image[i] / 3];
            i++;
        }
    }

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%s", ascii_art[y][x]);
        }
        printf("\n");
    }

    for (int i = 0; i < pixel_size; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}