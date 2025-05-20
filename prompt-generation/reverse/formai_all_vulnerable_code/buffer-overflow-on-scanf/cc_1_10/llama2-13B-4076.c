//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

// Function to calculate the area of a circle
float circleArea(float radius) {
  return 3.14159 * radius * radius;
}

// Function to calculate the circumference of a circle
float circleCircumference(float radius) {
  return 2 * 3.14159 * radius;
}

// Function to calculate the surface area of a sphere
float sphereSurfaceArea(float radius) {
  return 4 * 3.14159 * radius * radius;
}

// Function to calculate the volume of a sphere
float sphereVolume(float radius) {
  return (4/3) * 3.14159 * radius * radius * radius;
}

int main() {
  // Declare variables
  float radius, area, circumference, surfaceArea, volume;

  // Get user input for radius
  printf("Enter the radius of the circle/sphere: ");
  scanf("%f", &radius);

  // Calculate and display the area of the circle
  area = circleArea(radius);
  printf("The area of the circle is: %f\n", area);

  // Calculate and display the circumference of the circle
  circumference = circleCircumference(radius);
  printf("The circumference of the circle is: %f\n", circumference);

  // Calculate and display the surface area of the sphere
  surfaceArea = sphereSurfaceArea(radius);
  printf("The surface area of the sphere is: %f\n", surfaceArea);

  // Calculate and display the volume of the sphere
  volume = sphereVolume(radius);
  printf("The volume of the sphere is: %f\n", volume);

  return 0;
}