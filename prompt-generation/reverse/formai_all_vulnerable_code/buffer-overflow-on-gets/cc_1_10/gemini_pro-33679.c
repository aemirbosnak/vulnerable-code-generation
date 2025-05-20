//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define KEY "ENCRYPTME"

// Define the encryption function.
void encrypt(char *plaintext, char *ciphertext) {
  int keylen = strlen(KEY);
  int plaintextlen = strlen(plaintext);

  for (int i = 0; i < plaintextlen; i++) {
    ciphertext[i] = plaintext[i] ^ KEY[i % keylen];
  }

  ciphertext[plaintextlen] = '\0';
}

// Define the decryption function.
void decrypt(char *ciphertext, char *plaintext) {
  int keylen = strlen(KEY);
  int ciphertextlen = strlen(ciphertext);

  for (int i = 0; i < ciphertextlen; i++) {
    plaintext[i] = ciphertext[i] ^ KEY[i % keylen];
  }

  plaintext[ciphertextlen] = '\0';
}

// Main function.
int main() {
  // Get the plaintext from the user.
  char plaintext[1024];
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Encrypt the plaintext.
  char ciphertext[1024];
  encrypt(plaintext, ciphertext);

  // Print the ciphertext.
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext.
  char decryptedtext[1024];
  decrypt(ciphertext, decryptedtext);

  // Print the decrypted text.
  printf("The decrypted text is: %s\n", decryptedtext);

  return 0;
}