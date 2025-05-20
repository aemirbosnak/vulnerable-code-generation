//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// define the struct for our remote control vehicle
typedef struct RemoteControlVehicle {
    int speed;
    int direction;
    int batteryLevel;
} RCVehicle;

int main() {
    // initialize a new remote control vehicle
    RCVehicle vehicle;
    vehicle.speed = 0;
    vehicle.direction = 0;
    vehicle.batteryLevel = 100;

    printf("Welcome to the RC Vehicle Simulation!\n");

    while (vehicle.batteryLevel >= 0) {
        printf("Current Speed: %d\n", vehicle.speed);
        printf("Current Direction: %d\n", vehicle.direction);
        printf("Battery Level: %d\n\n", vehicle.batteryLevel);

        // prompt the user to enter a new speed and direction
        int speed;
        int direction;

        printf("Enter a new speed (0-100): ");
        scanf("%d", &speed);

        printf("Enter a new direction (0-360): ");
        scanf("%d", &direction);

        // validate the user input
        if (speed < 0 || speed > 100) {
            printf("Invalid speed, please enter a value between 0 and 100.\n");
            continue;
        }

        if (direction < 0 || direction > 360) {
            printf("Invalid direction, please enter a value between 0 and 360.\n");
            continue;
        }

        // update the vehicle's speed and direction
        vehicle.speed = speed;
        vehicle.direction = direction;

        // reduce the battery level by 10 for each simulation iteration
        vehicle.batteryLevel -= 10;
    }

    printf("Battery level is too low, shutting down simulation.\n");

    return 0;
}