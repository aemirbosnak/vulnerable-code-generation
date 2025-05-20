//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANE 3
#define MAX_CARS 10

typedef struct Car
{
    int lane;
    int position;
    int speed;
    int direction;
} Car;

void simulateTrafficFlow(Car cars[], int numCars)
{
    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < numCars; i++)
    {
        cars[i].speed = rand() % 30 + 10;
        cars[i].direction = rand() % 2;
    }

    while (1)
    {
        for (int i = 0; i < numCars; i++)
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

            if (cars[i].position >= MAX_LANE - 1)
            {
                cars[i].direction = 1;
            }
            else if (cars[i].position <= 0)
            {
                cars[i].direction = 0;
            }
        }

        sleep(1);
    }
}

int main()
{
    Car cars[MAX_CARS];
    int numCars = 5;

    simulateTrafficFlow(cars, numCars);

    return 0;
}