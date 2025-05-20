//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT 3
#define STOP 0

// Define the structure of the remote control vehicle
typedef struct {
    int speed; // Current speed of the vehicle
    int direction; // Current direction of the vehicle
} Vehicle;

// Function to initialize the vehicle
void initVehicle(Vehicle* vehicle) {
    vehicle->speed = 0;
    vehicle->direction = STOP;
}

// Function to move the vehicle forward
void moveForward(Vehicle* vehicle) {
    printf("Moving forward...\n");
    vehicle->speed = 5; // Set the speed to 5
    vehicle->direction = FORWARD; // Set the direction to forward
}

// Function to move the vehicle backward
void moveBackward(Vehicle* vehicle) {
    printf("Moving backward...\n");
    vehicle->speed = -5; // Set the speed to -5
    vehicle->direction = BACKWARD; // Set the direction to backward
}

// Function to turn the vehicle left
void turnLeft(Vehicle* vehicle) {
    printf("Turning left...\n");
    vehicle->speed = 0; // Set the speed to 0
    vehicle->direction = LEFT; // Set the direction to left
}

// Function to turn the vehicle right
void turnRight(Vehicle* vehicle) {
    printf("Turning right...\n");
    vehicle->speed = 0; // Set the speed to 0
    vehicle->direction = RIGHT; // Set the direction to right
}

// Function to stop the vehicle
void stopVehicle(Vehicle* vehicle) {
    printf("Stopping the vehicle...\n");
    vehicle->speed = 0; // Set the speed to 0
    vehicle->direction = STOP; // Set the direction to stop
}

// Function to control the vehicle based on user input
void controlVehicle(Vehicle* vehicle) {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Stop\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            moveForward(vehicle);
            break;
        case 2:
            moveBackward(vehicle);
            break;
        case 3:
            turnLeft(vehicle);
            break;
        case 4:
            turnRight(vehicle);
            break;
        case 5:
            stopVehicle(vehicle);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

int main() {
    Vehicle vehicle;
    initVehicle(&vehicle);

    while(1) {
        controlVehicle(&vehicle);
    }

    return 0;
}