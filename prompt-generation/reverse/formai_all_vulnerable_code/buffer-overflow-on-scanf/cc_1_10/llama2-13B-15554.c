//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <math.h>

// Define constants and variables
const double PI = 3.14159;
const double E = 2.71828;
double a, b, c, d, e, f, g;

// Function to calculate the area of a circle
double circleArea(double radius) {
  return PI * radius * radius;
}

// Function to calculate the circumference of a circle
double circleCircumference(double radius) {
  return 2 * PI * radius;
}

// Function to calculate the volume of a sphere
double sphereVolume(double radius) {
  return (4 / 3) * PI * radius * radius * radius;
}

// Function to calculate the surface area of a sphere
double sphereSurfaceArea(double radius) {
  return 4 * PI * radius * (radius * (radius + 1));
}

// Function to calculate the work done by a force
double forceWork(double force, double distance) {
  return force * distance;
}

// Function to calculate the energy of an object
double objectEnergy(double mass, double velocity) {
  return 0.5 * mass * velocity * velocity;
}

int main() {
  // Input values
  printf("Enter the value of a (in meters): ");
  scanf("%lf", &a);
  printf("Enter the value of b (in meters): ");
  scanf("%lf", &b);
  printf("Enter the value of c (in meters): ");
  scanf("%lf", &c);
  printf("Enter the value of d (in meters): ");
  scanf("%lf", &d);
  printf("Enter the value of e (in meters): ");
  scanf("%lf", &e);
  printf("Enter the value of f (in meters): ");
  scanf("%lf", &f);
  printf("Enter the value of g (in meters): ");
  scanf("%lf", &g);

  // Calculate the area of the circle
  double circleArea_result = circleArea(a);
  printf("The area of the circle with radius %lf is %lf square meters.\n", a, circleArea_result);

  // Calculate the circumference of the circle
  double circleCircumference_result = circleCircumference(a);
  printf("The circumference of the circle with radius %lf is %lf meters.\n", a, circleCircumference_result);

  // Calculate the volume of the sphere
  double sphereVolume_result = sphereVolume(c);
  printf("The volume of the sphere with radius %lf is %lf cubic meters.\n", c, sphereVolume_result);

  // Calculate the surface area of the sphere
  double sphereSurfaceArea_result = sphereSurfaceArea(c);
  printf("The surface area of the sphere with radius %lf is %lf square meters.\n", c, sphereSurfaceArea_result);

  // Calculate the work done by the force
  double forceWork_result = forceWork(f, e);
  printf("The work done by the force of %lf N over a distance of %lf meters is %lf Joules.\n", f, e, forceWork_result);

  // Calculate the energy of the object
  double objectEnergy_result = objectEnergy(g, d);
  printf("The energy of the object with mass %lf kg and velocity %lf m/s is %lf Joules.\n", g, d, objectEnergy_result);

  return 0;
}