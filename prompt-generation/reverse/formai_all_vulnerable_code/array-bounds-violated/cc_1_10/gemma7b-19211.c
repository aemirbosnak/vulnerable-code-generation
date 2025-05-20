//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANE 3

int main()
{
    // Traffic light timer
    int timer = 0;

    // Lane occupancy array
    int lane_occupancy[MAX_LANE] = {0, 0, 0};

    // Vehicle spawn rate
    int spawn_rate = 10;

    // Number of vehicles
    int num_vehicles = 0;

    // Vehicle movement parameters
    int direction = 1;
    int speed = 1;

    // Simulation loop
    while (1)
    {
        // Update traffic light timer
        timer++;

        // Spawn vehicles
        if (timer % spawn_rate == 0)
        {
            num_vehicles++;
            lane_occupancy[rand() % MAX_LANE] = 1;
        }

        // Move vehicles
        for (int i = 0; i < num_vehicles; i++)
        {
            // Change direction if necessary
            if (lane_occupancy[(direction + 1) % MAX_LANE] == 0)
            {
                direction *= -1;
            }

            // Move vehicle forward
            lane_occupancy[lane_occupancy[i]] = 0;
            lane_occupancy[i] = direction;
        }

        // Display traffic light status
        printf("Traffic light status: ");
        for (int i = 0; i < MAX_LANE; i++)
        {
            if (lane_occupancy[i] == 1)
            {
                printf("Green");
            }
            else
            {
                printf("Red");
            }
            printf(", ");
        }

        printf("\n");

        // Sleep for a while
        sleep(1);
    }

    return 0;
}