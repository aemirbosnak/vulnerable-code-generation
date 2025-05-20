//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "my_secret_key"

// Define the encryption function
void encrypt(char *plaintext, char *ciphertext) {
  int key_length = strlen(ENCRYPTION_KEY);
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ ENCRYPTION_KEY[i % key_length];
  }
}

// Define the decryption function
void decrypt(char *ciphertext, char *plaintext) {
  int key_length = strlen(ENCRYPTION_KEY);
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ ENCRYPTION_KEY[i % key_length];
  }
}

// Main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt the plaintext
  encrypt(plaintext, ciphertext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  decrypt(ciphertext, plaintext);

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", plaintext);

  // Free the allocated memory
  free(ciphertext);

  return 0;
}