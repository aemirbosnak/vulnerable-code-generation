//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the area of a circle
double circleArea(double radius) {
  return M_PI * radius * radius;
}

// Function to calculate the volume of a sphere
double sphereVolume(double radius) {
  return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

// Function to calculate the surface area of a sphere
double sphereSurfaceArea(double radius) {
  return 4.0 * M_PI * radius * radius;
}

// Function to calculate the volume of a cone
double coneVolume(double radius, double height) {
  return (1.0 / 3.0) * M_PI * radius * radius * height;
}

// Function to calculate the surface area of a cone
double coneSurfaceArea(double radius, double height) {
  return M_PI * radius * (radius + sqrt(height * height + radius * radius));
}

// Function to calculate the volume of a cylinder
double cylinderVolume(double radius, double height) {
  return M_PI * radius * radius * height;
}

// Function to calculate the surface area of a cylinder
double cylinderSurfaceArea(double radius, double height) {
  return 2.0 * M_PI * radius * (radius + height);
}

// Function to calculate the volume of a rectangular prism
double rectangularPrismVolume(double length, double width, double height) {
  return length * width * height;
}

// Function to calculate the surface area of a rectangular prism
double rectangularPrismSurfaceArea(double length, double width, double height) {
  return 2.0 * (length * width + width * height + height * length);
}

int main() {
  // Declare variables to store the user's input
  double radius, height, length, width;

  // Prompt the user to enter the radius of a circle
  printf("Enter the radius of a circle: ");
  scanf("%lf", &radius);

  // Calculate and print the area of the circle
  printf("The area of the circle is: %.2lf\n", circleArea(radius));

  // Prompt the user to enter the radius of a sphere
  printf("Enter the radius of a sphere: ");
  scanf("%lf", &radius);

  // Calculate and print the volume and surface area of the sphere
  printf("The volume of the sphere is: %.2lf\n", sphereVolume(radius));
  printf("The surface area of the sphere is: %.2lf\n", sphereSurfaceArea(radius));

  // Prompt the user to enter the radius and height of a cone
  printf("Enter the radius and height of a cone: ");
  scanf("%lf %lf", &radius, &height);

  // Calculate and print the volume and surface area of the cone
  printf("The volume of the cone is: %.2lf\n", coneVolume(radius, height));
  printf("The surface area of the cone is: %.2lf\n", coneSurfaceArea(radius, height));

  // Prompt the user to enter the radius and height of a cylinder
  printf("Enter the radius and height of a cylinder: ");
  scanf("%lf %lf", &radius, &height);

  // Calculate and print the volume and surface area of the cylinder
  printf("The volume of the cylinder is: %.2lf\n", cylinderVolume(radius, height));
  printf("The surface area of the cylinder is: %.2lf\n", cylinderSurfaceArea(radius, height));

  // Prompt the user to enter the length, width, and height of a rectangular prism
  printf("Enter the length, width, and height of a rectangular prism: ");
  scanf("%lf %lf %lf", &length, &width, &height);

  // Calculate and print the volume and surface area of the rectangular prism
  printf("The volume of the rectangular prism is: %.2lf\n", rectangularPrismVolume(length, width, height));
  printf("The surface area of the rectangular prism is: %.2lf\n", rectangularPrismSurfaceArea(length, width, height));

  return 0;
}