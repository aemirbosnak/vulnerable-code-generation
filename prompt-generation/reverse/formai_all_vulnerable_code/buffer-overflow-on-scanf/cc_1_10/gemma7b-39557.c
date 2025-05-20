//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int w, h, r, g, b;
    printf("Enter the width of the pixel art (in pixels): ");
    scanf("%d", &w);
    printf("Enter the height of the pixel art (in pixels): ");
    scanf("%d", &h);

    // Allocate memory for the pixel art
    int **pixels = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        pixels[i] = (int*)malloc(w * sizeof(int));
    }

    // Generate random pixel art
    srand(time(NULL));
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            pixels[y][x] = rand() % 3;
        }
    }

    // Print the pixel art
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            switch (pixels[y][x])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("■");
                    break;
                case 2:
                    printf("●");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < h; i++)
    {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}