//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int a, b, c, d, e;
  // Input 5 integer values
  printf("Enter 5 integer values: \n");
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

  // Calculate the sum of the numbers
  int sum = a + b + c + d + e;
  printf("The sum of the numbers is: %d\n", sum);

  // Calculate the average of the numbers
  float avg = sum / 5.0;
  printf("The average of the numbers is: %.2f\n", avg);

  // Find the maximum of the numbers
  int max = a;
  if (b > max) {
    max = b;
  }
  if (c > max) {
    max = c;
  }
  if (d > max) {
    max = d;
  }
  if (e > max) {
    max = e;
  }
  printf("The maximum of the numbers is: %d\n", max);

  // Find the minimum of the numbers
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  if (d < min) {
    min = d;
  }
  if (e < min) {
    min = e;
  }
  printf("The minimum of the numbers is: %d\n", min);

  // Calculate the product of the numbers
  int product = a * b * c * d * e;
  printf("The product of the numbers is: %d\n", product);

  return 0;
}