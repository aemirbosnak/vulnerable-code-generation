//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables
  int a, b, c, d;
  float x, y, z;

  // Get input from user
  printf("Enter four integers: ");
  scanf("%d %d %d %d", &a, &b, &c, &d);
  printf("Enter three floats: ");
  scanf("%f %f %f", &x, &y, &z);

  // Perform basic arithmetic operations
  printf("a + b = %d\n", a + b);
  printf("a - b = %d\n", a - b);
  printf("a * b = %d\n", a * b);
  printf("a / b = %d\n", a / b);
  printf("a %% b = %d\n", a % b);

  // Perform floating-point arithmetic operations
  printf("x + y = %f\n", x + y);
  printf("x - y = %f\n", x - y);
  printf("x * y = %f\n", x * y);
  printf("x / y = %f\n", x / y);

  // Perform trigonometric operations
  printf("sin(x) = %f\n", sin(x));
  printf("cos(x) = %f\n", cos(x));
  printf("tan(x) = %f\n", tan(x));

  // Perform exponential and logarithmic operations
  printf("exp(x) = %f\n", exp(x));
  printf("log(x) = %f\n", log(x));
  printf("log10(x) = %f\n", log10(x));

  // Perform absolute value and rounding operations
  printf("abs(x) = %f\n", abs(x));
  printf("ceil(x) = %f\n", ceil(x));
  printf("floor(x) = %f\n", floor(x));
  printf("round(x) = %f\n", round(x));

  // Perform power and square root operations
  printf("pow(x, y) = %f\n", pow(x, y));
  printf("sqrt(x) = %f\n", sqrt(x));

  // Perform random number generation
  printf("Random number: %d\n", rand());

  return 0;
}