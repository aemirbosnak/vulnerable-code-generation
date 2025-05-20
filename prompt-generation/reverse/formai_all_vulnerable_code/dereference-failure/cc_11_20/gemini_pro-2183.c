//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Check if the user entered the correct number of arguments.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <start> <end>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Convert the arguments to integers.
  int start = atoi(argv[1]);
  int end = atoi(argv[2]);

  // Check if the start and end arguments are valid.
  if (start < 2 || start > end) {
    fprintf(stderr, "Error: Invalid range.\n");
    return EXIT_FAILURE;
  }

  // Create an array to store the prime numbers.
  int *primes = malloc(sizeof(int) * (end - start + 1));
  if (primes == NULL) {
    fprintf(stderr, "Error: Could not allocate memory.\n");
    return EXIT_FAILURE;
  }

  // Initialize the array to 0.
  for (int i = 0; i < end - start + 1; i++) {
    primes[i] = 0;
  }

  // Sieve of Eratosthenes algorithm.
  for (int i = 2; i <= end; i++) {
    if (primes[i - start] == 0) {
      // Mark multiples of i as non-prime.
      for (int j = i * i; j <= end; j += i) {
        primes[j - start] = 1;
      }
    }
  }

  // Print the prime numbers.
  for (int i = start; i <= end; i++) {
    if (primes[i - start] == 0) {
      printf("%d\n", i);
    }
  }

  // Free the array.
  free(primes);

  return EXIT_SUCCESS;
}