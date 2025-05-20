//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **image, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", image[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    char **image = NULL;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    image = malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        image[i] = malloc(w * sizeof(char) + 1);
    }

    printf("Enter the pixels of the image (separated by spaces): ");
    char pixels[w * h];
    scanf("%s", pixels);

    int index = 0;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            image[y][x] = pixels[index];
            index++;
        }
    }

    draw_ascii_art(image, w, h);

    free(image);

    return 0;
}