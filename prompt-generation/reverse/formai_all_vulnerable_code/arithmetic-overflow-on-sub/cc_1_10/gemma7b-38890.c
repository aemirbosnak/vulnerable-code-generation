//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int direction;
    int speed;
} Car;

void simulateTrafficFlow(Car cars[], int numCars)
{
    int i, j, k;
    time_t t = time(NULL);

    // Move cars randomly
    for (i = 0; i < numCars; i++)
    {
        cars[i].position++;

        // Change lane if necessary
        if (rand() % 10 == 0)
        {
            cars[i].lane = (cars[i].lane + 1) % MAX_LANE;
        }

        // Increase speed if not at maximum
        if (cars[i].speed < MAX_CARS)
        {
            cars[i].speed++;
        }

        // Simulate traffic light interaction
        if (cars[i].position % MAX_LANE == 0)
        {
            // Randomly choose direction
            cars[i].direction = (rand() % 2) ? -1 : 1;
        }
    }

    // Print car positions
    for (i = 0; i < numCars; i++)
    {
        printf("Car %d: lane %d, position %d, direction %d, speed %d\n", i, cars[i].lane, cars[i].position, cars[i].direction, cars[i].speed);
    }

    // Print time elapsed
    printf("Time elapsed: %ld seconds\n", time(NULL) - t);
}

int main()
{
    Car cars[MAX_CARS];

    // Initialize cars
    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i].lane = rand() % MAX_LANE;
        cars[i].position = rand() % MAX_LANE;
        cars[i].direction = (rand() % 2) ? -1 : 1;
        cars[i].speed = 1;
    }

    // Simulate traffic flow
    simulateTrafficFlow(cars, MAX_CARS);

    return 0;
}