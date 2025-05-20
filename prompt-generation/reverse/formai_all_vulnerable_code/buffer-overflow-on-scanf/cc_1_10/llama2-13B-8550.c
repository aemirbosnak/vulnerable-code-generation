//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a function to calculate the area of a circle
double circleArea(double radius) {
  if (radius <= 0) {
    return -1; // return an error code
  }
  return 3.14159 * radius * radius;
}

// Define a function to calculate the perimeter of a circle
double circlePerimeter(double radius) {
  if (radius <= 0) {
    return -1; // return an error code
  }
  return 2 * 3.14159 * radius;
}

int main() {
  double radius;
  printf("Enter the radius of the circle: ");
  scanf("%lf", &radius);

  // Check if the input is valid
  if (radius <= 0) {
    printf("Invalid input. Please enter a positive value for the radius.\n");
    return 1;
  }

  // Calculate the area of the circle
  double area = circleArea(radius);
  if (area == -1) {
    printf("Error: The radius is invalid. Please enter a positive value for the radius.\n");
    return 2;
  }

  // Calculate the perimeter of the circle
  double perimeter = circlePerimeter(radius);
  if (perimeter == -1) {
    printf("Error: The radius is invalid. Please enter a positive value for the radius.\n");
    return 3;
  }

  // Print the results
  printf("The area of the circle is: %f\n", area);
  printf("The perimeter of the circle is: %f\n", perimeter);

  return 0;
}