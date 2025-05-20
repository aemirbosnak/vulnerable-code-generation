//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  // These two variables will store the range of numbers we want to check for primality
  int lowerBound, upperBound;

  // Get the range from the user
  printf("Enter the lower bound: ");
  scanf("%d", &lowerBound);
  printf("Enter the upper bound: ");
  scanf("%d", &upperBound);

  // Create an array to store the prime numbers
  int *primeNumbers = malloc(sizeof(int) * (upperBound - lowerBound + 1));

  // Initialize the array to 0
  for (int i = 0; i < upperBound - lowerBound + 1; i++) {
    primeNumbers[i] = 0;
  }

  // Now, let's find all the prime numbers in the given range
  for (int i = 2; i <= upperBound; i++) {
    // Check if the number is prime
    int isPrime = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }

    // If the number is prime, store it in the array
    if (isPrime == 1) {
      primeNumbers[i - lowerBound] = i;
    }
  }

  // Print the prime numbers
  printf("The prime numbers between %d and %d are: ", lowerBound, upperBound);
  for (int i = 0; i < upperBound - lowerBound + 1; i++) {
    if (primeNumbers[i] != 0) {
      printf("%d ", primeNumbers[i]);
    }
  }
  printf("\n");

  // Free the memory allocated for the array
  free(primeNumbers);

  return 0;
}