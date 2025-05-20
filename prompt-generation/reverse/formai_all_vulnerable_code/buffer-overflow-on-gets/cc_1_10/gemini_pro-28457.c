//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character
char encrypt(char c, char key) {
  return (c + key) % 256;
}

// Function to decrypt a character
char decrypt(char c, char key) {
  return (c - key) % 256;
}

// Function to encrypt a string
void encrypt_string(char *str, char *key) {
  int len = strlen(str);
  int keylen = strlen(key);

  for (int i = 0; i < len; i++) {
    str[i] = encrypt(str[i], key[i % keylen]);
  }
}

// Function to decrypt a string
void decrypt_string(char *str, char *key) {
  int len = strlen(str);
  int keylen = strlen(key);

  for (int i = 0; i < len; i++) {
    str[i] = decrypt(str[i], key[i % keylen]);
  }
}

// Main function
int main() {
  // Declare variables
  char plaintext[100], ciphertext[100], key[100];

  // Get the plaintext from the user
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Get the key from the user
  printf("Enter the key: ");
  gets(key);

  // Encrypt the string
  encrypt_string(plaintext, key);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  decrypt_string(ciphertext, key);

  // Print the plaintext
  printf("Plaintext: %s\n", plaintext);

  return 0;
}