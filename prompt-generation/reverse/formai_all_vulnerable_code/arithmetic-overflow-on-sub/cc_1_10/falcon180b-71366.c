//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME 1000
#define MAX_SIZE 1000

int is_prime(int n) {
  int i;
  if (n < 2) {
    return 0;
  }
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int generate_prime(int n) {
  int i;
  for (i = 2; i <= MAX_PRIME; i++) {
    if (is_prime(i)) {
      n--;
      if (n == 0) {
        return i;
      }
    }
  }
  return -1;
}

int generate_key(int prime, int size) {
  int i;
  int key = 2;
  while (key <= prime - 1) {
    for (i = 0; i < size; i++) {
      key = (key * key) % prime;
    }
  }
  return key;
}

int main() {
  int prime, size;
  printf("Enter prime number: ");
  scanf("%d", &prime);
  printf("Enter key size: ");
  scanf("%d", &size);

  int public_key = generate_key(prime, size);
  int private_key = (prime - 1) / public_key;

  printf("Public key: %d\n", public_key);
  printf("Private key: %d\n", private_key);

  return 0;
}