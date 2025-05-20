#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  int n_sims;
  scanf("Enter the number of simulations: ", &n_sims);

  for (int i = 0; i < n_sims; i++) {
    double time_max = 10.0;
    double g = 9.80665;
    double mass = 1.0;
    double initial_position = 1.0;
    double initial_velocity = 0.0;

    double time = 0.0;
    double position = initial_position;
    double velocity = initial_velocity;

    while (position > 0.0 && time < time_max) {
      double acceleration = g;
      double dt = 0.1;
      position += velocity * dt + 0.5 * acceleration * dt * dt;
      velocity += acceleration * dt;
      time += dt;
    }

    printf("The drone's position at time %.2lf is %.2lf meters.\n", time, position);
  }

  return 0;
}
