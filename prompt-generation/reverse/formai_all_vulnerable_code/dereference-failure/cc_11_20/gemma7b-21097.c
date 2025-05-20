//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **grid = NULL;
    int width, height, i, j, k, l, r, c, x;

    printf("Enter the width of the grid: ");
    scanf("%d", &width);

    printf("Enter the height of the grid: ");
    scanf("%d", &height);

    grid = (char**)malloc(height * sizeof(char*));
    for(i = 0; i < height; i++)
    {
        grid[i] = (char*)malloc(width * sizeof(char));
    }

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            grid[i][j] = '.';
        }
    }

    printf("Enter the number of commands: ");
    scanf("%d", &c);

    for(k = 0; k < c; k++)
    {
        printf("Enter the command (L/R/U/D/S): ");
        scanf("%c", &x);

        switch(x)
        {
            case 'L':
                r = -1;
                break;
            case 'R':
                r = 1;
                break;
            case 'U':
                l = -1;
                break;
            case 'D':
                l = 1;
                break;
            case 'S':
                l = 0;
                r = 0;
                break;
        }

        for(i = 0; i < height; i++)
        {
            for(j = 0; j < width; j++)
            {
                if(grid[i][j] == 'O')
                {
                    if(grid[i - l][j - r] == '.')
                    {
                        grid[i - l][j - r] = 'O';
                    }
                }
            }
        }
    }

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}