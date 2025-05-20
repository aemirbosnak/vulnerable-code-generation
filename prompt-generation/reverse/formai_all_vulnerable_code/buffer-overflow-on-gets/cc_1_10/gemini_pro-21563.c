//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key size in bytes
#define KEY_SIZE 32

// Declare the encryption and decryption functions
int encrypt(char *plaintext, char *key, char *ciphertext);
int decrypt(char *ciphertext, char *key, char *plaintext);

// Main function
int main() {
  // Declare the plaintext, key, and ciphertext variables
  char plaintext[100], key[KEY_SIZE], ciphertext[100];

  // Get the plaintext from the user
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Get the key from the user
  printf("Enter the key: ");
  gets(key);

  // Encrypt the plaintext using the key
  encrypt(plaintext, key, ciphertext);

  // Print the ciphertext
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext using the key
  decrypt(ciphertext, key, plaintext);

  // Print the plaintext
  printf("The recovered plaintext is: %s\n", plaintext);

  return 0;
}

// Encryption function
int encrypt(char *plaintext, char *key, char *ciphertext) {
  // Calculate the length of the plaintext
  int plaintext_len = strlen(plaintext);

  // Calculate the length of the key
  int key_len = strlen(key);

  // Check if the key is long enough
  if (key_len < plaintext_len) {
    return -1;
  }

  // Encrypt the plaintext using the key
  for (int i = 0; i < plaintext_len; i++) {
    ciphertext[i] = plaintext[i] ^ key[i];
  }

  // Add a null terminator to the ciphertext
  ciphertext[plaintext_len] = '\0';

  // Return 0 to indicate success
  return 0;
}

// Decryption function
int decrypt(char *ciphertext, char *key, char *plaintext) {
  // Calculate the length of the ciphertext
  int ciphertext_len = strlen(ciphertext);

  // Calculate the length of the key
  int key_len = strlen(key);

  // Check if the key is long enough
  if (key_len < ciphertext_len) {
    return -1;
  }

  // Decrypt the ciphertext using the key
  for (int i = 0; i < ciphertext_len; i++) {
    plaintext[i] = ciphertext[i] ^ key[i];
  }

  // Add a null terminator to the plaintext
  plaintext[ciphertext_len] = '\0';

  // Return 0 to indicate success
  return 0;
}