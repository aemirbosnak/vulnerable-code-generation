//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: medieval
// Ye Olde Pythagorean Program
// by Cester of Canterbury

#include <stdio.h>
#include <stdlib.h>

// A faire knave's function to calculate the square root of a number
double square_root(double x) {
  // If the number is negative, verily 'tis a knave's trick!
  if (x < 0) {
    printf("Fie! Thou hast summoned a demon!");
    exit(1);
  }

  // If the number is 0, then the square root is 0
  if (x == 0) {
    return 0;
  }

  // Initialize the guess to be half the number
  double guess = x / 2;

  // Iterate until the guess is within a certain tolerance of the true square root
  while (fabs(guess * guess - x) > 0.000001) {
    // Calculate the new guess
    guess = (guess + x / guess) / 2;
  }

  // Return the square root
  return guess;
}

// A function to calculate the hypotenuse of a triangle given the lengths of the other two sides
double hypotenuse(double a, double b) {
  // If either side is negative, verily 'tis a knave's trick!
  if (a < 0 || b < 0) {
    printf("Fie! Thou hast summoned a demon!");
    exit(1);
  }

  // Calculate the square of the first side
  double a_squared = a * a;

  // Calculate the square of the second side
  double b_squared = b * b;

  // Calculate the square of the hypotenuse
  double c_squared = a_squared + b_squared;

  // Calculate the hypotenuse
  double c = square_root(c_squared);

  // Return the hypotenuse
  return c;
}

int main() {
  // Declare the variables
  double a, b, c;

  // Prompt the user to enter the lengths of the first two sides
  printf("Enter the length of the first side: ");
  scanf("%lf", &a);

  printf("Enter the length of the second side: ");
  scanf("%lf", &b);

  // Calculate the hypotenuse
  c = hypotenuse(a, b);

  // Print the result
  printf("The length of the hypotenuse is: %.2f\n", c);

  return 0;
}