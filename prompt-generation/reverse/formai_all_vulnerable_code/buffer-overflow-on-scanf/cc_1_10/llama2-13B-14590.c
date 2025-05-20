//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.14159
#define E 2.71828

// Function to calculate the area of a circle
double circleArea(double radius) {
  return PI * radius * radius;
}

// Function to calculate the circumference of a circle
double circleCircumference(double radius) {
  return 2 * PI * radius;
}

// Function to calculate the surface area of a sphere
double sphereSurfaceArea(double radius) {
  return 4 * PI * radius * radius;
}

// Function to calculate the volume of a sphere
double sphereVolume(double radius) {
  return (4/3) * PI * radius * radius * radius;
}

int main() {
  double radius, area, circumference, surfaceArea, volume;

  // Prompt user for input
  printf("Enter the radius of the circle/sphere: ");
  scanf("%lf", &radius);

  // Calculate and print the area of the circle
  area = circleArea(radius);
  printf("The area of the circle is: %lf\n", area);

  // Calculate and print the circumference of the circle
  circumference = circleCircumference(radius);
  printf("The circumference of the circle is: %lf\n", circumference);

  // Calculate and print the surface area of the sphere
  surfaceArea = sphereSurfaceArea(radius);
  printf("The surface area of the sphere is: %lf\n", surfaceArea);

  // Calculate and print the volume of the sphere
  volume = sphereVolume(radius);
  printf("The volume of the sphere is: %lf\n", volume);

  return 0;
}