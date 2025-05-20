//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int i, j, k, l, m, n, x, y, z;
    int traffic_light_status = 0;
    int car_location[100] = {0};
    int car_speed[100] = {0};
    int number_of_cars = 0;

    time_t t;
    srand(time(NULL));

    while (1)
    {
        t = time(NULL);

        // Generate new cars
        if (rand() % 100 < 10)
        {
            car_location[number_of_cars] = rand() % 100;
            car_speed[number_of_cars] = rand() % 5 + 1;
            number_of_cars++;
        }

        // Move cars
        for (i = 0; i < number_of_cars; i++)
        {
            car_location[i] += car_speed[i] * t / 1000;

            // Change traffic light status
            if (car_location[i] % 100 == 0)
            {
                traffic_light_status = (traffic_light_status + 1) % 3;
            }

            // Collision detection
            for (j = 0; j < number_of_cars; j++)
            {
                if (i != j && car_location[i] == car_location[j])
                {
                    printf("COLLISION!!!\n");
                    exit(0);
                }
            }
        }

        // Update traffic light
        if (traffic_light_status == 0)
        {
            printf("Traffic light: green.\n");
        }
        else if (traffic_light_status == 1)
        {
            printf("Traffic light: yellow.\n");
        }
        else
        {
            printf("Traffic light: red.\n");
        }

        // Print car locations
        for (k = 0; k < number_of_cars; k++)
        {
            printf("Car %d location: %d.\n", k, car_location[k]);
        }

        // Sleep
        sleep(1);
    }

    return 0;
}