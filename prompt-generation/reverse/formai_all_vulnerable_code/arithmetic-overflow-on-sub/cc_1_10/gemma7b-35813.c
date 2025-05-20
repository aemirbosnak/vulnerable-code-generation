//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_ROTATION 90

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

void turnCar(int direction)
{
    car.direction = direction;
}

int main()
{
    car.x = 0;
    car.y = 0;
    car.direction = 0;
    car.speed = 0;

    while (1)
    {
        printf("Enter direction (0-3): ");
        int dir = getchar() - '0';

        printf("Enter speed (0-10): ");
        int speed = atoi(fgets(NULL, 10, stdin));

        moveCar(dir, speed);

        printf("Car position: (%d, %d)\n", car.x, car.y);
        printf("Car direction: %d\n", car.direction);
        printf("Car speed: %d\n", car.speed);

        sleep(1);
    }

    return 0;
}