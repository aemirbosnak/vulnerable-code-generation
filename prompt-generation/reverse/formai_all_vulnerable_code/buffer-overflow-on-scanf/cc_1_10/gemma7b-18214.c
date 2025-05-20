//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdlib.h>
#include <stdio.h>

#define MAX_SPEED 10

typedef struct Vehicle
{
    int x, y, facing, speed;
    char name[20];
} Vehicle;

Vehicle car;

void update_position()
{
    switch (car.facing)
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

    if (car.speed > 0)
    {
        switch (car.facing)
        {
            case 0:
                car.x += car.speed;
                break;
            case 1:
                car.y += car.speed;
                break;
            case 2:
                car.x -= car.speed;
                break;
            case 3:
                car.y -= car.speed;
                break;
        }
    }
}

void handle_input()
{
    char input;

    printf("Enter command (w/a/s/d/q): ");
    scanf("%c", &input);

    switch (input)
    {
        case 'w':
            car.speed = MAX_SPEED;
            car.facing = 0;
            break;
        case 'a':
            car.speed = MAX_SPEED;
            car.facing = 1;
            break;
        case 's':
            car.speed = MAX_SPEED;
            car.facing = 2;
            break;
        case 'd':
            car.speed = MAX_SPEED;
            car.facing = 3;
            break;
        case 'q':
            exit(0);
            break;
    }
}

int main()
{
    car.x = 0;
    car.y = 0;
    car.facing = 0;
    car.speed = 0;
    strcpy(car.name, "Rusty");

    while (1)
    {
        handle_input();
        update_position();

        printf("Position: (%d, %d)\n", car.x, car.y);
        printf("Speed: %d\n", car.speed);
        printf("Facing: %d\n", car.facing);
        printf("\n");
    }

    return 0;
}