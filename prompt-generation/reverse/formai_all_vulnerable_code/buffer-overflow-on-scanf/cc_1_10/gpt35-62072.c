//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 10
#define MIN_SPEED 1

// User-defined structure to represent remote control vehicle
typedef struct {
    int speed;
    bool isMoving;
} RCVehicle;

// Function to accelerate RC vehicle
void accelerate(RCVehicle *vehicle) {
    if (vehicle->speed < MAX_SPEED) {
        vehicle->speed++;
    }
    vehicle->isMoving = true;
}

// Function to decelerate RC vehicle
void decelerate(RCVehicle *vehicle) {
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed--;
    }
    if (vehicle->speed == 0) {
        vehicle->isMoving = false;
    }
}

int main() {
    // Initialize RC vehicle
    RCVehicle myRCVehicle = {0, false};

    // Simulate user input
    char userChoice;
    do {
        printf("Enter 'a' to accelerate, 'd' to decelerate, or 'q' to quit: ");
        scanf(" %c", &userChoice);

        switch(userChoice) {
            case 'a':
                accelerate(&myRCVehicle);
                printf("Accelerated to speed %d\n", myRCVehicle.speed);
                break;
            case 'd':
                decelerate(&myRCVehicle);
                printf("Decelerated to speed %d\n", myRCVehicle.speed);
                break;
            case 'q':
                printf("Quitting program\n");
                break;
            default:
                printf("Invalid input, please try again\n");
                break;
        }

        // Print current state of RC vehicle
        if (myRCVehicle.isMoving) {
            printf("RC vehicle is currently moving at speed %d\n", myRCVehicle.speed);
        } else {
            printf("RC vehicle is currently not moving\n");
        }

    } while (userChoice != 'q');

    return 0;
}