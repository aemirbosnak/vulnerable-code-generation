//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 1000

int main()
{
    // Map creation
    int **map = (int **)malloc(MAP_SIZE * sizeof(int *));
    for(int i = 0; i < MAP_SIZE; i++)
    {
        map[i] = (int *)malloc(MAP_SIZE * sizeof(int));
        for(int j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = 0;
        }
    }

    // Vehicle position
    int x = 0, y = 0;

    // Current direction
    int direction = 0;

    // Simulation loop
    int time = 0;
    while(1)
    {
        // Update time
        time++;

        // Move vehicle
        switch(direction)
        {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
        }

        // Check if vehicle has reached destination
        if(x == 500 && y == 500)
        {
            printf("Destination reached!\n");
            break;
        }

        // Draw map
        for(int i = 0; i < MAP_SIZE; i++)
        {
            for(int j = 0; j < MAP_SIZE; j++)
            {
                if(map[i][j] == 1)
                {
                    printf("%c ", '*');
                }
                else
                {
                    printf("%c ", '.');
                }
            }
            printf("\n");
        }

        // Display current position
        printf("Position: (%d, %d)\n", x, y);

        // Sleep for 1 second
        sleep(1);
    }

    // Free memory
    for(int i = 0; i < MAP_SIZE; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}