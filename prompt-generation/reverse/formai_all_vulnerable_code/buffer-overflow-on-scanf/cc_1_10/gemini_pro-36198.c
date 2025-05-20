//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

// Define the drone struct
typedef struct {
    double x;
    double y;
    double z;
    double roll;
    double pitch;
    double yaw;
} drone;

// Define the remote control struct
typedef struct {
    int throttle;
    int roll;
    int pitch;
    int yaw;
} remote_control;

// Create a new drone
drone* create_drone() {
    drone* d = (drone*)malloc(sizeof(drone));
    d->x = 0;
    d->y = 0;
    d->z = 0;
    d->roll = 0;
    d->pitch = 0;
    d->yaw = 0;
    return d;
}

// Create a new remote control
remote_control* create_remote_control() {
    remote_control* rc = (remote_control*)malloc(sizeof(remote_control));
    rc->throttle = 0;
    rc->roll = 0;
    rc->pitch = 0;
    rc->yaw = 0;
    return rc;
}

// Update the drone's position and orientation based on the remote control inputs
void update_drone(drone* d, remote_control* rc) {
    // Update the drone's position
    d->x += rc->throttle * cos(d->yaw) * cos(d->pitch);
    d->y += rc->throttle * sin(d->yaw) * cos(d->pitch);
    d->z += rc->throttle * sin(d->pitch);

    // Update the drone's orientation
    d->roll += rc->roll * PI / 180.0;
    d->pitch += rc->pitch * PI / 180.0;
    d->yaw += rc->yaw * PI / 180.0;
}

// Print the drone's position and orientation
void print_drone(drone* d) {
    printf("Position: (%.2f, %.2f, %.2f)\n", d->x, d->y, d->z);
    printf("Orientation: (%.2f, %.2f, %.2f)\n", d->roll, d->pitch, d->yaw);
}

// Main function
int main() {
    // Create a new drone and remote control
    drone* d = create_drone();
    remote_control* rc = create_remote_control();

    // Get the user input
    printf("Enter the throttle, roll, pitch, and yaw values:\n");
    scanf("%d %d %d %d", &rc->throttle, &rc->roll, &rc->pitch, &rc->yaw);

    // Update the drone's position and orientation
    update_drone(d, rc);

    // Print the drone's position and orientation
    print_drone(d);

    // Free the drone and remote control
    free(d);
    free(rc);

    return 0;
}