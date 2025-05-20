//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the drone's state
typedef struct {
    double x;
    double y;
    double z;
    double roll;
    double pitch;
    double yaw;
} drone_state;

// Define the remote control's state
typedef struct {
    double throttle;
    double roll;
    double pitch;
    double yaw;
} remote_control_state;

// Define the function to update the drone's state
void update_drone_state(drone_state *drone, remote_control_state *remote) {
    // Update the drone's position
    drone->x += remote->throttle * cos(drone->roll) * cos(drone->pitch);
    drone->y += remote->throttle * sin(drone->roll) * cos(drone->pitch);
    drone->z += remote->throttle * sin(drone->pitch);

    // Update the drone's orientation
    drone->roll += remote->roll;
    drone->pitch += remote->pitch;
    drone->yaw += remote->yaw;
}

// Define the function to print the drone's state
void print_drone_state(drone_state *drone) {
    printf("Position: (%f, %f, %f)\n", drone->x, drone->y, drone->z);
    printf("Orientation: (%f, %f, %f)\n", drone->roll, drone->pitch, drone->yaw);
}

// Main function
int main() {
    // Initialize the drone's state
    drone_state drone = {0, 0, 0, 0, 0, 0};

    // Initialize the remote control's state
    remote_control_state remote = {0, 0, 0, 0};

    // Seed the random number generator
    srand(time(NULL));

    // Main loop
    while (1) {
        // Get the remote control's state
        scanf("%lf %lf %lf %lf", &remote.throttle, &remote.roll, &remote.pitch, &remote.yaw);

        // Update the drone's state
        update_drone_state(&drone, &remote);

        // Print the drone's state
        print_drone_state(&drone);
    }

    return 0;
}