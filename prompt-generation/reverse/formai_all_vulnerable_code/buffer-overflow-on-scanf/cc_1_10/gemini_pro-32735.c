//GEMINI-pro DATASET v1.0 Category: Educational ; Style: inquisitive
// Can we optimize this C code further?

#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  int i = 5;
  while (i * i <= n) {
    if (n % i == 0 || n % (i + 2) == 0) return 0;
    i += 6;
  }
  return 1;
}

// Function to find the prime factors of a number
void primeFactors(int n) {
  // Print the number of 2s that divide n
  while (n % 2 == 0) {
    printf("%d ", 2);
    n /= 2;
  }

  // n must be odd at this point.  So we can skip one element (Note i = i +2)
  for (int i = 3; i * i <= n; i += 2) {
    // While i divides n, print i and divide n
    while (n % i == 0) {
      printf("%d ", i);
      n /= i;
    }
  }

  // This condition is to handle the case when n is a prime number greater than 2
  if (n > 2) printf("%d ", n);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (isPrime(n)) {
    printf("%d is a prime number.\n", n);
  } else {
    printf("%d is not a prime number.\nPrime factors of %d are: ", n, n);
    primeFactors(n);
  }

  return 0;
}