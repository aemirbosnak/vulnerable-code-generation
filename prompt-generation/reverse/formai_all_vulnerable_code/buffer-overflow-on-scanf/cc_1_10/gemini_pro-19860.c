//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool is_prime(int num) {
  if (num < 2) {
    return false;
  }
  if (num % 2 == 0 && num != 2) {
    return false;
  }
  for (int i = 3; i <= sqrt(num); i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// Function to generate a list of prime numbers up to a given limit
int *generate_primes(int limit) {
  int *primes = malloc(sizeof(int) * limit);
  int num_primes = 0;
  for (int i = 2; i <= limit; i++) {
    if (is_prime(i)) {
      primes[num_primes] = i;
      num_primes++;
    }
  }
  return primes;
}

// Function to print a list of prime numbers
void print_primes(int *primes, int num_primes) {
  for (int i = 0; i < num_primes; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");
}

int main() {
  int limit;

  // Get the limit from the user
  printf("Enter the limit up to which you want to generate prime numbers: ");
  scanf("%d", &limit);

  // Generate a list of prime numbers up to the given limit
  int *primes = generate_primes(limit);

  // Print the list of prime numbers
  printf("The prime numbers up to %d are: ", limit);
  print_primes(primes, limit);

  // Free the memory allocated for the list of prime numbers
  free(primes);

  return 0;
}