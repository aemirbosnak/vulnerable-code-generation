//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the RC vehicle's initial position
#define INIT_POS_X 0
#define INIT_POS_Y 0
#define INIT_POS_Z 0

// Define the RC vehicle's initial orientation
#define INIT_ORIENT_X 0
#define INIT_ORIENT_Y 0
#define INIT_ORIENT_Z 0

// Define the RC vehicle's maximum speed
#define MAX_SPEED 10

// Define the RC vehicle's maximum acceleration
#define MAX_ACCEL 2

// Define the RC vehicle's maximum turning rate
#define MAX_TURN_RATE 1

// Define the simulation time step
#define DT 0.1

// Define the simulation duration
#define SIM_DURATION 10

// Declare the RC vehicle's position and orientation
double pos_x = INIT_POS_X;
double pos_y = INIT_POS_Y;
double pos_z = INIT_POS_Z;
double orient_x = INIT_ORIENT_X;
double orient_y = INIT_ORIENT_Y;
double orient_z = INIT_ORIENT_Z;

// Declare the RC vehicle's velocity
double vel_x = 0;
double vel_y = 0;
double vel_z = 0;

// Declare the RC vehicle's acceleration
double accel_x = 0;
double accel_y = 0;
double accel_z = 0;

// Declare the RC vehicle's turning rate
double turn_rate = 0;

// Main simulation loop
int main()
{
  // Initialize the simulation
  pos_x = INIT_POS_X;
  pos_y = INIT_POS_Y;
  pos_z = INIT_POS_Z;
  orient_x = INIT_ORIENT_X;
  orient_y = INIT_ORIENT_Y;
  orient_z = INIT_ORIENT_Z;
  vel_x = 0;
  vel_y = 0;
  vel_z = 0;
  accel_x = 0;
  accel_y = 0;
  accel_z = 0;
  turn_rate = 0;

  // Read the user input
  double input_accel_x;
  double input_accel_y;
  double input_accel_z;
  double input_turn_rate;
  scanf("%lf %lf %lf %lf", &input_accel_x, &input_accel_y, &input_accel_z, &input_turn_rate);

  // Update the RC vehicle's acceleration and turning rate
  accel_x = input_accel_x;
  accel_y = input_accel_y;
  accel_z = input_accel_z;
  turn_rate = input_turn_rate;

  // Update the RC vehicle's velocity
  vel_x += accel_x * DT;
  vel_y += accel_y * DT;
  vel_z += accel_z * DT;

  // Update the RC vehicle's position
  pos_x += vel_x * DT;
  pos_y += vel_y * DT;
  pos_z += vel_z * DT;

  // Update the RC vehicle's orientation
  orient_x += turn_rate * DT;
  orient_y += turn_rate * DT;
  orient_z += turn_rate * DT;

  // Print the RC vehicle's state
  printf("Position: (%lf, %lf, %lf)\n", pos_x, pos_y, pos_z);
  printf("Orientation: (%lf, %lf, %lf)\n", orient_x, orient_y, orient_z);
  printf("Velocity: (%lf, %lf, %lf)\n", vel_x, vel_y, vel_z);

  return 0;
}