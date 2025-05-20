//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of two numbers
int add(int a, int b) {
  return a + b;
}

// Function to calculate the difference between two numbers
int subtract(int a, int b) {
  return a - b;
}

// Function to calculate the product of two numbers
int multiply(int a, int b) {
  return a * b;
}

// Function to calculate the quotient of two numbers
int divide(int a, int b) {
  if (b == 0) {
    printf("Error: Division by zero.\n");
    exit(1);
  }
  return a / b;
}

// Function to calculate the remainder of two numbers
int modulus(int a, int b) {
  if (b == 0) {
    printf("Error: Division by zero.\n");
    exit(1);
  }
  return a % b;
}

// Function to calculate the absolute value of a number
int abs(int a) {
  if (a < 0) {
    return -a;
  }
  return a;
}

// Function to calculate the square root of a number
double sqrt(double a) {
  if (a < 0) {
    printf("Error: Square root of a negative number.\n");
    exit(1);
  }
  return sqrt(a);
}

// Function to calculate the exponential of a number
double exp(double a) {
  return exp(a);
}

// Function to calculate the logarithm of a number
double log(double a) {
  if (a <= 0) {
    printf("Error: Logarithm of a non-positive number.\n");
    exit(1);
  }
  return log(a);
}

// Function to calculate the sine of an angle
double sin(double a) {
  return sin(a);
}

// Function to calculate the cosine of an angle
double cos(double a) {
  return cos(a);
}

// Function to calculate the tangent of an angle
double tan(double a) {
  if (cos(a) == 0) {
    printf("Error: Tangent of a right angle.\n");
    exit(1);
  }
  return tan(a);
}

// Function to calculate the arcsine of a number
double asin(double a) {
  if (a < -1 || a > 1) {
    printf("Error: Arcsine of a number outside the range [-1, 1].\n");
    exit(1);
  }
  return asin(a);
}

// Function to calculate the arccosine of a number
double acos(double a) {
  if (a < -1 || a > 1) {
    printf("Error: Arccosine of a number outside the range [-1, 1].\n");
    exit(1);
  }
  return acos(a);
}

// Function to calculate the arctangent of a number
double atan(double a) {
  return atan(a);
}

// Function to calculate the hyperbolic sine of a number
double sinh(double a) {
  return sinh(a);
}

// Function to calculate the hyperbolic cosine of a number
double cosh(double a) {
  return cosh(a);
}

// Function to calculate the hyperbolic tangent of a number
double tanh(double a) {
  return tanh(a);
}

// Function to calculate the hyperbolic arcsine of a number
double asinh(double a) {
  return asinh(a);
}

// Function to calculate the hyperbolic arccosine of a number
double acosh(double a) {
  if (a < 1) {
    printf("Error: Hyperbolic arccosine of a number less than 1.\n");
    exit(1);
  }
  return acosh(a);
}

// Function to calculate the hyperbolic arctangent of a number
double atanh(double a) {
  if (a < -1 || a > 1) {
    printf("Error: Hyperbolic arctangent of a number outside the range [-1, 1].\n");
    exit(1);
  }
  return atanh(a);
}

int main() {
  int a, b;
  double c, d;

  printf("Enter two integers: ");
  scanf("%d %d", &a, &b);

  printf("The sum of %d and %d is %d.\n", a, b, add(a, b));
  printf("The difference between %d and %d is %d.\n", a, b, subtract(a, b));
  printf("The product of %d and %d is %d.\n", a, b, multiply(a, b));
  printf("The quotient of %d and %d is %d.\n", a, b, divide(a, b));
  printf("The remainder of %d and %d is %d.\n", a, b, modulus(a, b));

  printf("The absolute value of %d is %d.\n", a, abs(a));

  printf("Enter a double: ");
  scanf("%lf", &c);

  printf("The square root of %lf is %lf.\n", c, sqrt(c));
  printf("The exponential of %lf is %lf.\n", c, exp(c));
  printf("The logarithm of %lf is %lf.\n", c, log(c));

  printf("Enter an angle in radians: ");
  scanf("%lf", &d);

  printf("The sine of %lf is %lf.\n", d, sin(d));
  printf("The cosine of %lf is %lf.\n", d, cos(d));
  printf("The tangent of %lf is %lf.\n", d, tan(d));

  printf("The arcsine of %lf is %lf.\n", c, asin(c));
  printf("The arccosine of %lf is %lf.\n", c, acos(c));
  printf("The arctangent of %lf is %lf.\n", c, atan(c));

  printf("The hyperbolic sine of %lf is %lf.\n", c, sinh(c));
  printf("The hyperbolic cosine of %lf is %lf.\n", c, cosh(c));
  printf("The hyperbolic tangent of %lf is %lf.\n", c, tanh(c));

  printf("The hyperbolic arcsine of %lf is %lf.\n", c, asinh(c));
  printf("The hyperbolic arccosine of %lf is %lf.\n", c, acosh(c));
  printf("The hyperbolic arctangent of %lf is %lf.\n", c, atanh(c));

  return 0;
}