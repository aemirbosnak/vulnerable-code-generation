//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 5

typedef struct Car
{
    int position;
    int direction;
    int speed;
} Car;

Car cars[MAX_CARS];

void initializeCars()
{
    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i].position = 0;
        cars[i].direction = 1;
        cars[i].speed = rand() % 5 + 1;
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
                case 1:
                    cars[i].position++;
                    if (cars[i].position >= 10)
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
                cars[i].speed = rand() % 5 + 1;
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