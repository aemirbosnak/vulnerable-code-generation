//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Vehicle states
#define STOPPED 0
#define MOVING 1

// Remote control commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

// Vehicle struct
struct Vehicle {
    int state; // STOPPED or MOVING
    double x; // X-coordinate
    double y; // Y-coordinate
    double angle; // Angle in radians
    double speed; // Speed in m/s
};

// Remote control struct
struct RemoteControl {
    int command; // FORWARD, BACKWARD, LEFT, RIGHT, or STOP
};

// Function to move the vehicle forward
void moveForward(struct Vehicle *vehicle) {
    vehicle->x += vehicle->speed * cos(vehicle->angle);
    vehicle->y += vehicle->speed * sin(vehicle->angle);
}

// Function to move the vehicle backward
void moveBackward(struct Vehicle *vehicle) {
    vehicle->x -= vehicle->speed * cos(vehicle->angle);
    vehicle->y -= vehicle->speed * sin(vehicle->angle);
}

// Function to turn the vehicle left
void turnLeft(struct Vehicle *vehicle) {
    vehicle->angle -= M_PI / 6;
}

// Function to turn the vehicle right
void turnRight(struct Vehicle *vehicle) {
    vehicle->angle += M_PI / 6;
}

// Function to stop the vehicle
void stop(struct Vehicle *vehicle) {
    vehicle->state = STOPPED;
}

// Function to simulate the vehicle
void simulate(struct Vehicle *vehicle, struct RemoteControl *remote) {
    switch (remote->command) {
        case FORWARD:
            moveForward(vehicle);
            break;
        case BACKWARD:
            moveBackward(vehicle);
            break;
        case LEFT:
            turnLeft(vehicle);
            break;
        case RIGHT:
            turnRight(vehicle);
            break;
        case STOP:
            stop(vehicle);
            break;
    }
}

// Function to print the vehicle's state
void printState(struct Vehicle *vehicle) {
    printf("State: %s\n", vehicle->state == STOPPED ? "STOPPED" : "MOVING");
    printf("X: %.2f\n", vehicle->x);
    printf("Y: %.2f\n", vehicle->y);
    printf("Angle: %.2f\n", vehicle->angle);
    printf("Speed: %.2f\n", vehicle->speed);
}

int main() {
    // Create a vehicle
    struct Vehicle vehicle;
    vehicle.state = STOPPED;
    vehicle.x = 0.0;
    vehicle.y = 0.0;
    vehicle.angle = 0.0;
    vehicle.speed = 1.0;

    // Create a remote control
    struct RemoteControl remote;
    remote.command = STOP;

    // Simulate the vehicle
    while (1) {
        // Get a command from the user
        printf("Enter a command (FORWARD, BACKWARD, LEFT, RIGHT, or STOP): ");
        scanf("%d", &remote.command);

        // Simulate the vehicle
        simulate(&vehicle, &remote);

        // Print the vehicle's state
        printState(&vehicle);
    }

    return 0;
}