//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define traffic light status
    int traffic_light_status = 0;

    // Define number of vehicles
    int num_vehicles = 0;

    // Define vehicle positions
    int vehicle_positions[10] = {0};

    // Loop to simulate traffic flow
    while (1)
    {
        // Display traffic light status
        printf("Traffic Light Status: ");
        switch (traffic_light_status)
        {
            case 0:
                printf("Red");
                break;
            case 1:
                printf("Yellow");
                break;
            case 2:
                printf("Green");
                break;
        }

        // Increment number of vehicles if green light is on
        if (traffic_light_status == 2)
        {
            num_vehicles++;
        }

        // Move vehicles forward if green light is on
        if (num_vehicles > 0)
        {
            for (int i = 0; i < num_vehicles; i++)
            {
                vehicle_positions[i]++;
            }
        }

        // Display vehicle positions
        printf("Vehicle Positions: ");
        for (int i = 0; i < num_vehicles; i++)
        {
            printf("%d ", vehicle_positions[i]);
        }

        // Pause for 2 seconds
        sleep(2);

        // Change traffic light status
        traffic_light_status = (traffic_light_status + 1) % 3;
    }

    return 0;
}