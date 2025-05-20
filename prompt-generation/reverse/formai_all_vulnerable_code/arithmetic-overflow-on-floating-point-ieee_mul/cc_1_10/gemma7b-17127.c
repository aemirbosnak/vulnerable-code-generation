//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    // Map coordinates
    int x_map = 0;
    int y_map = 0;

    // Current location coordinates
    int x_curr = 10;
    int y_curr = 10;

    // Distance and bearing
    int distance = 0;
    float bearing = 0.0f;

    // Direction of travel
    int direction = 1;

    // Map boundaries
    const int x_max = 100;
    const int x_min = -100;
    const int y_max = 100;
    const int y_min = -100;

    // Simulate navigation
    while (1)
    {
        // Calculate distance and bearing
        distance = (int)round(sqrt(pow(x_curr - x_map, 2) + pow(y_curr - y_map, 2)));
        bearing = (float)atan2((double)(y_curr - y_map), (double)(x_curr - x_map)) * 180.0f / PI;

        // Update current location
        x_curr += direction * distance * cos(PI * bearing / 180.0f);
        y_curr += direction * distance * sin(PI * bearing / 180.0f);

        // Display map and current location
        printf("Map: (%d, %d)\n", x_map, y_map);
        printf("Current location: (%d, %d)\n", x_curr, y_curr);
        printf("Distance: %d, Bearing: %.2f\n", distance, bearing);

        // Check if boundary is reached
        if (x_curr > x_max || x_curr < x_min || y_curr > y_max || y_curr < y_min)
        {
            // Change direction and update map coordinates
            direction *= -1;
            x_map = x_curr;
            y_map = y_curr;
        }

        // Pause for 1 second
        sleep(1);
    }

    return 0;
}