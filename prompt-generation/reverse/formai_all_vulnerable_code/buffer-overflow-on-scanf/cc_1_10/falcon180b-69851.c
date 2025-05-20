//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 20
#define MAX_TURNS 30

// Define the structure of the remote control vehicle
typedef struct {
    int speed;
    int turns;
} RemoteControlVehicle;

// Function to initialize the remote control vehicle
void init_vehicle(RemoteControlVehicle* vehicle) {
    vehicle->speed = 0;
    vehicle->turns = 0;
}

// Function to move the remote control vehicle
void move_vehicle(RemoteControlVehicle* vehicle, int direction) {
    if (direction == 1) {
        // Move forward
        printf("Vehicle is moving forward...\n");
        vehicle->speed += 1;
    } else if (direction == 2) {
        // Turn left
        printf("Vehicle is turning left...\n");
        vehicle->turns += 1;
    } else if (direction == 3) {
        // Turn right
        printf("Vehicle is turning right...\n");
        vehicle->turns -= 1;
    } else {
        // Invalid direction
        printf("Invalid direction!\n");
    }
}

// Function to check if the remote control vehicle is still within bounds
int is_in_bounds(RemoteControlVehicle* vehicle) {
    if (vehicle->speed >= 0 && vehicle->speed <= MAX_SPEED &&
        vehicle->turns >= -MAX_TURNS && vehicle->turns <= MAX_TURNS) {
        return 1;
    } else {
        return 0;
    }
}

// Function to reset the remote control vehicle
void reset_vehicle(RemoteControlVehicle* vehicle) {
    vehicle->speed = 0;
    vehicle->turns = 0;
}

// Main function to simulate the remote control vehicle
int main() {
    RemoteControlVehicle vehicle;
    init_vehicle(&vehicle);

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Reset\n");
        scanf("%d", &choice);

        if (choice == 1) {
            move_vehicle(&vehicle, 1);
        } else if (choice == 2) {
            move_vehicle(&vehicle, 2);
        } else if (choice == 3) {
            move_vehicle(&vehicle, 3);
        } else if (choice == 4) {
            reset_vehicle(&vehicle);
        } else {
            printf("Invalid choice!\n");
        }

        if (!is_in_bounds(&vehicle)) {
            printf("Vehicle is out of bounds, resetting...\n");
            reset_vehicle(&vehicle);
        }
    }

    return 0;
}