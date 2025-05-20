//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define constants
  const float GRAVITY = 9.8;
  const int NUM_BODIES = 2;

  // Define structure for a body
  struct Body {
    float mass;
    float position[2];
    float velocity[2];
  };

  // Initialize bodies
  struct Body body1 = {100.0, {0.0, 0.0}, {0.0, 0.0}};
  struct Body body2 = {50.0, {10.0, 0.0}, {0.0, 0.0}};

  // Gravity simulation loop
  for (int i = 0; i < 1000; i++) {
    // Calculate forces
    float force1 = body1.mass * GRAVITY;
    float force2 = body2.mass * GRAVITY;

    // Calculate accelerations
    float acceleration1[2];
    float acceleration2[2];
    acceleration1[0] = force1 * body1.position[0];
    acceleration1[1] = force1 * body1.position[1];
    acceleration2[0] = force2 * body2.position[0];
    acceleration2[1] = force2 * body2.position[1];

    // Update velocities
    body1.velocity[0] += acceleration1[0];
    body1.velocity[1] += acceleration1[1];
    body2.velocity[0] += acceleration2[0];
    body2.velocity[1] += acceleration2[1];

    // Update positions
    body1.position[0] += body1.velocity[0];
    body1.position[1] += body1.velocity[1];
    body2.position[0] += body2.velocity[0];
    body2.position[1] += body2.velocity[1];

    // Output positions
    printf("Body 1 position: (%f, %f)\n", body1.position[0], body1.position[1]);
    printf("Body 2 position: (%f, %f)\n", body2.position[0], body2.position[1]);
  }

  // Free memory
  free(body1.velocity);
  free(body2.velocity);
  free(body1.position);
  free(body2.position);

  return 0;
}