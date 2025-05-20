//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the alphabet and its size
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABET_SIZE 26

// Define the encryption and decryption keys
int encryption_key = 3;
int decryption_key = 21;

// Function to encrypt a single character
char encrypt_char(char c) {
  // Check if the character is in the alphabet
  if (strchr(ALPHABET, c) == NULL) {
    return c;
  }

  // Calculate the encrypted character
  int encrypted_char_index = (c - 'A' + encryption_key) % ALPHABET_SIZE;
  char encrypted_char = ALPHABET[encrypted_char_index];

  return encrypted_char;
}

// Function to decrypt a single character
char decrypt_char(char c) {
  // Check if the character is in the alphabet
  if (strchr(ALPHABET, c) == NULL) {
    return c;
  }

  // Calculate the decrypted character
  int decrypted_char_index = (c - 'A' - decryption_key) % ALPHABET_SIZE;
  char decrypted_char = ALPHABET[decrypted_char_index];

  return decrypted_char;
}

// Function to encrypt a string
char *encrypt_string(char *str) {
  // Allocate memory for the encrypted string
  char *encrypted_str = malloc(strlen(str) + 1);

  // Encrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    encrypted_str[i] = encrypt_char(str[i]);
  }

  // Null-terminate the encrypted string
  encrypted_str[strlen(str)] = '\0';

  return encrypted_str;
}

// Function to decrypt a string
char *decrypt_string(char *str) {
  // Allocate memory for the decrypted string
  char *decrypted_str = malloc(strlen(str) + 1);

  // Decrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    decrypted_str[i] = decrypt_char(str[i]);
  }

  // Null-terminate the decrypted string
  decrypted_str[strlen(str)] = '\0';

  return decrypted_str;
}

// Main function
int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter the string to encrypt: ");
  scanf("%s", str);

  // Encrypt the string
  char *encrypted_str = encrypt_string(str);

  // Print the encrypted string
  printf("Encrypted string: %s\n", encrypted_str);

  // Decrypt the string
  char *decrypted_str = decrypt_string(encrypted_str);

  // Print the decrypted string
  printf("Decrypted string: %s\n", decrypted_str);

  // Free the allocated memory
  free(encrypted_str);
  free(decrypted_str);

  return 0;
}