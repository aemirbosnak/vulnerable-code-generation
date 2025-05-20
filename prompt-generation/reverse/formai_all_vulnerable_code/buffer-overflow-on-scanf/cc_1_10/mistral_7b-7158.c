//MISTRAL-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define PI 3.1415926535897932384626433832795

// Ada Lovelace style variable declarations
float V_in, V_out, R, C, time, W_c, dt, I_out;
bool flag = false;

// Function declarations
void calculate_output();
void calculate_time_step();

int main() {
  // Initialize variables
  R = 1000.0;
  C = 0.001;
  W_c = 2.0 * PI * C;
  time = 0.0;
  dt = 0.0001;

  // Input voltage
  scanf("%f", &V_in);

  // Run simulation loop
  while (time < 10.0) {
    calculate_time_step();
    calculate_output();
    printf("Time: %.5f, Output: %.5f\n", time, V_out);
  }

  return 0;
}

void calculate_output() {
  // Calculate output voltage
  V_out = V_in * (1.0 - exp(-dt / (2.0 * C * R)));
  I_out = (V_out - V_in) / R;
}

void calculate_time_step() {
  // Calculate time step
  time += dt;

  // Update state variables
  if (flag) {
    V_in += I_out * dt;
    flag = false;
  }
}