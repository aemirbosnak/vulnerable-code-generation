//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to encrypt a string using the Caesar cipher
char *caesar_encrypt(char *str, int key) {
  // Base case: if the string is empty, return an empty string
  if (strlen(str) == 0) {
    return "";
  }

  // Recursive case: apply the Caesar cipher to the first character of the string and the rest of the string
  char first_char = str[0];
  char *rest_of_str = str + 1;

  // Shift the character by the given key
  if (first_char >= 'a' && first_char <= 'z') {
    first_char = (first_char - 'a' + key) % 26 + 'a';
  } else if (first_char >= 'A' && first_char <= 'Z') {
    first_char = (first_char - 'A' + key) % 26 + 'A';
  }

  // Recursively encrypt the rest of the string
  char *rest_of_encrypted_str = caesar_encrypt(rest_of_str, key);

  // Concatenate the encrypted first character and the encrypted rest of the string
  char *encrypted_str = (char *)malloc(strlen(str) + 1);
  encrypted_str[0] = first_char;
  strcpy(encrypted_str + 1, rest_of_encrypted_str);

  // Return the encrypted string
  return encrypted_str;
}

// Recursive function to decrypt a string using the Caesar cipher
char *caesar_decrypt(char *str, int key) {
  // Base case: if the string is empty, return an empty string
  if (strlen(str) == 0) {
    return "";
  }

  // Recursive case: apply the Caesar cipher to the first character of the string and the rest of the string
  char first_char = str[0];
  char *rest_of_str = str + 1;

  // Shift the character by the given key in the opposite direction
  if (first_char >= 'a' && first_char <= 'z') {
    first_char = (first_char - 'a' - key + 26) % 26 + 'a';
  } else if (first_char >= 'A' && first_char <= 'Z') {
    first_char = (first_char - 'A' - key + 26) % 26 + 'A';
  }

  // Recursively decrypt the rest of the string
  char *rest_of_decrypted_str = caesar_decrypt(rest_of_str, key);

  // Concatenate the decrypted first character and the decrypted rest of the string
  char *decrypted_str = (char *)malloc(strlen(str) + 1);
  decrypted_str[0] = first_char;
  strcpy(decrypted_str + 1, rest_of_decrypted_str);

  // Return the decrypted string
  return decrypted_str;
}

int main() {
  // Get the input string from the user
  char *input_str = (char *)malloc(100);
  printf("Enter a string to encrypt: ");
  scanf("%s", input_str);

  // Get the encryption key from the user
  int key;
  printf("Enter the encryption key: ");
  scanf("%d", &key);

  // Encrypt the input string using the Caesar cipher
  char *encrypted_str = caesar_encrypt(input_str, key);

  // Print the encrypted string
  printf("Encrypted string: %s\n", encrypted_str);

  // Decrypt the encrypted string using the Caesar cipher
  char *decrypted_str = caesar_decrypt(encrypted_str, key);

  // Print the decrypted string
  printf("Decrypted string: %s\n", decrypted_str);

  // Free the allocated memory
  free(input_str);
  free(encrypted_str);
  free(decrypted_str);

  return 0;
}