//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants for the simulation
#define BATTERY_LOW_THRESHOLD 5
#define MAX_DISTANCE 100

// Define struct for the remote control vehicle
typedef struct {
    int battery_level; // 0 = empty, 10 = full
    int distance_traveled;
    bool is_on;
} rc_vehicle_t;

// Function to turn on the vehicle
void turn_on_vehicle(rc_vehicle_t* vehicle) {
    vehicle->is_on = true;
    printf("Vehicle turned on.\n");
}

// Function to turn off the vehicle
void turn_off_vehicle(rc_vehicle_t* vehicle) {
    vehicle->is_on = false;
    printf("Vehicle turned off.\n");
}

// Function to move the vehicle forward a given distance
void move_forward(rc_vehicle_t* vehicle, int distance) {
    // Check if vehicle is on
    if (!vehicle->is_on) {
        printf("Vehicle is not turned on.\n");
        return;
    }

    // Check if battery level is low
    if (vehicle->battery_level <= BATTERY_LOW_THRESHOLD) {
        printf("Battery level is too low.\n");
        return;
    }

    // Check if distance is within range
    if (distance > MAX_DISTANCE) {
        printf("Distance is too far.\n");
        return;
    }

    // Update vehicle's distance traveled and battery level
    vehicle->distance_traveled += distance;
    vehicle->battery_level--;

    // Print status update
    printf("Moved vehicle forward %d units. Distance traveled: %d. Battery level: %d/10.\n", distance, vehicle->distance_traveled, vehicle->battery_level);
}

int main() {
    // Initialize vehicle
    rc_vehicle_t vehicle;
    vehicle.battery_level = 10;
    vehicle.distance_traveled = 0;
    vehicle.is_on = false;

    // Print instructions
    printf("Welcome to the remote control vehicle simulation!\n");
    printf("To turn on the vehicle, enter 'on'.\n");
    printf("To turn off the vehicle, enter 'off'.\n");
    printf("To move the vehicle forward, enter 'move [distance]'.\n");
    printf("To exit the program, enter 'exit'.\n");

    // Start loop to receive user commands
    char input[50];
    char* command;
    char* distance_str;
    int distance;
    while(true) {
        printf("Enter command: ");
        fgets(input, 50, stdin);
        input[strlen(input)-1] = '\0'; // Remove trailing newline

        // Parse command
        command = strtok(input, " ");
        distance_str = strtok(NULL, " ");

        // Handle exit command
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Handle other commands
        if (strcmp(command, "on") == 0) {
            turn_on_vehicle(&vehicle);
        } else if (strcmp(command, "off") == 0) {
            turn_off_vehicle(&vehicle);
        } else if (strcmp(command, "move") == 0) {
            if (distance_str == NULL) {
                printf("Please enter a distance.\n");
            } else {
                distance = atoi(distance_str);
                move_forward(&vehicle, distance);
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}