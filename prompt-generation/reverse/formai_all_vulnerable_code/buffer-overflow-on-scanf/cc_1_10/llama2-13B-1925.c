//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the area of a circle
double circleArea(double radius) {
  if (radius < 0) {
    return -1; // return -1 if radius is negative
  }
  return M_PI * radius * radius; // calculate the area of the circle
}

// Define a function to calculate the perimeter of a rectangle
double rectanglePerimeter(double width, double height) {
  if (width < 0 || height < 0) {
    return -1; // return -1 if either width or height is negative
  }
  return 2 * (width + height); // calculate the perimeter of the rectangle
}

int main() {
  double radius, width, height;
  double area, perimeter;

  // Ask the user for the radius of the circle
  printf("Enter the radius of the circle: ");
  scanf("%lf", &radius);

  // Calculate the area of the circle and print the result
  area = circleArea(radius);
  printf("The area of the circle is: %f\n", area);

  // Ask the user for the width and height of the rectangle
  printf("Enter the width and height of the rectangle: ");
  scanf("%lf%lf", &width, &height);

  // Calculate the perimeter of the rectangle and print the result
  perimeter = rectanglePerimeter(width, height);
  printf("The perimeter of the rectangle is: %f\n", perimeter);

  // Check if the radius is negative and print an error message
  if (radius < 0) {
    printf("Error: Negative radius not allowed.\n");
  }

  // Check if the width or height is negative and print an error message
  if (width < 0 || height < 0) {
    printf("Error: Negative width or height not allowed.\n");
  }

  return 0;
}