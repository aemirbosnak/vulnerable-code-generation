//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

struct Vehicle
{
    int x, y, direction, speed;
    char name[20];
};

void moveVehicle(struct Vehicle *v)
{
    switch (v->direction)
    {
        case 0:
            v->x++;
            break;
        case 1:
            v->y++;
            break;
        case 2:
            v->x--;
            break;
        case 3:
            v->y--;
            break;
    }

    v->speed++;

    if (v->speed > MAX_SPEED)
    {
        v->speed = MAX_SPEED;
    }
}

int main()
{
    struct Vehicle myCar;
    myCar.x = 0;
    myCar.y = 0;
    myCar.direction = 0;
    myCar.speed = 0;
    strcpy(myCar.name, "Lightning");

    time_t t = time(NULL);

    while (time(NULL) - t < 10)
    {
        moveVehicle(&myCar);
        printf("Vehicle name: %s, x: %d, y: %d, speed: %d\n", myCar.name, myCar.x, myCar.y, myCar.speed);
        sleep(0.1);
    }

    return 0;
}