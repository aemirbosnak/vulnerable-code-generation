//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100  // Maximum speed of the vehicle (km/h)
#define MIN_SPEED 0    // Minimum speed of the vehicle (km/h)
#define MAX_STEERING_ANGLE 30  // Maximum steering angle of the vehicle (degrees)
#define MIN_STEERING_ANGLE -30 // Minimum steering angle of the vehicle (degrees)

// Structure to represent the remote control vehicle
typedef struct {
    int speed;  // Current speed of the vehicle (km/h)
    int steering_angle;  // Current steering angle of the vehicle (degrees)
} Vehicle;

// Function to initialize the remote control vehicle
void init_vehicle(Vehicle *vehicle) {
    vehicle->speed = 0;
    vehicle->steering_angle = 0;
}

// Function to accelerate the remote control vehicle
void accelerate(Vehicle *vehicle, int amount) {
    vehicle->speed += amount;
    if (vehicle->speed > MAX_SPEED) {
        vehicle->speed = MAX_SPEED;
    }
}

// Function to decelerate the remote control vehicle
void decelerate(Vehicle *vehicle, int amount) {
    vehicle->speed -= amount;
    if (vehicle->speed < MIN_SPEED) {
        vehicle->speed = MIN_SPEED;
    }
}

// Function to turn the remote control vehicle left
void turn_left(Vehicle *vehicle, int amount) {
    vehicle->steering_angle += amount;
    if (vehicle->steering_angle > MAX_STEERING_ANGLE) {
        vehicle->steering_angle = MAX_STEERING_ANGLE;
    }
}

// Function to turn the remote control vehicle right
void turn_right(Vehicle *vehicle, int amount) {
    vehicle->steering_angle -= amount;
    if (vehicle->steering_angle < MIN_STEERING_ANGLE) {
        vehicle->steering_angle = MIN_STEERING_ANGLE;
    }
}

// Function to print the current state of the remote control vehicle
void print_vehicle_state(Vehicle *vehicle) {
    printf("Current speed: %d km/h\n", vehicle->speed);
    printf("Current steering angle: %d degrees\n", vehicle->steering_angle);
}

int main() {
    // Initialize the remote control vehicle
    Vehicle vehicle;
    init_vehicle(&vehicle);

    // Read commands from the user until the user enters "quit"
    char command[10];
    while (strcmp(command, "quit") != 0) {
        printf("Enter command (accelerate, decelerate, turn left, turn right, quit): ");
        scanf("%s", command);

        // Parse the command and update the state of the remote control vehicle
        if (strcmp(command, "accelerate") == 0) {
            int amount;
            printf("Enter amount to accelerate (km/h): ");
            scanf("%d", &amount);
            accelerate(&vehicle, amount);
        } else if (strcmp(command, "decelerate") == 0) {
            int amount;
            printf("Enter amount to decelerate (km/h): ");
            scanf("%d", &amount);
            decelerate(&vehicle, amount);
        } else if (strcmp(command, "turn left") == 0) {
            int amount;
            printf("Enter amount to turn left (degrees): ");
            scanf("%d", &amount);
            turn_left(&vehicle, amount);
        } else if (strcmp(command, "turn right") == 0) {
            int amount;
            printf("Enter amount to turn right (degrees): ");
            scanf("%d", &amount);
            turn_right(&vehicle, amount);
        } else if (strcmp(command, "quit") != 0) {
            printf("Invalid command!\n");
        }

        // Print the current state of the remote control vehicle
        print_vehicle_state(&vehicle);
    }

    return 0;
}