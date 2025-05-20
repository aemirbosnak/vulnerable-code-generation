//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "SECRETKEY"

// Define the encryption algorithm
char *encrypt(char *plaintext) {
  int keylen = strlen(KEY);
  char *ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ KEY[i % keylen];
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

// Define the decryption algorithm
char *decrypt(char *ciphertext) {
  int keylen = strlen(KEY);
  char *plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ KEY[i % keylen];
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decryptedtext = decrypt(ciphertext);

  // Print the decrypted text
  printf("The decrypted text is: %s\n", decryptedtext);

  return 0;
}