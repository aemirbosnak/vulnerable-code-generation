//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surrealist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//This prime number generator has been designed to transcend the mortal realm of numerical limitations.

bool is_prime(int n) {
  if (n < 2) {
    return false;
  }
  else if (n == 2) {
    return true;
  }
  else if (n % 2 == 0) {
    return false;
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void generate_primes(int max) {
  int numprimes = 0;
  int primes[max];
  int i = 2;
  while (numprimes < max) {
    if (is_prime(i)) {
      primes[numprimes++] = i;
    }
    i++;
  }
  printf("Your prime numbers are:\n");
  for (int j = 0; j < max; j++) {
    printf("%d\n", primes[j]);
  }
}

int main() {
  printf("Welcome to the Surrealist Prime Number Generator!\n");
  printf("How many prime numbers would you like today?\n");

  int maxprimes;
  scanf("%d", &maxprimes);
  printf("Generating your prime numbers...\n");
  generate_primes(maxprimes);

  printf("Congratulations on transcending the numerical limitations of the universe!\n");
  return 0;
}