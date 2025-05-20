//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
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
        cars[i].speed = rand() % 5 + 1;
        cars[i].direction = rand() % 2;
    }
}

void simulateTrafficFlow()
{
    time_t start_time = time(NULL);
    time_t end_time = start_time + 60;

    while (time(NULL) < end_time)
    {
        for (int i = 0; i < MAX_CARS; i++)
        {
            switch (cars[i].direction)
            {
                case 0:
                    cars[i].position += cars[i].speed;
                    break;
                case 1:
                    cars[i].position -= cars[i].speed;
                    break;
            }

            if (cars[i].position > 1000)
            {
                cars[i].direction = 1;
                cars[i].position = 0;
            }

            if (cars[i].position < 0)
            {
                cars[i].direction = 0;
                cars[i].position = 1000;
            }
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