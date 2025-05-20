//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: synchronous
/*
 * Unique C Encryption Program
 *
 * This program takes a string as input and encrypts it using a simple substitution cipher.
 * The substitution is performed by replacing each letter with the letter that is 'n' positions
 * ahead of it in the alphabet, where 'n' is a user-defined key.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a substitution cipher
char *encrypt(char *input, int key) {
  // Create a new string to hold the encrypted text
  char *output = malloc(strlen(input) + 1);

  // Loop through each character in the input string
  for (int i = 0; i < strlen(input); i++) {
    // Get the current character and its position in the alphabet
    char c = input[i];
    int pos = c - 'A';

    // Perform the substitution
    int new_pos = (pos + key) % 26;
    char new_c = 'A' + new_pos;

    // Add the new character to the output string
    output[i] = new_c;
  }

  // Add a null terminator to the end of the output string
  output[strlen(input)] = '\0';

  // Return the encrypted string
  return output;
}

// Function to decrypt a string using a substitution cipher
char *decrypt(char *input, int key) {
  // Create a new string to hold the decrypted text
  char *output = malloc(strlen(input) + 1);

  // Loop through each character in the input string
  for (int i = 0; i < strlen(input); i++) {
    // Get the current character and its position in the alphabet
    char c = input[i];
    int pos = c - 'A';

    // Perform the substitution
    int new_pos = (pos - key + 26) % 26;
    char new_c = 'A' + new_pos;

    // Add the new character to the output string
    output[i] = new_c;
  }

  // Add a null terminator to the end of the output string
  output[strlen(input)] = '\0';

  // Return the decrypted string
  return output;
}

int main() {
  // Get the input string from the user
  char *input = malloc(100);
  printf("Enter a string to encrypt: ");
  fgets(input, 100, stdin);

  // Get the encryption key from the user
  int key;
  printf("Enter the encryption key: ");
  scanf("%d", &key);

  // Encrypt the input string using the given key
  char *encrypted = encrypt(input, key);

  // Print the encrypted string
  printf("Encrypted string: %s\n", encrypted);

  // Decrypt the encrypted string using the given key
  char *decrypted = decrypt(encrypted, key);

  // Print the decrypted string
  printf("Decrypted string: %s\n", decrypted);

  // Free the memory allocated for the input and output strings
  free(input);
  free(encrypted);
  free(decrypted);

  return 0;
}