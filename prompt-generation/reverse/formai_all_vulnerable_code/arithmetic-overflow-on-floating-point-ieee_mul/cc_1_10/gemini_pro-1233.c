//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the tolerance for the convergence criterion
#define TOLERANCE 1e-6

// Function to calculate the square root of a number using the Babylonian method
double babylonian_sqrt(double number) {
  // Initialize the guess
  double guess = number / 2;

  // Iterate until the guess converges
  int iteration = 0;
  while (fabs(guess * guess - number) > TOLERANCE && iteration < MAX_ITERATIONS) {
    // Update the guess
    guess = (guess + number / guess) / 2;

    // Increment the iteration count
    iteration++;
  }

  // Return the guess
  return guess;
}

// Function to calculate the factorial of a number
int factorial(int number) {
  // Initialize the factorial
  int factorial = 1;

  // Multiply the factorial by all the numbers from 1 to the given number
  for (int i = 1; i <= number; i++) {
    factorial *= i;
  }

  // Return the factorial
  return factorial;
}

// Function to calculate the binomial coefficient
int binomial_coefficient(int n, int k) {
  // Return the factorial of n divided by the product of the factorials of k and n - k
  return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to calculate the area of a triangle
double triangle_area(double base, double height) {
  // Return half of the product of the base and the height
  return 0.5 * base * height;
}

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
  // Return the volume of a sphere with the given radius
  return (4 / 3) * M_PI * pow(radius, 3);
}

// Function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
  // Return the surface area of a sphere with the given radius
  return 4 * M_PI * pow(radius, 2);
}

int main() {
  // Print the square root of 2 using the Babylonian method
  printf("The square root of 2 is: %f\n", babylonian_sqrt(2));

  // Print the factorial of 5
  printf("The factorial of 5 is: %d\n", factorial(5));

  // Print the binomial coefficient of 10 and 5
  printf("The binomial coefficient of 10 and 5 is: %d\n", binomial_coefficient(10, 5));

  // Print the area of a triangle with a base of 10 and a height of 5
  printf("The area of a triangle with a base of 10 and a height of 5 is: %f\n", triangle_area(10, 5));

  // Print the volume of a sphere with a radius of 5
  printf("The volume of a sphere with a radius of 5 is: %f\n", sphere_volume(5));

  // Print the surface area of a sphere with a radius of 5
  printf("The surface area of a sphere with a radius of 5 is: %f\n", sphere_surface_area(5));

  return 0;
}