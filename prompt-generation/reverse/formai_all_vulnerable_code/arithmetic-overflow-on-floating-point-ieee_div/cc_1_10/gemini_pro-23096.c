//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the mass of the object
#define MASS 1.0

// Define the gravitational constant
#define G 9.81

// Define the time step
#define DT 0.01

// Define the number of iterations
#define ITERATIONS 1000

// Define the initial position and velocity of the object
double x = 0.0;
double y = 0.0;
double vx = 0.0;
double vy = 0.0;

// Main function
int main() {
  // Open a file to write the data to
  FILE *fp = fopen("data.txt", "w");

  // Initialize the time
  double t = 0.0;

  // Loop over the iterations
  for (int i = 0; i < ITERATIONS; i++) {
    // Calculate the acceleration of the object
    double ax = -G * MASS / pow(x * x + y * y, 1.5);
    double ay = -G * MASS / pow(x * x + y * y, 1.5);

    // Update the velocity of the object
    vx += ax * DT;
    vy += ay * DT;

    // Update the position of the object
    x += vx * DT;
    y += vy * DT;

    // Write the data to the file
    fprintf(fp, "%f %f %f %f\n", t, x, y, sqrt(vx * vx + vy * vy));

    // Update the time
    t += DT;
  }

  // Close the file
  fclose(fp);

  return 0;
}