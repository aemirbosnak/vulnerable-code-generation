//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

int main() {

  int a, b, c, d, e, f, sum;

  printf("Enter six numbers:\n");
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

  sum = a + b + c + d + e + f;

  printf("The sum of the numbers is: %d\n", sum);

  int product = a * b * c * d * e * f;

  printf("The product of the numbers is: %d\n", product);

  int average = sum / 6;

  printf("The average of the numbers is: %d\n", average);

  int maximum = a;

  if (b > maximum) {
    maximum = b;
  }

  if (c > maximum) {
    maximum = c;
  }

  if (d > maximum) {
    maximum = d;
  }

  if (e > maximum) {
    maximum = e;
  }

  if (f > maximum) {
    maximum = f;
  }

  printf("The maximum number out of the six is: %d\n", maximum);

  int minimum = a;

  if (b < minimum) {
    minimum = b;
  }

  if (c < minimum) {
    minimum = c;
  }

  if (d < minimum) {
    minimum = d;
  }

  if (e < minimum) {
    minimum = e;
  }

  if (f < minimum) {
    minimum = f;
  }

  printf("The minimum number out of the six is: %d\n", minimum);

  return 0;
}