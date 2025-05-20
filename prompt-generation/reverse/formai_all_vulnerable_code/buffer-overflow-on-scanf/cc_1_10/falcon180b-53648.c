//Falcon-180B DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is even or odd
int isEven(int num) {
  if (num % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

// Function to calculate the factorial of a number
int factorial(int num) {
  int result = 1;
  for (int i = 1; i <= num; i++) {
    result *= i;
  }
  return result;
}

// Function to calculate the sum of even numbers up to a given number
int sumEven(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    if (isEven(i)) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  // Check if the number is even
  if (isEven(num)) {
    printf("%d is even.\n", num);
  } else {
    printf("%d is odd.\n", num);
  }

  // Calculate the factorial of the number
  int fact = factorial(num);
  printf("The factorial of %d is %d.\n", num, fact);

  // Calculate the sum of even numbers up to the given number
  int sum = sumEven(num);
  printf("The sum of even numbers up to %d is %d.\n", num, sum);

  return 0;
}