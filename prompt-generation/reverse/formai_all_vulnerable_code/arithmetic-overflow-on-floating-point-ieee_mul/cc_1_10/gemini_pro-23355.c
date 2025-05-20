//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: irregular
// Let the drones fly, let the sky be filled with their wings!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define the drone structure
typedef struct drone {
  double x;  // X-coordinate of the drone
  double y;  // Y-coordinate of the drone
  double z;  // Z-coordinate of the drone
  double vx; // X-velocity of the drone
  double vy; // Y-velocity of the drone
  double vz; // Z-velocity of the drone
  double ax; // X-acceleration of the drone
  double ay; // Y-acceleration of the drone
  double az; // Z-acceleration of the drone
} drone;

// Define the remote control structure
typedef struct remote_control {
  double pitch;  // Pitch angle of the remote control
  double roll;   // Roll angle of the remote control
  double yaw;    // Yaw angle of the remote control
  double throttle; // Throttle of the remote control
} remote_control;

// Function to initialize the drone
void drone_init(drone *d) {
  d->x = 0.0;
  d->y = 0.0;
  d->z = 0.0;
  d->vx = 0.0;
  d->vy = 0.0;
  d->vz = 0.0;
  d->ax = 0.0;
  d->ay = 0.0;
  d->az = 0.0;
}

// Function to initialize the remote control
void remote_control_init(remote_control *rc) {
  rc->pitch = 0.0;
  rc->roll = 0.0;
  rc->yaw = 0.0;
  rc->throttle = 0.0;
}

// Function to update the drone's position and velocity based on the remote control inputs
void drone_update(drone *d, remote_control *rc) {
  // Calculate the accelerations
  d->ax = rc->roll * 9.81;
  d->ay = rc->pitch * 9.81;
  d->az = rc->throttle * 9.81;

  // Calculate the velocities
  d->vx += d->ax * 0.01;
  d->vy += d->ay * 0.01;
  d->vz += d->az * 0.01;

  // Calculate the positions
  d->x += d->vx * 0.01;
  d->y += d->vy * 0.01;
  d->z += d->vz * 0.01;
}

// Function to print the drone's position and velocity
void drone_print(drone *d) {
  printf("Position: (%f, %f, %f)\n", d->x, d->y, d->z);
  printf("Velocity: (%f, %f, %f)\n", d->vx, d->vy, d->vz);
}

// Main function
int main() {
  // Initialize the drone and remote control
  drone d;
  remote_control rc;
  drone_init(&d);
  remote_control_init(&rc);

  // Main loop
  while (true) {
    // Read the remote control inputs
    scanf("%lf %lf %lf %lf", &rc.pitch, &rc.roll, &rc.yaw, &rc.throttle);

    // Update the drone's position and velocity
    drone_update(&d, &rc);

    // Print the drone's position and velocity
    drone_print(&d);
  }

  return 0;
}