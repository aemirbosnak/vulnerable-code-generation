//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables
  int a, b, c;
  float x, y, z;

  // Get input from user
  printf("Enter three integers, separated by spaces: ");
  scanf("%d %d %d", &a, &b, &c);
  printf("Enter three floating-point numbers, separated by spaces: ");
  scanf("%f %f %f", &x, &y, &z);

  // Perform calculations
  int sum = a + b + c;
  float average = (x + y + z) / 3;
  float product = a * b * c;
  float quotient = x / y;
  float remainder = fmod(z, y);

  // Print results
  printf("Sum: %d\n", sum);
  printf("Average: %f\n", average);
  printf("Product: %f\n", product);
  printf("Quotient: %f\n", quotient);
  printf("Remainder: %f\n", remainder);

  // Perform additional calculations
  int max = fmax(a, fmax(b, c));
  int min = fmin(a, fmin(b, c));
  float absx = fabsf(x);
  float celf = (y - 32) * 5 / 9;
  float fahr = (z * 9 / 5) + 32;

  // Print additional results
  printf("Maximum: %d\n", max);
  printf("Minimum: %d\n", min);
  printf("Absolute value of x: %f\n", absx);
  printf("Celsius temperature: %f\n", celf);
  printf("Fahrenheit temperature: %f\n", fahr);

  // Generate random numbers
  int r1 = rand() % 100;
  float r2 = (float)rand() / (float)RAND_MAX;

  // Print random numbers
  printf("Random integer: %d\n", r1);
  printf("Random floating-point number: %f\n", r2);

  return 0;
}