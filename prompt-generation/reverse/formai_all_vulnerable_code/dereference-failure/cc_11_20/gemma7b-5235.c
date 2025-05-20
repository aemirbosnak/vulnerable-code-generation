//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    // Allocate memory for traffic light array
    int *traffic_lights = (int *)malloc(5 * sizeof(int));
    traffic_lights[0] = 0;
    traffic_lights[1] = 1;
    traffic_lights[2] = 2;
    traffic_lights[3] = 0;
    traffic_lights[4] = 1;

    // Allocate memory for car array
    int *cars = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        cars[i] = 0;
    }

    // Initialize timer
    srand(time(NULL));
    int timer = 0;

    // Simulate traffic flow
    while (1)
    {
        // Cars move forward
        for (int i = 0; i < 10; i++)
        {
            if (cars[i] > 0)
            {
                cars[i]--;
            }
        }

        // Randomly spawn new cars
        if (rand() % 100 < 20)
        {
            cars[rand() % 10] = 10;
        }

        // Traffic light changes
        timer++;
        if (timer % 5 == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                traffic_lights[i] = (traffic_lights[i] + 1) % 3;
            }
        }

        // Print traffic status
        printf("Traffic Light Status:");
        for (int i = 0; i < 5; i++)
        {
            switch (traffic_lights[i])
            {
                case 0:
                    printf(" Red ");
                    break;
                case 1:
                    printf(" Yellow ");
                    break;
                case 2:
                    printf(" Green ");
                    break;
            }
        }

        printf("\n");

        // Sleep for a while
        sleep(1);
    }

    return 0;
}