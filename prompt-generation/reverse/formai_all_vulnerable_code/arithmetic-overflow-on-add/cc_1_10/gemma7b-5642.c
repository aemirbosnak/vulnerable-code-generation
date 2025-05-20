//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    int direction;
} Car;

Car cars[MAX_CARS];

void initializeCars()
{
    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i].lane = rand() % MAX_LANE;
        cars[i].position = rand() % 1000;
        cars[i].speed = rand() % 5;
        cars[i].direction = rand() % 2;
    }
}

void simulateTrafficFlow()
{
    time_t t = time(NULL);

    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i].position += cars[i].speed * t / 1000;

        if (cars[i].direction == 0)
        {
            if (cars[i].lane == 0)
            {
                cars[i].direction = 1;
            }
        }
        else
        {
            if (cars[i].lane == MAX_LANE - 1)
            {
                cars[i].direction = 0;
            }
        }

        cars[i].lane = (cars[i].lane + cars[i].direction) % MAX_LANE;
    }
}

int main()
{
    initializeCars();
    simulateTrafficFlow();

    return 0;
}