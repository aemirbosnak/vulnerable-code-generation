//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 90

typedef struct Vehicle
{
    int x;
    int y;
    int direction;
    int speed;
} Vehicle;

Vehicle vehicle;

void moveVehicle(int direction, int speed)
{
    switch (direction)
    {
        case 0:
            vehicle.x++;
            break;
        case 1:
            vehicle.y++;
            break;
        case 2:
            vehicle.x--;
            break;
        case 3:
            vehicle.y--;
            break;
    }

    vehicle.speed = speed;
}

int main()
{
    int command;
    int speed;
    int turn;

    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = 0;
    vehicle.speed = 0;

    while (1)
    {
        printf("Enter command (0-3, 4-8, 9): ");
        scanf("%d", &command);

        switch (command)
        {
            case 0:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(0, speed);
                break;
            case 1:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(1, speed);
                break;
            case 2:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(2, speed);
                break;
            case 3:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(3, speed);
                break;
            case 4:
                printf("Enter turn (1-90): ");
                scanf("%d", &turn);
                vehicle.direction = turn;
                break;
            case 5:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(vehicle.direction, speed);
                break;
            case 6:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(vehicle.direction, speed);
                break;
            case 7:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(vehicle.direction, speed);
                break;
            case 8:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveVehicle(vehicle.direction, speed);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
        }

        printf("Position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Direction: %d\n", vehicle.direction);
        printf("Speed: %d\n", vehicle.speed);
    }

    return 0;
}