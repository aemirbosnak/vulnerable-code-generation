//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
/*
 * Scientific Calculator Implementation in C
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265359
#define EULER 2.7182818284

// Function to calculate the square root of a number
double sqrt(double num) {
  return num * num;
}

// Function to calculate the power of a number
double power(double base, int exponent) {
  double result = 1;
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  return result;
}

// Function to calculate the factorial of a number
double factorial(int num) {
  double result = 1;
  for (int i = 1; i <= num; i++) {
    result *= i;
  }
  return result;
}

// Function to calculate the sine of an angle
double sine(double angle) {
  return sin(angle * PI / 180);
}

// Function to calculate the cosine of an angle
double cosine(double angle) {
  return cos(angle * PI / 180);
}

// Function to calculate the tangent of an angle
double tangent(double angle) {
  return tan(angle * PI / 180);
}

// Function to calculate the logarithm of a number
double logarithm(double num) {
  return log(num);
}

// Function to calculate the exponential of a number
double exponential(double num) {
  return exp(num);
}

// Main function
int main() {
  // Declare variables
  double num, result;
  int exponent;

  // Get input from user
  printf("Enter a number: ");
  scanf("%lf", &num);
  printf("Enter an exponent: ");
  scanf("%d", &exponent);

  // Calculate square root
  result = sqrt(num);
  printf("Square root of %lf is %lf\n", num, result);

  // Calculate power
  result = power(num, exponent);
  printf("%lf raised to the power of %d is %lf\n", num, exponent, result);

  // Calculate factorial
  result = factorial(num);
  printf("Factorial of %d is %lf\n", num, result);

  // Calculate sine, cosine, and tangent
  double angle;
  printf("Enter an angle in degrees: ");
  scanf("%lf", &angle);
  result = sine(angle);
  printf("Sine of %lf is %lf\n", angle, result);
  result = cosine(angle);
  printf("Cosine of %lf is %lf\n", angle, result);
  result = tangent(angle);
  printf("Tangent of %lf is %lf\n", angle, result);

  // Calculate logarithm and exponential
  result = logarithm(num);
  printf("Logarithm of %lf is %lf\n", num, result);
  result = exponential(num);
  printf("Exponential of %lf is %lf\n", num, result);

  return 0;
}