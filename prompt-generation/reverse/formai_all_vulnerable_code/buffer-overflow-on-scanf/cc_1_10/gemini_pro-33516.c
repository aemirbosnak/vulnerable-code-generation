//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth fibonacci number
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to print the first n fibonacci numbers
void printFibonacci(int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");
}

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to print the factorial of the first n numbers
void printFactorial(int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", factorial(i));
  }
  printf("\n");
}

// Function to calculate the sum of the first n natural numbers
int sumOfNaturals(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + sumOfNaturals(n - 1);
  }
}

// Function to print the sum of the first n natural numbers
void printSumOfNaturals(int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", sumOfNaturals(i));
  }
  printf("\n");
}

// Main function
int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  printf("The first %d fibonacci numbers are: ", n);
  printFibonacci(n);

  printf("The factorial of the first %d numbers are: ", n);
  printFactorial(n);

  printf("The sum of the first %d natural numbers are: ", n);
  printSumOfNaturals(n);

  return 0;
}