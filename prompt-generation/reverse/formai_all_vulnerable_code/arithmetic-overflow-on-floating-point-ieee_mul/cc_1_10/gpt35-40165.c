//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
/* A Physics simulation program that models the motion of a projectile under the influence of gravity */

#include <stdio.h>
#include <math.h>

#define G 9.81    // Acceleration due to gravity in m/s^2

int main() {
  double angle, v, time, x, y, maxHeight, flightTime, range;
  const double PI = 3.14159265358979323846;
  
  // Get input from the user
  printf("Enter the angle of projection (in degrees): ");
  scanf("%lf", &angle);
  printf("Enter the initial velocity (in m/s): ");
  scanf("%lf", &v);
  
  // Convert the angle to radians
  angle = angle * PI / 180.0;

  // Calculate the maximum height
  maxHeight = (v * v * sin(angle) * sin(angle)) / (2.0 * G);
  printf("\nMaximum height reached: %.2lf meters\n", maxHeight);

  // Calculate the time of flight
  flightTime = (2.0 * v * sin(angle)) / G;
  printf("Time of flight: %.2lf seconds\n", flightTime);
  
  // Calculate the range
  range = (v * v * sin(2.0 * angle)) / G;
  printf("Range of the projectile: %.2lf meters\n\n", range);

  // Simulation loop
  for (time = 0; time <= flightTime + 0.1; time += 0.1) {
    x = v * cos(angle) * time;
    y = v * sin(angle) * time - 0.5 * G * time * time;
    
    // Round the coordinates to 2 decimal places
    x = round(x * 100.0) / 100.0;
    y = round(y * 100.0) / 100.0;
    
    // Print the coordinates of the projectile
    printf("Time = %.1lf s \t x = %.2lf m \t y = %.2lf m\n", time, x, y);
    
    // If the projectile hits the ground, break out of the loop
    if (y <= 0.0) {
      break;
    }
  }
  
  return 0;
}