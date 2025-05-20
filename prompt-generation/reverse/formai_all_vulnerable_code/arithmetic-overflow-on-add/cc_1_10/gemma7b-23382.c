//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car
{
    int lane;
    int position;
    int speed;
    int direction;
} Car;

Car createCar()
{
    Car car;
    car.lane = rand() % NUM_LANE;
    car.position = rand() % 100;
    car.speed = rand() % 5 + 1;
    car.direction = rand() % 2;
    return car;
}

void moveCar(Car *car)
{
    switch (car->direction)
    {
        case 0:
            car->position++;
            break;
        case 1:
            car->position--;
            break;
    }

    if (car->position >= 100)
    {
        car->direction = 1;
    }

    if (car->position <= 0)
    {
        car->direction = 0;
    }
}

void simulateTrafficFlow(int numCars)
{
    Car cars[numCars];
    for (int i = 0; i < numCars; i++)
    {
        cars[i] = createCar();
    }

    time_t start = time(NULL);
    time_t end = start + 10;

    while (time(NULL) < end)
    {
        for (int i = 0; i < numCars; i++)
        {
            moveCar(&cars[i]);
        }

        sleep(1);
    }

    for (int i = 0; i < numCars; i++)
    {
        printf("Car %d: lane %d, position %d, speed %d, direction %d\n", i + 1, cars[i].lane, cars[i].position, cars[i].speed, cars[i].direction);
    }
}

int main()
{
    simulateTrafficFlow(5);

    return 0;
}