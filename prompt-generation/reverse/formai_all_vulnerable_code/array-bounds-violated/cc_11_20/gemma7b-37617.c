//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

int main()
{
    int x, y, map[MAP_SIZE][MAP_SIZE], current_x, current_y, destination_x, destination_y;

    // Initialize the map
    for (x = 0; x < MAP_SIZE; x++)
    {
        for (y = 0; y < MAP_SIZE; y++)
        {
            map[x][y] = 0;
        }
    }

    // Place some obstacles on the map
    map[5][10] = 1;
    map[10][15] = 1;
    map[15][20] = 1;

    // Get the current position of Sherlock Holmes
    current_x = 12;
    current_y = 18;

    // Get the destination position of Sherlock Holmes
    destination_x = 10;
    destination_y = 12;

    // Calculate the direction of travel
    int direction = 0;
    if (destination_x - current_x > 0)
    {
        direction = 1;
    }
    else if (destination_x - current_x < 0)
    {
        direction = 3;
    }
    else if (destination_y - current_y > 0)
    {
        direction = 2;
    }
    else if (destination_y - current_y < 0)
    {
        direction = 4;
    }

    // Move Sherlock Holmes in the direction of travel
    switch (direction)
    {
        case 1:
            current_x++;
            break;
        case 2:
            current_y++;
            break;
        case 3:
            current_x--;
            break;
        case 4:
            current_y--;
            break;
    }

    // Check if Sherlock Holmes has reached the destination
    if (current_x == destination_x && current_y == destination_y)
    {
        printf("Congratulations, Sherlock Holmes, you have reached the destination.\n");
    }
    else
    {
        printf("Sorry, Sherlock Holmes, you have not reached the destination.\n");
    }

    return 0;
}