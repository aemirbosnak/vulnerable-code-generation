//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, m, i, j, x, y, z;
    printf("Enter the dimensions of the pixel art (n x m): ");
    scanf("%d %d", &n, &m);

    // Allocate memory for the pixel art
    int **pixel_art = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        pixel_art[i] = (int*)malloc(m * sizeof(int));
    }

    // Get the pixel art from the user
    printf("Enter the pixel art (1 for black, 0 for white): ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &pixel_art[i][j]);
        }
    }

    // Print the pixel art
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (pixel_art[i][j] == 1)
            {
                printf("■ ");
            }
            else
            {
                printf("□ ");
            }
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(pixel_art[i]);
    }
    free(pixel_art);

    return 0;
}