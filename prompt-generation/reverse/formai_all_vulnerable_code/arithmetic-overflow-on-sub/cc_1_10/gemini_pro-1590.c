//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

// Vehicle parameters
#define VEHICLE_LENGTH 1.0
#define VEHICLE_WIDTH 0.5
#define VEHICLE_MASS 1000.0
#define VEHICLE_MAX_STEER_ANGLE 30.0 * (PI / 180.0)
#define VEHICLE_MAX_SPEED 10.0

// Simulation parameters
#define SIMULATION_STEP 0.01
#define SIMULATION_TIME 100.0

// Remote control parameters
#define RC_STEER_SENSITIVITY 0.1
#define RC_THROTTLE_SENSITIVITY 0.2

// Vehicle state
double x = 0.0;
double y = 0.0;
double theta = 0.0;
double v = 0.0;
double steer_angle = 0.0;

// Remote control input
double rc_steer = 0.0;
double rc_throttle = 0.0;

// Initialize the simulation
void init_simulation() {
  // Set the initial vehicle state
  x = 0.0;
  y = 0.0;
  theta = 0.0;
  v = 0.0;
  steer_angle = 0.0;

  // Set the initial remote control input
  rc_steer = 0.0;
  rc_throttle = 0.0;
}

// Update the vehicle state
void update_vehicle_state() {
  // Calculate the acceleration in the x and y directions
  double ax = v * cos(theta);
  double ay = v * sin(theta);

  // Calculate the change in position and orientation
  double dx = ax * SIMULATION_STEP;
  double dy = ay * SIMULATION_STEP;
  double dtheta = (v / VEHICLE_LENGTH) * tan(steer_angle) * SIMULATION_STEP;

  // Update the vehicle state
  x += dx;
  y += dy;
  theta += dtheta;

  // Keep the vehicle within the simulation bounds
  if (x < 0.0) {
    x = 0.0;
  } else if (x > 100.0) {
    x = 100.0;
  }

  if (y < 0.0) {
    y = 0.0;
  } else if (y > 100.0) {
    y = 100.0;
  }

  // Limit the speed of the vehicle
  if (v > VEHICLE_MAX_SPEED) {
    v = VEHICLE_MAX_SPEED;
  } else if (v < 0.0) {
    v = 0.0;
  }

  // Limit the steer angle of the vehicle
  if (steer_angle > VEHICLE_MAX_STEER_ANGLE) {
    steer_angle = VEHICLE_MAX_STEER_ANGLE;
  } else if (steer_angle < -VEHICLE_MAX_STEER_ANGLE) {
    steer_angle = -VEHICLE_MAX_STEER_ANGLE;
  }
}

// Update the remote control input
void update_remote_control_input() {
  // Get the remote control input
  rc_steer += rand() % 2 == 0 ? -RC_STEER_SENSITIVITY : RC_STEER_SENSITIVITY;
  rc_throttle += rand() % 2 == 0 ? -RC_THROTTLE_SENSITIVITY : RC_THROTTLE_SENSITIVITY;

  // Limit the remote control input
  if (rc_steer > 1.0) {
    rc_steer = 1.0;
  } else if (rc_steer < -1.0) {
    rc_steer = -1.0;
  }

  if (rc_throttle > 1.0) {
    rc_throttle = 1.0;
  } else if (rc_throttle < -1.0) {
    rc_throttle = -1.0;
  }
}

// Main simulation loop
int main() {
  // Initialize the simulation
  init_simulation();

  // Start the simulation clock
  clock_t start_time = clock();

  // Run the simulation for the specified amount of time
  while (clock() - start_time < SIMULATION_TIME * CLOCKS_PER_SEC) {
    // Update the remote control input
    update_remote_control_input();

    // Update the vehicle state
    update_vehicle_state();

    // Print the vehicle state
    printf("x: %.2f, y: %.2f, theta: %.2f, v: %.2f, steer_angle: %.2f\n", x, y, theta, v, steer_angle);
  }

  return 0;
}