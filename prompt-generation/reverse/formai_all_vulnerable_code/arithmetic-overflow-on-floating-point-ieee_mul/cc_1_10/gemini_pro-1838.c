//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define variables
  int a = 10;
  int b = 5;
  double c = 3.14;
  double d = 2.71;

  // Perform basic arithmetic operations
  printf("a + b = %d\n", a + b);
  printf("a - b = %d\n", a - b);
  printf("a * b = %d\n", a * b);
  printf("a / b = %d\n", a / b);
  printf("a %% b = %d\n", a % b);

  // Perform floating-point operations
  printf("c + d = %f\n", c + d);
  printf("c - d = %f\n", c - d);
  printf("c * d = %f\n", c * d);
  printf("c / d = %f\n", c / d);

  // Perform exponential and logarithmic operations
  printf("pow(a, b) = %d\n", (int)pow(a, b));
  printf("sqrt(c) = %f\n", sqrt(c));
  printf("log(c) = %f\n", log(c));
  printf("log10(c) = %f\n", log10(c));

  // Perform trigonometric operations
  printf("sin(d) = %f\n", sin(d));
  printf("cos(d) = %f\n", cos(d));
  printf("tan(d) = %f\n", tan(d));

  // Perform hyperbolic operations
  printf("sinh(d) = %f\n", sinh(d));
  printf("cosh(d) = %f\n", cosh(d));
  printf("tanh(d) = %f\n", tanh(d));

  // Perform rounding operations
  printf("round(c) = %f\n", round(c));
  printf("ceil(c) = %f\n", ceil(c));
  printf("floor(c) = %f\n", floor(c));

  // Perform random number generation
  srand(time(NULL));
  printf("Random number between 0 and 99: %d\n", rand() % 100);

  return 0;
}