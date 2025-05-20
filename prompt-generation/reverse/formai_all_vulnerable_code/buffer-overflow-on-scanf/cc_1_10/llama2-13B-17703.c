//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a function to calculate the gravitational potential energy of two objects
double gravitationalPotentialEnergy(double mass1, double mass2, double distance) {
  // Check if the distance is negative
  if (distance < 0) {
    printf("Error: Distance must be non-negative. Please enter a valid distance.\n");
    return -1; // Return an error code
  }

  // Check if either mass is negative
  if (mass1 < 0 || mass2 < 0) {
    printf("Error: Mass must be non-negative. Please enter a valid mass.\n");
    return -1; // Return an error code
  }

  // Calculate the gravitational potential energy
  double gravitationalPotential = (mass1 * mass2) / (distance * distance);

  // Check if the gravitational potential energy is negative
  if (gravitationalPotential < 0) {
    printf("Error: Gravitational potential energy must be non-negative. Please enter a valid distance or mass.\n");
    return -1; // Return an error code
  }

  return gravitationalPotential;
}

int main() {
  double mass1, mass2, distance;

  // Get the user input
  printf("Enter the mass of object 1 (in kg): ");
  scanf("%lf", &mass1);
  printf("Enter the mass of object 2 (in kg): ");
  scanf("%lf", &mass2);
  printf("Enter the distance between the objects (in m): ");
  scanf("%lf", &distance);

  // Call the function to calculate the gravitational potential energy
  double gravitationalPotential = gravitationalPotentialEnergy(mass1, mass2, distance);

  // Check if the function returned an error code
  if (gravitationalPotential < 0) {
    printf("Error: Calculation failed. Please enter valid input.\n");
    return 1; // Return an error code
  }

  // Print the result
  printf("The gravitational potential energy between the two objects is: %lf J\n", gravitationalPotential);

  return 0; // Return success
}