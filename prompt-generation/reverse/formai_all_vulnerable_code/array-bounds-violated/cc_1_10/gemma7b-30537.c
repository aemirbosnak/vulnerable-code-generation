//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

int main()
{
    // GPS Simulation Parameters
    double latitude = 37.733233;
    double longitude = -122.419417;
    double bearing = 120.0;
    double speed = 20.0;

    // Map Dimensions
    int mapWidth = 1000;
    int mapHeight = 1000;

    // Car Position and Direction
    int carX = (int)(longitude * mapWidth);
    int carY = (int)(latitude * mapHeight);
    int carDirection = (int)(bearing * 180.0);

    // Map Display
    char map[mapHeight][mapWidth];

    // Draw Roads
    map[carY][carX] = 'R';

    // Draw Car
    map[carY][carX] = 'C';

    // Display Map
    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            printf("%c ", map[y][x]);
        }

        printf("\n");
    }

    // Update GPS Location
    latitude += 0.01 * speed * sin(PI * bearing / 180.0);
    longitude += 0.01 * speed * cos(PI * bearing / 180.0);

    // Display New Location
    printf("New Location: %.6f, %.6f\n", latitude, longitude);

    return 0;
}