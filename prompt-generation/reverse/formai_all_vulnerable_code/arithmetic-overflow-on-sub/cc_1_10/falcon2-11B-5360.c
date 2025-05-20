//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int angle;
} point;

typedef struct
{
    point position;
    int speed;
    int direction;
} car;

void display_car(car *car_ptr)
{
    printf("Current Position: (%d, %d)\n", car_ptr->position.x, car_ptr->position.y);
    printf("Current Speed: %d\n", car_ptr->speed);
    printf("Current Direction: %d\n", car_ptr->direction);
}

void move_car(car *car_ptr)
{
    if(car_ptr->direction == 0)
    {
        car_ptr->position.x -= car_ptr->speed;
        car_ptr->position.y += car_ptr->speed;
    }
    else if(car_ptr->direction == 1)
    {
        car_ptr->position.x += car_ptr->speed;
        car_ptr->position.y += car_ptr->speed;
    }
    else if(car_ptr->direction == 2)
    {
        car_ptr->position.x -= car_ptr->speed;
        car_ptr->position.y -= car_ptr->speed;
    }
    else if(car_ptr->direction == 3)
    {
        car_ptr->position.x += car_ptr->speed;
        car_ptr->position.y -= car_ptr->speed;
    }
}

void main()
{
    car car1;
    car1.position.x = 0;
    car1.position.y = 0;
    car1.speed = 0;
    car1.direction = 1;

    while(1)
    {
        display_car(&car1);
        printf("Please enter direction (0-3): ");
        scanf("%d", &car1.direction);
        move_car(&car1);
    }
}