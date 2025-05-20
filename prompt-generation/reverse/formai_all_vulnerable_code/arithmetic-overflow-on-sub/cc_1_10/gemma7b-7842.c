//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 90

typedef struct Car
{
    int x;
    int y;
    int direction;
    int speed;
} Car;

Car car;

void moveCar(int direction, int speed)
{
    switch (direction)
    {
        case 0:
            car.x++;
            break;
        case 1:
            car.y++;
            break;
        case 2:
            car.x--;
            break;
        case 3:
            car.y--;
            break;
    }

    car.speed = speed;
}

int main()
{
    int i, j;
    time_t t;

    car.x = 0;
    car.y = 0;
    car.direction = 0;
    car.speed = 0;

    t = time(NULL);

    for (i = 0; i < 10; i++)
    {
        moveCar(car.direction, car.speed);

        if (time(NULL) - t >= 1)
        {
            t = time(NULL);
            printf("Car position: (%d, %d)\n", car.x, car.y);
        }
    }

    return 0;
}