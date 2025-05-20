//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Vehicle struct
typedef struct {
    int x;
    int y;
    int speed;
    int direction; // 0: up, 1: right, 2: down, 3: left
} Vehicle;

// Remote control struct
typedef struct {
    int throttle;
    int steering;
} RemoteControl;

// Initialize the vehicle
void init_vehicle(Vehicle *vehicle) {
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->speed = 0;
    vehicle->direction = 0;
}

// Initialize the remote control
void init_remote_control(RemoteControl *remote_control) {
    remote_control->throttle = 0;
    remote_control->steering = 0;
}

// Update the vehicle's position and speed
void update_vehicle(Vehicle *vehicle, RemoteControl *remote_control) {
    // Update the vehicle's speed
    vehicle->speed += remote_control->throttle;
    if (vehicle->speed < 0) {
        vehicle->speed = 0;
    } else if (vehicle->speed > 10) {
        vehicle->speed = 10;
    }

    // Update the vehicle's direction
    if (remote_control->steering < 0) {
        vehicle->direction = (vehicle->direction + 1) % 4;
    } else if (remote_control->steering > 0) {
        vehicle->direction = (vehicle->direction - 1 + 4) % 4;
    }

    // Update the vehicle's position
    switch (vehicle->direction) {
        case 0:
            vehicle->y += vehicle->speed;
            break;
        case 1:
            vehicle->x += vehicle->speed;
            break;
        case 2:
            vehicle->y -= vehicle->speed;
            break;
        case 3:
            vehicle->x -= vehicle->speed;
            break;
    }
}

// Display the vehicle's position and speed
void display_vehicle(Vehicle *vehicle) {
    printf("Vehicle position: (%d, %d)\n", vehicle->x, vehicle->y);
    printf("Vehicle speed: %d\n", vehicle->speed);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the vehicle and remote control
    Vehicle vehicle;
    init_vehicle(&vehicle);
    RemoteControl remote_control;
    init_remote_control(&remote_control);

    // Main loop
    while (1) {
        // Get the user input
        printf("Enter throttle (-10 to 10): ");
        scanf("%d", &remote_control.throttle);
        printf("Enter steering (-1 to 1): ");
        scanf("%d", &remote_control.steering);

        // Update the vehicle's position and speed
        update_vehicle(&vehicle, &remote_control);

        // Display the vehicle's position and speed
        display_vehicle(&vehicle);
    }

    return 0;
}