//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main()
{
    int width, height;
    int **pixels = NULL;

    printf("Enter the dimensions of the ASCII artwork (width x height): ");
    scanf("%d %d", &width, &height);

    pixels = (int **)malloc(height * sizeof(int *) + height);
    for (int r = 0; r < height; r++)
    {
        pixels[r] = (int *)malloc(width * sizeof(int) + width);
    }

    // Generate the ASCII artwork
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            pixels[r][c] = rand() % 2;
        }
    }

    // Print the ASCII artwork
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            if (pixels[r][c] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

    free(pixels);

    return 0;
}