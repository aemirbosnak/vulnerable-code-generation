//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define EULER 2.71828
#define SQRT2 1.41421
#define SQRT3 1.73205

int main() {
  int n, m, a, b, c;
  double x, y, z;

  // Exercise 1: Euler's Identity
  printf("Euler's Identity: \n");
  printf("e^(i%c) = %c\n", 'i', EULER);

  // Exercise 2: Pythagorean Triplets
  printf("Pythagorean Triplets: \n");
  for (a = 1; a <= 10; a++) {
    for (b = 1; b <= 10; b++) {
      c = sqrt(a*a + b*b);
      x = a/c;
      y = b/c;
      z = (a*x + b*y)/(x*y);
      printf("%d %d %d = %f %f %f\n", a, b, c, x, y, z);
    }
  }

  // Exercise 3: Fibonacci Numbers
  printf("Fibonacci Numbers: \n");
  for (n = 1; n <= 10; n++) {
    x = n * (n + 1) / 2;
    y = n * (n + 2) / 3;
    z = n * (n + 3) / 4;
    printf("%d = %f %f %f\n", n, x, y, z);
  }

  // Exercise 4: Square Root
  printf("Square Root: \n");
  for (n = 1; n <= 10; n++) {
    x = n * n;
    y = sqrt(x);
    z = x / y;
    printf("%d = %f %f %f\n", n, x, y, z);
  }

  // Exercise 5: Power
  printf("Power: \n");
  for (n = 1; n <= 10; n++) {
    x = n * n;
    y = n * n * n;
    z = n * n * n * n;
    printf("%d = %f %f %f\n", n, x, y, z);
  }

  return 0;
}