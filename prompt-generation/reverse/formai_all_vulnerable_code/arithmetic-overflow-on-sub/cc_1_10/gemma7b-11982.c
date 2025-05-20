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
        cars[i].position = rand() % MAX_LANE;
        cars[i].speed = rand() % 5;
        cars[i].direction = rand() % 2;
    }
}

void simulateTrafficFlow()
{
    time_t start = time(NULL);
    while (time(NULL) - start < 10)
    {
        for (int i = 0; i < MAX_CARS; i++)
        {
            switch (cars[i].direction)
            {
                case 0:
                    cars[i].position++;
                    if (cars[i].position >= MAX_LANE)
                        cars[i].direction = 1;
                    break;
                case 1:
                    cars[i].position--;
                    if (cars[i].position <= 0)
                        cars[i].direction = 0;
                    break;
            }

            cars[i].lane = rand() % MAX_LANE;
        }

        sleep(1);
    }
}

int main()
{
    initializeCars();
    simulateTrafficFlow();

    return 0;
}