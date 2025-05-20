//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prime number generator
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

// Greatest common divisor
int gcd(int a, int b) {
  while (b) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

// Modular exponentiation
int modPow(int base, int exponent, int modulus) {
  int result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exponent /= 2;
  }
  return result;
}

// Key generation
void generateKeys(int *e, int *d, int p, int q) {
  int n = p * q;
  int phiN = (p - 1) * (q - 1);
  for (*e = 3; *e < phiN; (*e) += 2)
    if (gcd(*e, phiN) == 1) break;
  for (*d = 3; *d < phiN; (*d) += 2)
    if ((*e) * (*d) % phiN == 1) break;
}

// Encryption
int encrypt(int m, int e, int n) { return modPow(m, e, n); }

// Decryption
int decrypt(int c, int d, int n) { return modPow(c, d, n); }

// Main function
int main() {
  // Generate two prime numbers
  int p, q;
  do {
    p = rand() % 1000;
  } while (!isPrime(p));
  do {
    q = rand() % 1000;
  } while (!isPrime(q));

  // Generate public and private keys
  int e, d;
  generateKeys(&e, &d, p, q);

  // Get the plaintext message
  char message[100];
  printf("Enter the plaintext message: ");
  gets(message);

  // Encrypt the message
  int ciphertext[strlen(message)];
  for (int i = 0; i < strlen(message); i++)
    ciphertext[i] = encrypt(message[i], e, p * q);

  // Decrypt the ciphertext
  char decryptedMessage[strlen(message)];
  for (int i = 0; i < strlen(message); i++)
    decryptedMessage[i] = decrypt(ciphertext[i], d, p * q);

  // Print the decrypted message
  printf("The decrypted message is: %s\n", decryptedMessage);

  return 0;
}