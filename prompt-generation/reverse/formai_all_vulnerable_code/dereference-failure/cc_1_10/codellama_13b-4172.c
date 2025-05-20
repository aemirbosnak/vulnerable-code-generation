//Code Llama-13B DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
/*
 * Unique C Prime Number Generator Example Program
 *
 * This program generates prime numbers using the Sieve of Eratosthenes algorithm.
 * It is written in an enthusiastic style, with lots of comments and puns.
 *
 * To use this program, simply compile it and run it with a command like:
 *
 *     ./prime_numbers <max_number>
 *
 * where <max_number> is the maximum number of prime numbers you want to generate.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A function to generate prime numbers using the Sieve of Eratosthenes algorithm
void generate_primes(int max_number) {
  // Create an array to store the prime numbers
  int prime_numbers[max_number];

  // Initialize the first element of the array to 2
  prime_numbers[0] = 2;

  // Loop through the numbers 3 to max_number, inclusive
  for (int i = 3; i <= max_number; i += 2) {
    // If the number is not divisible by any of the previous prime numbers,
    // then it is a prime number
    bool is_prime = true;
    for (int j = 0; j < i; j++) {
      if (i % prime_numbers[j] == 0) {
        is_prime = false;
        break;
      }
    }

    // If the number is prime, add it to the array of prime numbers
    if (is_prime) {
      prime_numbers[i] = i;
    }
  }

  // Print the prime numbers
  for (int i = 0; i < max_number; i++) {
    printf("%d\n", prime_numbers[i]);
  }
}

// A main function to test the generate_primes function
int main(int argc, char *argv[]) {
  // Check if the user provided a command-line argument
  if (argc < 2) {
    printf("Usage: %s <max_number>\n", argv[0]);
    return 1;
  }

  // Convert the command-line argument to an integer
  int max_number = atoi(argv[1]);

  // Generate the prime numbers and print them
  generate_primes(max_number);

  return 0;
}