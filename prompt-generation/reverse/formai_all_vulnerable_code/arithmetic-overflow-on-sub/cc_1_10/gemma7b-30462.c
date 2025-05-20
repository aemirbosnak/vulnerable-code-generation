//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
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
        cars[i].position = rand() % 100;
        cars[i].speed = rand() % 5 + 1;
        cars[i].direction = rand() % 2;
    }
}

void simulateTrafficFlow()
{
    time_t tStart = time(NULL);

    // Move cars
    for (int i = 0; i < MAX_CARS; i++)
    {
        switch (cars[i].direction)
        {
            case 0:
                cars[i].position++;
                break;
            case 1:
                cars[i].position--;
                break;
        }

        // Change lanes
        if (cars[i].position % MAX_LANE == 0)
        {
            cars[i].lane = rand() % MAX_LANE;
        }
    }

    // Check collisions
    for (int i = 0; i < MAX_CARS; i++)
    {
        for (int j = i; j < MAX_CARS; j++)
        {
            if (i != j && cars[i].position == cars[j].position && cars[i].lane == cars[j].lane)
            {
                // Collision!
                printf("Collision!\n");
                exit(1);
            }
        }
    }

    time_t tEnd = time(NULL);
    printf("Time elapsed: %ld seconds\n", tEnd - tStart);
}

int main()
{
    initializeCars();
    simulateTrafficFlow();

    return 0;
}