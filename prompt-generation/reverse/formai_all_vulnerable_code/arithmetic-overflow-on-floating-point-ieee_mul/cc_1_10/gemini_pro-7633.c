//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a circle
float circle_area(float radius) {
  return M_PI * radius * radius;
}

// Function to calculate the volume of a sphere
float sphere_volume(float radius) {
  return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

// Function to calculate the surface area of a sphere
float sphere_surface_area(float radius) {
  return 4.0 * M_PI * radius * radius;
}

// Function to calculate the volume of a cone
float cone_volume(float radius, float height) {
  return (1.0 / 3.0) * M_PI * radius * radius * height;
}

// Function to calculate the surface area of a cone
float cone_surface_area(float radius, float height) {
  return M_PI * radius * (radius + sqrtf(height * height + radius * radius));
}

// Function to calculate the volume of a cylinder
float cylinder_volume(float radius, float height) {
  return M_PI * radius * radius * height;
}

// Function to calculate the surface area of a cylinder
float cylinder_surface_area(float radius, float height) {
  return 2.0 * M_PI * radius * (radius + height);
}

int main() {
  // Declare variables
  float radius, height;

  // Get the radius and height from the user
  printf("Enter the radius: ");
  scanf("%f", &radius);
  printf("Enter the height: ");
  scanf("%f", &height);

  // Calculate the area of the circle
  float circle_area_result = circle_area(radius);

  // Calculate the volume of the sphere
  float sphere_volume_result = sphere_volume(radius);

  // Calculate the surface area of the sphere
  float sphere_surface_area_result = sphere_surface_area(radius);

  // Calculate the volume of the cone
  float cone_volume_result = cone_volume(radius, height);

  // Calculate the surface area of the cone
  float cone_surface_area_result = cone_surface_area(radius, height);

  // Calculate the volume of the cylinder
  float cylinder_volume_result = cylinder_volume(radius, height);

  // Calculate the surface area of the cylinder
  float cylinder_surface_area_result = cylinder_surface_area(radius, height);

  // Print the results
  printf("The area of the circle is: %.2f\n", circle_area_result);
  printf("The volume of the sphere is: %.2f\n", sphere_volume_result);
  printf("The surface area of the sphere is: %.2f\n", sphere_surface_area_result);
  printf("The volume of the cone is: %.2f\n", cone_volume_result);
  printf("The surface area of the cone is: %.2f\n", cone_surface_area_result);
  printf("The volume of the cylinder is: %.2f\n", cylinder_volume_result);
  printf("The surface area of the cylinder is: %.2f\n", cylinder_surface_area_result);

  return 0;
}