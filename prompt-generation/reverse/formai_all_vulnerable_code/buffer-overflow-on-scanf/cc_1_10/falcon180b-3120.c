//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double a, b, c;
  int n, i;
  char op;

  // Prompt user for input
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  // Initialize variables
  a = 0;
  b = 1;
  c = 0;

  // Get input from user
  for (i = 1; i <= n; i++) {
    printf("Enter term %d: ", i);
    scanf("%lf", &c);

    // Calculate next term
    if (i == 1) {
      a = c;
    } else if (i == 2) {
      b = c;
    } else {
      a = b;
      b = c;
      c = a + b;
    }
  }

  // Print Fibonacci series
  printf("Fibonacci series:\n");
  for (i = 1; i <= n; i++) {
    printf("%lf ", a);
  }
  printf("\n");

  // Calculate sum of series
  a = a + b;
  for (i = 2; i <= n; i++) {
    a = a + c;
  }
  printf("Sum of series: %lf\n", a);

  // Calculate average of series
  a = a / n;
  printf("Average of series: %lf\n", a);

  // Calculate product of series
  a = 1;
  for (i = 1; i <= n; i++) {
    a = a * c;
  }
  printf("Product of series: %lf\n", a);

  // Calculate sum of squares of series
  a = 0;
  for (i = 1; i <= n; i++) {
    a = a + pow(c, 2);
  }
  printf("Sum of squares of series: %lf\n", a);

  // Calculate standard deviation of series
  a = sqrt(a / n);
  printf("Standard deviation of series: %lf\n", a);

  return 0;
}