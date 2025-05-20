//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int w, h, x, y;
    time_t t;
    srand(time(&t));

    printf("Enter width of pixel art (in multiples of 8): ");
    scanf("%d", &w);

    printf("Enter height of pixel art (in multiples of 8): ");
    scanf("%d", &h);

    int **pixels = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        pixels[i] = (int *)malloc(w * sizeof(int));
    }

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            pixels[y][x] = rand() % 2;
        }
    }

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (pixels[y][x] == 1)
            {
                printf("%c", 248);
            }
            else
            {
                printf("%c", 32);
            }
        }
        printf("\n");
    }

    free(pixels);

    return 0;
}