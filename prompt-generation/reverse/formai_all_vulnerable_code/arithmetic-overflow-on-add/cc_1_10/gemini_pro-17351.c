//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Initialize the random number generator
void init_rand() {
  srand(time(NULL));
}

// Generate a random number between 2 and max
int rand_num(int max) {
  return (rand() % (max - 2)) + 2;
}

// Check if a number is prime
int is_prime(int num) {
  int i;
  for (i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Generate a list of prime numbers
void generate_primes(int num_primes, int max) {
  int i, num_generated = 0;
  int *primes = malloc(num_primes * sizeof(int));
  init_rand();
  while (num_generated < num_primes) {
    int num = rand_num(max);
    if (is_prime(num)) {
      primes[num_generated++] = num;
    }
  }
  for (i = 0; i < num_primes; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");
  free(primes);
}

int main() {
  int num_primes, max;
  printf("Enter the number of prime numbers to generate: ");
  scanf("%d", &num_primes);
  printf("Enter the maximum value for the prime numbers: ");
  scanf("%d", &max);
  generate_primes(num_primes, max);
  return 0;
}