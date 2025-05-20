//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x;
    int y;
    int direction;
    int speed;
} Car;

void simulateTrafficFlow(Car cars[], int numCars)
{
    time_t tStart = time(NULL);

    for (int i = 0; i < numCars; i++)
    {
        cars[i].x++;
        switch (cars[i].direction)
        {
            case 0:
                cars[i].y++;
                break;
            case 1:
                cars[i].y--;
                break;
            case 2:
                cars[i].x--;
                break;
            case 3:
                cars[i].x++;
                break;
        }

        if (time(NULL) - tStart >= cars[i].speed)
        {
            tStart = time(NULL);
            cars[i].x++;
            cars[i].direction = (cars[i].direction + 1) % 4;
        }
    }

    for (int i = 0; i < numCars; i++)
    {
        printf("Car %d: x = %d, y = %d\n", i + 1, cars[i].x, cars[i].y);
    }
}

int main()
{
    Car cars[MAX_CARS];

    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i].x = 0;
        cars[i].y = 0;
        cars[i].direction = 0;
        cars[i].speed = rand() % 5 + 1;
    }

    simulateTrafficFlow(cars, MAX_CARS);

    return 0;
}