//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10
#define MAX_Lane 3

typedef struct Car
{
    int position;
    int lane;
    int direction;
    int speed;
} Car;

Car cars[MAX_Cars];

void initializeCars()
{
    for (int i = 0; i < MAX_Cars; i++)
    {
        cars[i].position = 0;
        cars[i].lane = 1;
        cars[i].direction = 1;
        cars[i].speed = 5;
    }
}

void simulateTrafficFlow()
{
    time_t start = time(NULL);

    while (time(NULL) - start < 10)
    {
        for (int i = 0; i < MAX_Cars; i++)
        {
            switch (cars[i].direction)
            {
                case 1:
                    cars[i].position++;
                    if (cars[i].position >= MAX_Lane)
                        cars[i].direction = -1;
                    break;
                case -1:
                    cars[i].position--;
                    if (cars[i].position <= 0)
                        cars[i].direction = 1;
                    break;
            }

            cars[i].speed--;
            if (cars[i].speed <= 0)
                cars[i].speed = 5;
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