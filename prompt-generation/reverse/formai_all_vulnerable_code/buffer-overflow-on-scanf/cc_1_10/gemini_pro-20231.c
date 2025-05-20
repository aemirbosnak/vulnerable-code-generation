//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define some constants
  const double PI = 3.14159265358979323846;
  const double E = 2.71828182845904523536;
  const double SQRT_2 = 1.41421356237309504880;

  // Define some variables
  double x, y, z;

  // Get input from the user
  printf("Enter a number: ");
  scanf("%lf", &x);

  // Perform some calculations
  y = sin(x);
  z = cos(x);

  // Print the results
  printf("sin(%lf) = %lf\n", x, y);
  printf("cos(%lf) = %lf\n", x, z);

  // Calculate the area of a circle
  double radius, area;
  printf("Enter the radius of a circle: ");
  scanf("%lf", &radius);
  area = PI * radius * radius;
  printf("The area of a circle with radius %lf is %lf\n", radius, area);

  // Calculate the volume of a sphere
  double volume;
  volume = (4.0 / 3.0) * PI * radius * radius * radius;
  printf("The volume of a sphere with radius %lf is %lf\n", radius, volume);

  // Calculate the surface area of a sphere
  double surface_area;
  surface_area = 4.0 * PI * radius * radius;
  printf("The surface area of a sphere with radius %lf is %lf\n", radius, surface_area);

  // Calculate the distance between two points
  double x1, y1, x2, y2, distance;
  printf("Enter the coordinates of two points: ");
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  printf("The distance between the two points is %lf\n", distance);

  // Calculate the slope of a line
  double slope;
  slope = (y2 - y1) / (x2 - x1);
  printf("The slope of the line is %lf\n", slope);

  // Calculate the intercept of a line
  double intercept;
  intercept = y1 - slope * x1;
  printf("The intercept of the line is %lf\n", intercept);

  // Calculate the equation of a line
  printf("The equation of the line is y = %lfx + %lf\n", slope, intercept);

  return 0;
}