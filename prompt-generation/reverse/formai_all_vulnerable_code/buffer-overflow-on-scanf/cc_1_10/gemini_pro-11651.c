//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the encryption key
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

// Function to encrypt a string
char *encrypt(char *plaintext) {
  int keylen = strlen(KEY);
  int plaintextlen = strlen(plaintext);

  // Allocate memory for the ciphertext
  char *ciphertext = malloc(plaintextlen + 1);
  
  // Encrypt the plaintext
  for (int i = 0; i < plaintextlen; i++) {
    int j = i % keylen;
    int k = plaintext[i];
    int l = KEY[j];
    ciphertext[i] = (k ^ l) & 0xFF;
  }

  // Add the null terminator
  ciphertext[plaintextlen] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
  int keylen = strlen(KEY);
  int ciphertextlen = strlen(ciphertext);

  // Allocate memory for the plaintext
  char *plaintext = malloc(ciphertextlen + 1);
  
  // Decrypt the ciphertext
  for (int i = 0; i < ciphertextlen; i++) {
    int j = i % keylen;
    int k = ciphertext[i];
    int l = KEY[j];
    plaintext[i] = (k ^ l) & 0xFF;
  }

  // Add the null terminator
  plaintext[ciphertextlen] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  char plaintext[1024];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *plaintext2 = decrypt(ciphertext);

  // Print the plaintext
  printf("Plaintext: %s\n", plaintext2);

  // Free the allocated memory
  free(ciphertext);
  free(plaintext2);

  return 0;
}