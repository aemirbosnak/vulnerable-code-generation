//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 45

typedef struct Vehicle
{
    int x, y, facing, speed, turning;
} Vehicle;

Vehicle vehicle;

void moveVehicle(int direction, int power)
{
    switch (direction)
    {
        case 0: // Forward
            vehicle.speed = power;
            vehicle.x++;
            break;
        case 1: // Right
            vehicle.speed = power;
            vehicle.y++;
            break;
        case 2: // Left
            vehicle.speed = power;
            vehicle.y--;
            break;
        case 3: // Back
            vehicle.speed = power;
            vehicle.x--;
            break;
    }

    vehicle.turning = 0;
}

void turnVehicle(int angle)
{
    vehicle.turning = angle;
}

int main()
{
    int i, command, direction, power, angle;

    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.facing = 0;
    vehicle.speed = 0;
    vehicle.turning = 0;

    printf("Press 'S' to start, 'Q' to quit: ");
    scanf("%c", &command);

    while (command != 'Q')
    {
        printf("Enter direction (0-3): ");
        scanf("%d", &direction);

        printf("Enter power (1-10): ");
        scanf("%d", &power);

        moveVehicle(direction, power);

        printf("Enter angle (optional): ");
        scanf("%d", &angle);

        if (angle)
            turnVehicle(angle);

        printf("Vehicle position: (%d, %d), facing: %d\n", vehicle.x, vehicle.y, vehicle.facing);

        printf("Press 'S' to start, 'Q' to quit: ");
        scanf("%c", &command);
    }

    return 0;
}