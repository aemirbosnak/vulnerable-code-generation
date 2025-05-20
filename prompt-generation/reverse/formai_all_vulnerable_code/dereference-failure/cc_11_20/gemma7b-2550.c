//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 64
#define HEIGHT 32

int main()
{
    int **pixels = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        pixels[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize pixels
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            pixels[y][x] = 0;
        }
    }

    // Draw a line
    pixels[10][0] = 1;
    pixels[10][1] = 1;
    pixels[10][2] = 1;
    pixels[10][3] = 1;

    // Draw a circle
    for (int r = 0; r < 5; r++)
    {
        for (int y = -r; y <= r; y++)
        {
            for (int x = -r; x <= r; x++)
            {
                int d = x * x + y * y;
                if (d <= r * r)
                {
                    pixels[10 + y][10 + x] = 1;
                }
            }
        }
    }

    // Print pixels
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%d ", pixels[y][x]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}