//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: careful
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
bool is_prime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// Function to generate the next prime number after the given number
int next_prime(int n) {
  int next = n + 1;
  while (!is_prime(next)) {
    next++;
  }
  return next;
}

int main() {
  // Get the user's input for the number of prime numbers to generate
  int num_primes;
  printf("Enter the number of prime numbers to generate: ");
  scanf("%d", &num_primes);

  // Check if the user entered a valid number
  if (num_primes <= 0) {
    printf("Invalid number of prime numbers. Please enter a positive integer.\n");
    return 1;
  }

  // Initialize the current prime number to 2
  int current_prime = 2;

  // Generate the specified number of prime numbers
  for (int i = 0; i < num_primes; i++) {
    // Print the current prime number
    printf("%d ", current_prime);

    // Get the next prime number
    current_prime = next_prime(current_prime);
  }

  printf("\n");
  return 0;
}