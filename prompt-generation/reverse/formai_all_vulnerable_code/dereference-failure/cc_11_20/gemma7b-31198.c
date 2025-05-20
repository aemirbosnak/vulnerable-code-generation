//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, y, i, j, n, m, k, traffic_light, direction, speed;
    char **grid;

    // Traffic Light Simulation
    traffic_light = 0;

    // Grid Size
    n = 5;
    m = 5;

    // Initialize Grid
    grid = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        grid[i] = (char *)malloc(m * sizeof(char));
        for (j = 0; j < m; j++)
        {
            grid[i][j] = '0';
        }
    }

    // Car Movement
    x = 2;
    y = 2;
    direction = 1;

    // Speed
    speed = 1;

    // Timer
    k = 0;

    // Game Loop
    while (1)
    {
        // Traffic Light Change
        if (k % 5 == 0)
        {
            traffic_light = (traffic_light + 1) % 3;
        }

        // Car Movement
        switch (direction)
        {
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
            case 4:
                x++;
                break;
        }

        // Grid Update
        grid[x][y] = 'C';

        // Display Grid
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        // Sleep
        sleep(speed);

        // Increment Timer
        k++;
    }

    return 0;
}