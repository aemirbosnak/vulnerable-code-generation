//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **art, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", art[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    char **art = NULL;
    int w = 0, h = 0;

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &w);

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    art = malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        art[i] = malloc(w * sizeof(char) + 1);
    }

    printf("Enter the ASCII art: ");
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            scanf("%c", &art[y][x]);
        }
    }

    draw_ascii_art(art, w, h);

    for (int i = 0; i < h; i++)
    {
        free(art[i]);
    }
    free(art);

    return 0;
}