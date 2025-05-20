//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of digits in a number
int sum_of_digits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

// Function to calculate the product of digits in a number
int product_of_digits(int num) {
  int product = 1;
  while (num > 0) {
    product *= num % 10;
    num /= 10;
  }
  return product;
}

// Function to check if a number is prime
int is_prime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to calculate the factorial of a number
int factorial(int num) {
  int fact = 1;
  for (int i = 1; i <= num; i++) {
    fact *= i;
  }
  return fact;
}

// Function to calculate the sum of odd numbers up to a given number
int sum_of_odd_numbers(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    if (i % 2 != 0) {
      sum += i;
    }
  }
  return sum;
}

// Function to calculate the sum of even numbers up to a given number
int sum_of_even_numbers(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    if (i % 2 == 0) {
      sum += i;
    }
  }
  return sum;
}

// Function to calculate the sum of squares of numbers up to a given number
int sum_of_squares(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    sum += i * i;
  }
  return sum;
}

// Function to calculate the sum of cubes of numbers up to a given number
int sum_of_cubes(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    sum += i * i * i;
  }
  return sum;
}

// Main function to test the above functions
int main() {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  printf("Sum of digits: %d\n", sum_of_digits(num));
  printf("Product of digits: %d\n", product_of_digits(num));
  printf("Is prime: %s\n", is_prime(num) ? "Yes" : "No");
  printf("Factorial: %d\n", factorial(num));
  printf("Sum of odd numbers up to %d: %d\n", num, sum_of_odd_numbers(num));
  printf("Sum of even numbers up to %d: %d\n", num, sum_of_even_numbers(num));
  printf("Sum of squares of numbers up to %d: %d\n", num, sum_of_squares(num));
  printf("Sum of cubes of numbers up to %d: %d\n", num, sum_of_cubes(num));

  return 0;
}