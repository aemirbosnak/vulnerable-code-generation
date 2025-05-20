//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
  if (num <= 1) return false;
  for (int i = 2; i <= num / 2; ++i) {
    if (num % i == 0) return false;
  }
  return true;
}

// Function to generate a list of prime numbers
int* generatePrimes(int limit) {
  int* primes = (int*) malloc((limit - 1) * sizeof(int));
  int index = 0;

  for (int i = 2; i <= limit; ++i) {
    if (isPrime(i)) {
      primes[index] = i;
      index++;
    }
  }

  return primes;
}

// Function to print a list of prime numbers
void printPrimes(int* primes, int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", primes[i]);
  }
  printf("\n");
}

int main() {
  int limit;

  printf("Enter the limit for prime number generation: ");
  scanf("%d", &limit);

  int* primes = generatePrimes(limit);
  int primeCount = (limit - 1);

  printf("List of prime numbers up to %d:\n", limit);
  printPrimes(primes, primeCount);

  free(primes);
  return 0;
}