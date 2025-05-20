//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define remote control vehicle struct
typedef struct {
    int speed;
    int direction;
} rc_vehicle_t;

// Define remote control struct
typedef struct {
    int throttle;
    int steering;
} rc_t;

// Function to simulate vehicle movement
void simulate_vehicle(rc_vehicle_t* vehicle, rc_t* remote) {
    if (remote->throttle > 0) {
        vehicle->speed += remote->throttle;
    } else if (remote->throttle < 0) {
        vehicle->speed -= remote->throttle;
    } else {
        vehicle->speed = 0;
    }

    if (remote->steering > 0) {
        vehicle->direction += remote->steering;
    } else if (remote->steering < 0) {
        vehicle->direction -= remote->steering;
    }
}

// Function to print vehicle status
void print_vehicle_status(rc_vehicle_t* vehicle) {
    printf("Vehicle Speed: %d\n", vehicle->speed);
    printf("Vehicle Direction: %d\n", vehicle->direction);
}

// Function to get user input for remote control
void get_remote_control_input(rc_t* remote) {
    printf("Enter throttle (0-100): ");
    scanf("%d", &remote->throttle);

    printf("Enter steering (-100 to 100): ");
    scanf("%d", &remote->steering);
}

int main() {
    rc_vehicle_t vehicle;
    rc_t remote;

    // Initialize vehicle and remote control
    vehicle.speed = 0;
    vehicle.direction = 0;
    remote.throttle = 0;
    remote.steering = 0;

    // Main loop
    while (1) {
        // Get user input for remote control
        get_remote_control_input(&remote);

        // Simulate vehicle movement
        simulate_vehicle(&vehicle, &remote);

        // Print vehicle status
        print_vehicle_status(&vehicle);
    }

    return 0;
}