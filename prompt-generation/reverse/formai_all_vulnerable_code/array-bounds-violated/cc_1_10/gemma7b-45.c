//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("clear");

    // Create a grid of squares
    char grid[10][20] = {{'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'-',' '},
                              {'.','.'},
                              {'.','.'}
                           };

    // Place the invader in a random position
    int invader_x = rand() % 20;
    int invader_y = rand() % 10;
    grid[invader_y][invader_x] = 'I';

    // Create the invaders
    char invaders[5][5] = {
        {'I','I','I','I','I'},
        {'I','I','I','I','I'},
        {'I','I','I','I','I'},
        {'I','I','I','I','I'},
        {'I','I','I','I','I'}
    };

    // Move the invaders
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (invaders[i][j] == 'I')
            {
                invaders[i][j] = '.';
                invaders[i-1][j] = 'I';
            }
        }
    }

    // Print the grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}