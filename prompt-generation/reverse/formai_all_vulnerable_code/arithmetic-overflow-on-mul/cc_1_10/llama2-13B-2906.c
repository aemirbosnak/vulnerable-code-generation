//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the factorial of a given integer
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Define a function to calculate the sum of the first n natural numbers
int sum_of_natural_numbers(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

// Define a function to calculate the product of the first n natural numbers
int product_of_natural_numbers(int n) {
  int product = 1;
  for (int i = 1; i <= n; i++) {
    product *= i;
  }
  return product;
}

int main() {
  int n, m, k;
  double average, standard_deviation;

  // Calculate the factorial of a given integer
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("The factorial of %d is %d.\n", n, factorial(n));

  // Calculate the sum of the first n natural numbers
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("The sum of the first %d natural numbers is %d.\n", n, sum_of_natural_numbers(n));

  // Calculate the product of the first n natural numbers
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("The product of the first %d natural numbers is %d.\n", n, product_of_natural_numbers(n));

  // Calculate the average of the first n natural numbers
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  average = (double)sum_of_natural_numbers(n) / n;
  printf("The average of the first %d natural numbers is %f.\n", n, average);

  // Calculate the standard deviation of the first n natural numbers
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  standard_deviation = sqrt((double)sum_of_natural_numbers(n * (n - 1)) / (n * n));
  printf("The standard deviation of the first %d natural numbers is %f.\n", n, standard_deviation);

  return 0;
}