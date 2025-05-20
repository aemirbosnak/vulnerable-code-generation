//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P 13
#define Q 7
#define N (P * Q)
#define PHI_N ((P - 1) * (Q - 1))

unsigned long int power(unsigned long int base, unsigned long int exponent) {
  unsigned long int result = 1;
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  return result;
}

unsigned long int gcd(unsigned long int a, unsigned long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

unsigned long int extended_gcd(unsigned long int a, unsigned long int b, unsigned long int *x, unsigned long int *y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  unsigned long int gcd = extended_gcd(b, a % b, x, y);
  unsigned long int temp = *x;
  *x = *y;
  *y = temp - (a / b) * *y;
  return gcd;
}

unsigned long int modular_inverse(unsigned long int a, unsigned long int m) {
  unsigned long int x, y;
  unsigned long int gcd = extended_gcd(a, m, &x, &y);
  if (gcd != 1) {
    printf("Modular inverse does not exist.\n");
    return -1;
  }
  return (x % m + m) % m;
}

void generate_keys(unsigned long int *public_key, unsigned long int *private_key) {
  unsigned long int e = 2;
  while (gcd(e, PHI_N) != 1) {
    e++;
  }
  *public_key = e;
  *private_key = modular_inverse(*public_key, PHI_N);
}

unsigned long int encrypt(unsigned long int message, unsigned long int public_key) {
  return power(message, public_key) % N;
}

unsigned long int decrypt(unsigned long int ciphertext, unsigned long int private_key) {
  return power(ciphertext, private_key) % N;
}

int main() {
  unsigned long int message, public_key, private_key, encrypted_message, decrypted_message;

  printf("Enter a message to encrypt: ");
  scanf("%lu", &message);

  generate_keys(&public_key, &private_key);

  printf("Public key: %lu\n", public_key);
  printf("Private key: %lu\n", private_key);

  encrypted_message = encrypt(message, public_key);

  printf("Encrypted message: %lu\n", encrypted_message);

  decrypted_message = decrypt(encrypted_message, private_key);

  printf("Decrypted message: %lu\n", decrypted_message);

  return 0;
}