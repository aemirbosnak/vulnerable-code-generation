//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define your function prototypes here
int euclid(int a, int b);
int generate_key(int p, int q);

// Declare constant variables
const int MIN_VALUE = 2;
const int MAX_VALUE = 100;

int main() {
  // Declare your variables here
  int p, q, n, e, d, phi;

  // Generate random prime numbers
  do {
    p = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
  } while(!is_prime(p));

  do {
    q = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
  } while(!is_prime(q));

  // Calculate public and private keys
  n = p * q;
  phi = (p - 1) * (q - 1);
  e = generate_key(p, q);
  d = euclid(e, phi);

  // Print out the results
  printf("Your public key is (%d, %d).\n", n, e);
  printf("Your private key is (%d, %d).\n", n, d);

  return 0;
}

/**
 * Uses the Euclidean Algorithm to calculate the greatest common divisor of a and b.
 *
 * @param a     First integer.
 * @param b     Second integer.
 *
 * @return      The greatest common divisor of a and b.
 **/
int euclid(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return euclid(b, a % b);
  }
}

/**
 * Generates a public key that is relatively prime to (p - 1) * (q - 1).
 *
 * @param p     First prime factor.
 * @param q     Second prime factor.
 *
 * @return      A public key that is relatively prime to (p - 1) * (q - 1).
 **/
int generate_key(int p, int q) {
  int e;
  int phi = (p - 1) * (q - 1);

  do {
    e = rand() % (phi - 2) + 2;
  } while(euclid(e, phi) != 1);

  return e;
}

/**
 * Checks if a number is prime.
 *
 * @param n     The integer to check.
 *
 * @return      1 if n is prime, 0 otherwise.
 **/
int is_prime(int n) {
  int i;

  if (n <= 1) {
    return 0;
  }

  for (i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}