//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_ROTATION 90

typedef struct Vehicle
{
    int x;
    int y;
    int direction;
    int speed;
} Vehicle;

Vehicle vehicle;

void update_vehicle()
{
    int x_change, y_change;

    switch (vehicle.direction)
    {
        case 0:
            x_change = vehicle.speed;
            y_change = 0;
            break;
        case 1:
            x_change = vehicle.speed;
            y_change = vehicle.speed;
            break;
        case 2:
            x_change = vehicle.speed;
            y_change = -vehicle.speed;
            break;
        case 3:
            x_change = -vehicle.speed;
            y_change = -vehicle.speed;
            break;
    }

    vehicle.x += x_change;
    vehicle.y += y_change;
}

void handle_input()
{
    char input;

    scanf(" %c", &input);

    switch (input)
    {
        case 'w':
            vehicle.speed++;
            break;
        case 'a':
            vehicle.direction--;
            break;
        case 's':
            vehicle.speed--;
            break;
        case 'd':
            vehicle.direction++;
            break;
        case 'q':
            exit(0);
            break;
    }
}

int main()
{
    time_t start_time, end_time;
    int time_elapsed;

    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = 0;
    vehicle.speed = 0;

    start_time = time(NULL);

    while (!vehicle.x || !vehicle.y)
    {
        update_vehicle();
        handle_input();

        end_time = time(NULL);
        time_elapsed = end_time - start_time;

        if (time_elapsed > 1)
        {
            start_time = end_time;
            printf("Time elapsed: %d seconds\n", time_elapsed);
        }
    }

    return 0;
}