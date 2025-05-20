//FormAI DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81

int main() {
  // User input for projectile motion
  double initialHeight, launchAngle, initialVelocity, timeStep;
  printf("Enter initial height (in meters): ");
  scanf("%lf", &initialHeight);
  printf("Enter launch angle (in degrees): ");
  scanf("%lf", &launchAngle);
  printf("Enter initial velocity (in m/s): ");
  scanf("%lf", &initialVelocity);
  printf("Enter time step (in seconds): ");
  scanf("%lf", &timeStep);

  // Convert launch angle to radians
  double launchAngleRad = launchAngle * M_PI / 180;

  // Projectile motion calculations
  double xPosition = 0;
  double yPosition = initialHeight;
  double xVelocity = initialVelocity * cos(launchAngleRad);
  double yVelocity = initialVelocity * sin(launchAngleRad);
  double time = 0;

  // Initialize variables for printing max height and distance
  double maxHeight = initialHeight;
  double maxDistance = 0;

  // Run simulation until projectile hits ground (yPosition < 0)
  while (yPosition >= 0) {
    // Update x and y position using kinematic equations
    xPosition += xVelocity * timeStep;
    yPosition += yVelocity * timeStep - 0.5 * GRAVITY * pow(timeStep, 2);

    // Update x and y velocities using kinematic equations
    xVelocity = initialVelocity * cos(launchAngleRad);
    yVelocity -= GRAVITY * timeStep;

    // Update time
    time += timeStep;

    // Check if we have new max height or distance
    if (yPosition > maxHeight) {
      maxHeight = yPosition;
    }
    if (xPosition > maxDistance) {
      maxDistance = xPosition;
    }

    // Print current state
    printf("Time: %lf seconds\t", time);
    printf("X Position: %lf meters\t", xPosition);
    printf("Y Position: %lf meters\n", yPosition);
  }

  // Print max height and distance
  printf("Max height: %lf meters\n", maxHeight);
  printf("Max distance: %lf meters\n", maxDistance);

  return 0;
}