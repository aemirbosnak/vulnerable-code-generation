//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Our super secret encryption key: the ASCII code for 'p'
#define KEY 112

// Function to encrypt a single character
char encrypt(char c) {
  return c ^ KEY; // XOR the character with the key
}

// Function to encrypt a string
char* encrypt_string(char* str) {
  // Allocate memory for the encrypted string
  char* encrypted_str = malloc(strlen(str) + 1);

  // Encrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    encrypted_str[i] = encrypt(str[i]);
  }

  // Null-terminate the encrypted string
  encrypted_str[strlen(str)] = '\0';

  // Return the encrypted string
  return encrypted_str;
}

// Function to decrypt a string
char* decrypt_string(char* str) {
  // Allocate memory for the decrypted string
  char* decrypted_str = malloc(strlen(str) + 1);

  // Decrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    decrypted_str[i] = encrypt(str[i]);
  }

  // Null-terminate the decrypted string
  decrypted_str[strlen(str)] = '\0';

  // Return the decrypted string
  return decrypted_str;
}

// Main function
int main() {
  // Get the string to be encrypted from the user
  printf("Enter the string to be encrypted: ");
  char* str = malloc(100);
  scanf("%s", str);

  // Encrypt the string
  char* encrypted_str = encrypt_string(str);

  // Print the encrypted string
  printf("Encrypted string: %s\n", encrypted_str);

  // Decrypt the string
  char* decrypted_str = decrypt_string(encrypted_str);

  // Print the decrypted string
  printf("Decrypted string: %s\n", decrypted_str);

  // Free the allocated memory
  free(str);
  free(encrypted_str);
  free(decrypted_str);

  return 0;
}