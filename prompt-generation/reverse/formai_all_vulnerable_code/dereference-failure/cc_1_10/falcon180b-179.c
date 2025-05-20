//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for the vehicle's position and speed
typedef struct {
    int x;
    int y;
    int speedX;
    int speedY;
} Vehicle;

// Function prototypes
void initVehicle(Vehicle* vehicle);
void moveVehicle(Vehicle* vehicle);
void turnVehicle(Vehicle* vehicle, int direction);
void printVehicle(Vehicle* vehicle);

int main() {
    srand(time(NULL));

    // Initialize the vehicle
    Vehicle* myVehicle = malloc(sizeof(Vehicle));
    initVehicle(myVehicle);

    // Main loop
    while (1) {
        // Move the vehicle
        moveVehicle(myVehicle);

        // Turn the vehicle randomly
        int direction = rand() % 4; // 0: left, 1: right, 2: up, 3: down
        turnVehicle(myVehicle, direction);

        // Print the vehicle's current position
        printf("My vehicle is at (%d, %d)\n", myVehicle->x, myVehicle->y);

        // Wait for 100 milliseconds
        usleep(100000);
    }

    return 0;
}

// Initialize the vehicle's position and speed
void initVehicle(Vehicle* vehicle) {
    vehicle->x = rand() % 100; // Random x-coordinate between 0 and 99
    vehicle->y = rand() % 100; // Random y-coordinate between 0 and 99
    vehicle->speedX = rand() % 5 - 2; // Random speed between -2 and 2
    vehicle->speedY = rand() % 5 - 2; // Random speed between -2 and 2
}

// Move the vehicle based on its current speed
void moveVehicle(Vehicle* vehicle) {
    vehicle->x += vehicle->speedX;
    vehicle->y += vehicle->speedY;

    // If the vehicle hits a wall, reverse its direction
    if (vehicle->x < 0 || vehicle->x > 99 || vehicle->y < 0 || vehicle->y > 99) {
        vehicle->speedX = -vehicle->speedX;
        vehicle->speedY = -vehicle->speedY;
    }
}

// Turn the vehicle randomly
void turnVehicle(Vehicle* vehicle, int direction) {
    switch (direction) {
        case 0: // Left
            vehicle->speedX = -vehicle->speedX;
            vehicle->speedY = -vehicle->speedY;
            break;
        case 1: // Right
            vehicle->speedX = -vehicle->speedX;
            vehicle->speedY = vehicle->speedY;
            break;
        case 2: // Up
            vehicle->speedX = vehicle->speedX;
            vehicle->speedY = -vehicle->speedY;
            break;
        case 3: // Down
            vehicle->speedX = vehicle->speedX;
            vehicle->speedY = vehicle->speedY;
            break;
    }
}

// Print the vehicle's current position
void printVehicle(Vehicle* vehicle) {
    printf("Vehicle is at (%d, %d)\n", vehicle->x, vehicle->y);
}