//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the speed and direction of the vehicle
#define SPEED 5
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

// Define the structure of the vehicle
typedef struct {
    int x; // x-coordinate
    int y; // y-coordinate
    int direction; // direction of the vehicle (1 for forward, -1 for backward)
} Vehicle;

// Function prototypes
void move(Vehicle *vehicle);
void turn(Vehicle *vehicle, int direction);
void remote_control(Vehicle *vehicle);

int main() {
    Vehicle vehicle;
    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = FORWARD;

    remote_control(&vehicle);

    return 0;
}

// Move the vehicle forward or backward based on its current direction
void move(Vehicle *vehicle) {
    if (vehicle->direction == FORWARD) {
        vehicle->x += SPEED;
    } else if (vehicle->direction == BACKWARD) {
        vehicle->x -= SPEED;
    }
}

// Turn the vehicle left or right based on the given direction
void turn(Vehicle *vehicle, int direction) {
    if (direction == LEFT) {
        vehicle->y -= SPEED;
    } else if (direction == RIGHT) {
        vehicle->y += SPEED;
    }
}

// Simulate remote control of the vehicle
void remote_control(Vehicle *vehicle) {
    char command;
    while (1) {
        printf("Enter a command (f for forward, b for backward, l for left, r for right, q to quit): ");
        scanf("%c", &command);

        if (command == 'q') {
            break;
        } else if (command == 'f') {
            move(vehicle);
        } else if (command == 'b') {
            turn(vehicle, BACKWARD);
        } else if (command == 'l') {
            turn(vehicle, LEFT);
        } else if (command == 'r') {
            turn(vehicle, RIGHT);
        }
    }
}