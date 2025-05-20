//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRIME 1000

// Function declarations
int is_prime(int n);
int gcd(int a, int b);
int generate_public_key(int *e, int phi);
int generate_private_key(int e, int phi);
int encrypt(int m, int e, int n);
int decrypt(int c, int d, int n);

int main() {
  int p, q, n, phi, e, d;
  int m, c;

  srand(time(NULL));

  // Generate two random prime numbers p and q
  do {
    p = rand() % MAX_PRIME + 1;
  } while (!is_prime(p));
  
  do {
    q = rand() % MAX_PRIME + 1;
  } while (!is_prime(q));

  printf("p = %d, q = %d\n", p, q);

  // Calculate n and phi(n)
  n = p * q;
  phi = (p - 1) * (q - 1);

  // Generate public and private keys
  generate_public_key(&e, phi);
  d = generate_private_key(e, phi);

  printf("Public key: {%d, %d}\n", e, n);
  printf("Private key: {%d, %d}\n", d, n);

  // Encrypt and decrypt a message
  m = 123;
  c = encrypt(m, e, n);
  printf("Encrypted message: %d\n", c);

  m = decrypt(c, d, n);
  printf("Decrypted message: %d\n", m);

  return 0;
}

// Check if a number is prime
int is_prime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Calculate greatest common divisor of two numbers using Euclid's algorithm
int gcd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Generate a public key e that is coprime with phi(n)
int generate_public_key(int *e, int phi) {
  do {
    *e = rand() % (phi - 2) + 2;
  } while (gcd(*e, phi) != 1);
  return *e;
}

// Generate a private key d such that (e * d) mod phi(n) = 1
int generate_private_key(int e, int phi) {
  int d = 1;
  while ((d * e) % phi != 1) {
    d++;
  }
  return d;
}

// Encrypt a message using public key (e, n)
int encrypt(int m, int e, int n) {
  int c = 1;
  for (int i = 0; i < e; i++) {
    c = (c * m) % n;
  }
  return c;
}

// Decrypt a message using private key (d, n)
int decrypt(int c, int d, int n) {
  int m = 1;
  for (int i = 0; i < d; i++) {
    m = (m * c) % n;
  }
  return m;
}