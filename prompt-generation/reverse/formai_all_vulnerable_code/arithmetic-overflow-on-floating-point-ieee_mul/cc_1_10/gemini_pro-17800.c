//GEMINI-pro DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * The following program simulates the motion of a projectile in two dimensions.
 * The user is prompted to enter the initial velocity of the projectile, the angle
 * at which it is launched, and the time interval between successive positions.
 * The program then calculates the position of the projectile at each time interval
 * and prints the results to the screen.
 */

int main() {
  // Define the initial velocity of the projectile.
  double v0x, v0y;
  printf("Enter the initial velocity of the projectile (m/s): ");
  scanf("%lf %lf", &v0x, &v0y);

  // Define the angle at which the projectile is launched.
  double theta;
  printf("Enter the angle at which the projectile is launched (degrees): ");
  scanf("%lf", &theta);

  // Convert the angle from degrees to radians.
  theta = theta * M_PI / 180.0;

  // Define the time interval between successive positions.
  double dt;
  printf("Enter the time interval between successive positions (s): ");
  scanf("%lf", &dt);

  // Define the initial position of the projectile.
  double x0 = 0.0;
  double y0 = 0.0;

  // Define the acceleration due to gravity.
  double g = 9.81;

  // Calculate the position of the projectile at each time interval.
  for (double t = 0.0; t <= 10.0; t += dt) {
    // Calculate the horizontal position of the projectile.
    double x = x0 + v0x * t;

    // Calculate the vertical position of the projectile.
    double y = y0 + v0y * t - 0.5 * g * t * t;

    // Print the position of the projectile to the screen.
    printf("At time %f seconds, the projectile is at position (%f, %f) meters.\n", t, x, y);
  }

  return 0;
}