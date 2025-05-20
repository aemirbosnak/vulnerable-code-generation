//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of digits of a number
int sumDigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
  int reversedNum = 0;
  int temp = num;
  while (temp > 0) {
    reversedNum = reversedNum * 10 + temp % 10;
    temp /= 10;
  }
  return num == reversedNum;
}

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int num1, int num2) {
  if (num2 == 0) {
    return num1;
  } else {
    return gcd(num2, num1 % num2);
  }
}

// Function to find the least common multiple (LCM) of two numbers
int lcm(int num1, int num2) {
  return (num1 * num2) / gcd(num1, num2);
}

// Function to find the factorial of a number
int factorial(int num) {
  if (num == 0) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

// Function to check if a number is prime
int isPrime(int num) {
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

// Function to generate a random number between two numbers
int randomNum(int min, int max) {
  srand(time(NULL));
  return (rand() % (max - min + 1)) + min;
}

int main() {
  int num1, num2;

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  printf("Sum of digits of %d: %d\n", num1, sumDigits(num1));
  printf("Is %d a palindrome? %s\n", num1, isPalindrome(num1) ? "Yes" : "No");
  printf("GCD of %d and %d: %d\n", num1, num2, gcd(num1, num2));
  printf("LCM of %d and %d: %d\n", num1, num2, lcm(num1, num2));
  printf("Factorial of %d: %d\n", num1, factorial(num1));
  printf("Is %d prime? %s\n", num1, isPrime(num1) ? "Yes" : "No");
  printf("Random number between %d and %d: %d\n", num1, num2, randomNum(num1, num2));

  return 0;
}