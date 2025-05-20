#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int sim_count = 0;
  scanf("Enter simulation count: ", &sim_count);

  for (int i = 0; i < sim_count; i++) {
    int dt = 0;
    scanf("Enter time step (dt): ", &dt);

    int mass = 10;
    int gravity = 9.8;
    int force = 20;

    int position = 0;
    int velocity = 0;

    // Calculate acceleration due to force
    int acceleration = force / mass;

    // Update position and velocity
    position += velocity * dt * acceleration;
    velocity += acceleration * dt;

    // Introduce integer overflow vulnerability
    position = position * 2;

    printf("Position: %d\n", position);
  }

  return 0;
}
