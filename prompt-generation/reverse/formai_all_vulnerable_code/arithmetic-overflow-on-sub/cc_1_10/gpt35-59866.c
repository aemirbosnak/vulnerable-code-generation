//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long gcd(long a, long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

long modular_pow(long base, long exponent, long modulus) {
  long result = 1;
  while (exponent > 0) {
    if (exponent % 2 != 0) {
      result = (result * base) % modulus;
    }
    base = (base * base) % modulus;
    exponent = exponent / 2;
  }
  return result;
}

int main() {
  long p, q, n, phi, e, d;
  srand(time(0));
  
  /* Configuration */
  printf("Enter the value of p (prime number): ");
  scanf("%ld", &p);
  printf("Enter the value of q (prime number): ");
  scanf("%ld", &q);
  n = p * q;
  phi = (p - 1) * (q - 1);
  printf("n = %ld\nphi = %ld\n", n, phi);
  
  /* Generate key pair */
  do {
    e = rand() % phi; // Pick a random e such that 1 < e < phi and gcd(e, phi) = 1
  } while (gcd(e, phi) != 1);
  d = modular_pow(e, -1, phi); // Find d such that (e * d) % phi = 1
  printf("Public Key = {%ld, %ld}\nPrivate Key = {%ld, %ld}\n", e, n, d, n);

  /* Encryption */
  long plaintext, ciphertext;
  printf("Enter the plaintext (integer): ");
  scanf("%ld", &plaintext);
  ciphertext = modular_pow(plaintext, e, n);
  printf("Ciphertext = %ld\n", ciphertext);

  /* Decryption */
  printf("Decrypt the ciphertext (using private key)...\n");
  long decrypted_text = modular_pow(ciphertext, d, n);
  printf("Decrypted Text = %ld\n", decrypted_text);

  return 0;
}