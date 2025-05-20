//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Whaaaaaaat?! A prime number generator in C?!
  // This is gonna be eeeepic!

  // First, let's get some input from the user.
  // How many prime numbers do they want?
  int num_primes;
  printf("How many prime numbers do you want? ");
  scanf("%d", &num_primes);

  // Now, let's create an array to store the prime numbers.
  int *primes = (int *)malloc(sizeof(int) * num_primes);

  // We'll start by putting the first prime number, 2, in the array.
  primes[0] = 2;

  // Now, let's find the rest of the prime numbers.
  int next_prime = 3;  // Start with the next odd number after 2.
  int num_found = 1;   // We've already found 1 prime number.

  while (num_found < num_primes) {
    // Is the next number a prime number?
    bool is_prime = true;
    for (int i = 0; i < num_found; i++) {
      if (next_prime % primes[i] == 0) {
        is_prime = false;
        break;
      }
    }

    // If it's a prime number, add it to the array and increment the count.
    if (is_prime) {
      primes[num_found] = next_prime;
      num_found++;
    }

    // Move on to the next odd number.
    next_prime += 2;
  }

  // Now, let's print out the prime numbers.
  printf("The first %d prime numbers are:\n", num_primes);
  for (int i = 0; i < num_primes; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");

  // Free the memory that we allocated for the array.
  free(primes);

  return 0;
}