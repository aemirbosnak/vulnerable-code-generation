//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define TIME_STEP 0.1 // simulation time step

// define planet struct to hold planet information
typedef struct {
  double mass; // planet mass in kg
  double x_pos; // planet x position in m
  double y_pos; // planet y position in m
  double x_vel; // planet x velocity in m/s
  double y_vel; // planet y velocity in m/s
} Planet;

// define function to calculate gravitational force between two planets
double gravitationalForce(double m1, double m2, double r) {
  return G * m1 * m2 / pow(r, 2);
}

int main() {
  // create two planets
  Planet planet1 = {1000, 0, 0, 0, 10};
  Planet planet2 = {500, 100, 0, 0, -20};

  // simulate gravity between planets for 100 time steps
  for(int i = 0; i < 100; i++) {
    // calculate distance between planets
    double dx = planet2.x_pos - planet1.x_pos;
    double dy = planet2.y_pos - planet1.y_pos;
    double r = sqrt(pow(dx, 2) + pow(dy, 2));

    // calculate gravitational force between planets
    double f = gravitationalForce(planet1.mass, planet2.mass, r);

    // calculate x and y components of force
    double fx = f * dx / r;
    double fy = f * dy / r;

    // calculate new velocities for both planets
    planet1.x_vel += fx / planet1.mass * TIME_STEP;
    planet1.y_vel += fy / planet1.mass * TIME_STEP;
    planet2.x_vel -= fx / planet2.mass * TIME_STEP;
    planet2.y_vel -= fy / planet2.mass * TIME_STEP;

    // calculate new positions for both planets
    planet1.x_pos += planet1.x_vel * TIME_STEP;
    planet1.y_pos += planet1.y_vel * TIME_STEP;
    planet2.x_pos += planet2.x_vel * TIME_STEP;
    planet2.y_pos += planet2.y_vel * TIME_STEP;

    // print out the positions of both planets
    printf("Planet 1: (%f, %f)\n", planet1.x_pos, planet1.y_pos);
    printf("Planet 2: (%f, %f)\n", planet2.x_pos, planet2.y_pos);
  }

  return 0;
}