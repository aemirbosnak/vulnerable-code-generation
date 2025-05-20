//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_STEERING_ANGLE 30
#define MIN_STEERING_ANGLE -30

typedef struct {
  float x;
  float y;
  float theta;
} VehicleState;

typedef struct {
  int throttle;
  int steering_angle;
} RemoteControlInput;

void update_vehicle_state(VehicleState *vehicle, RemoteControlInput *input, float dt) {
  float v = input->throttle * MAX_SPEED / 100.0;
  float omega = input->steering_angle * MAX_STEERING_ANGLE / 180.0 * M_PI;

  vehicle->x += v * dt * cos(vehicle->theta);
  vehicle->y += v * dt * sin(vehicle->theta);
  vehicle->theta += omega * dt;
}

void print_vehicle_state(VehicleState *vehicle) {
  printf("Vehicle state:\n");
  printf("  x: %.2f\n", vehicle->x);
  printf("  y: %.2f\n", vehicle->y);
  printf("  theta: %.2f\n", vehicle->theta);
}

int main() {
  // Initialize vehicle state
  VehicleState vehicle = {0, 0, 0};

  // Main simulation loop
  while (1) {
    // Get remote control input
    RemoteControlInput input;
    scanf("%d %d", &input.throttle, &input.steering_angle);

    // Update vehicle state
    update_vehicle_state(&vehicle, &input, 0.01);

    // Print vehicle state
    print_vehicle_state(&vehicle);
  }

  return 0;
}