//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the function prototypes
double calculate_area_of_circle(double radius);
double calculate_area_of_triangle(double base, double height);
double calculate_area_of_rectangle(double length, double width);
double calculate_area_of_trapezoid(double base1, double base2, double height);
double calculate_area_of_parallelogram(double base, double height);
double calculate_area_of_rhombus(double diagonal1, double diagonal2);
double calculate_area_of_ellipse(double major_axis, double minor_axis);
double calculate_area_of_sector(double radius, double angle);
double calculate_area_of_segment(double radius, double angle);

int main() {
  // Declare the variables
  double radius, base, height, length, width, base1, base2, diagonal1, diagonal2, major_axis, minor_axis, angle;

  // Get the input from the user
  printf("Enter the radius of the circle: ");
  scanf("%lf", &radius);
  printf("Enter the base and height of the triangle: ");
  scanf("%lf %lf", &base, &height);
  printf("Enter the length and width of the rectangle: ");
  scanf("%lf %lf", &length, &width);
  printf("Enter the bases and height of the trapezoid: ");
  scanf("%lf %lf %lf", &base1, &base2, &height);
  printf("Enter the base and height of the parallelogram: ");
  scanf("%lf %lf", &base, &height);
  printf("Enter the diagonals of the rhombus: ");
  scanf("%lf %lf", &diagonal1, &diagonal2);
  printf("Enter the major and minor axes of the ellipse: ");
  scanf("%lf %lf", &major_axis, &minor_axis);
  printf("Enter the radius and angle of the sector: ");
  scanf("%lf %lf", &radius, &angle);
  printf("Enter the radius and angle of the segment: ");
  scanf("%lf %lf", &radius, &angle);

  // Calculate the areas
  double area_of_circle = calculate_area_of_circle(radius);
  double area_of_triangle = calculate_area_of_triangle(base, height);
  double area_of_rectangle = calculate_area_of_rectangle(length, width);
  double area_of_trapezoid = calculate_area_of_trapezoid(base1, base2, height);
  double area_of_parallelogram = calculate_area_of_parallelogram(base, height);
  double area_of_rhombus = calculate_area_of_rhombus(diagonal1, diagonal2);
  double area_of_ellipse = calculate_area_of_ellipse(major_axis, minor_axis);
  double area_of_sector = calculate_area_of_sector(radius, angle);
  double area_of_segment = calculate_area_of_segment(radius, angle);

  // Print the results
  printf("The area of the circle is: %lf\n", area_of_circle);
  printf("The area of the triangle is: %lf\n", area_of_triangle);
  printf("The area of the rectangle is: %lf\n", area_of_rectangle);
  printf("The area of the trapezoid is: %lf\n", area_of_trapezoid);
  printf("The area of the parallelogram is: %lf\n", area_of_parallelogram);
  printf("The area of the rhombus is: %lf\n", area_of_rhombus);
  printf("The area of the ellipse is: %lf\n", area_of_ellipse);
  printf("The area of the sector is: %lf\n", area_of_sector);
  printf("The area of the segment is: %lf\n", area_of_segment);

  return 0;
}

// Define the function to calculate the area of a circle
double calculate_area_of_circle(double radius) {
  return M_PI * radius * radius;
}

// Define the function to calculate the area of a triangle
double calculate_area_of_triangle(double base, double height) {
  return 0.5 * base * height;
}

// Define the function to calculate the area of a rectangle
double calculate_area_of_rectangle(double length, double width) {
  return length * width;
}

// Define the function to calculate the area of a trapezoid
double calculate_area_of_trapezoid(double base1, double base2, double height) {
  return 0.5 * (base1 + base2) * height;
}

// Define the function to calculate the area of a parallelogram
double calculate_area_of_parallelogram(double base, double height) {
  return base * height;
}

// Define the function to calculate the area of a rhombus
double calculate_area_of_rhombus(double diagonal1, double diagonal2) {
  return 0.5 * diagonal1 * diagonal2;
}

// Define the function to calculate the area of an ellipse
double calculate_area_of_ellipse(double major_axis, double minor_axis) {
  return M_PI * major_axis * minor_axis;
}

// Define the function to calculate the area of a sector
double calculate_area_of_sector(double radius, double angle) {
  return 0.5 * radius * radius * angle;
}

// Define the function to calculate the area of a segment
double calculate_area_of_segment(double radius, double angle) {
  return radius * radius * (angle - sin(angle)) / 2;
}