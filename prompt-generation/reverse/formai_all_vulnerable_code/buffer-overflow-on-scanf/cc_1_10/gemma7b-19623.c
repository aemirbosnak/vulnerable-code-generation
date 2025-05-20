//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

int main()
{
    int width, height, i, j, x, y;
    char **ascii_art;

    printf("Enter the width of the ASCII art (max %d): ", MAX_WIDTH);
    scanf("%d", &width);

    printf("Enter the height of the ASCII art (max %d): ", MAX_HEIGHT);
    scanf("%d", &height);

    ascii_art = (char **)malloc(height * sizeof(char *));
    for (i = 0; i < height; i++)
    {
        ascii_art[i] = (char *)malloc(width * sizeof(char));
    }

    printf("Enter the ASCII art (each line separated by a newline):\n");
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            scanf("%c", &ascii_art[y][x]);
        }
    }

    printf("Your ASCII art:\n");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < height; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}