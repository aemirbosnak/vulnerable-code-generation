//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for the Caesar cipher
#define KEY 3

// Function to encrypt a string using the Caesar cipher
char *caesar_encrypt(char *plaintext) {
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);
  
  // Encrypt each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] + KEY;
  }

  // Terminate the ciphertext with a null character
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string using the Caesar cipher
char *caesar_decrypt(char *ciphertext) {
  // Allocate memory for the plaintext
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Decrypt each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] - KEY;
  }

  // Terminate the plaintext with a null character
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Function to perform a bitwise XOR operation on two strings
char *bitwise_xor(char *s1, char *s2) {
  // Allocate memory for the result
  char *result = malloc(strlen(s1) + 1);

  // Perform the bitwise XOR operation on each character in the strings
  for (int i = 0; i < strlen(s1); i++) {
    result[i] = s1[i] ^ s2[i];
  }

  // Terminate the result with a null character
  result[strlen(s1)] = '\0';

  // Return the result
  return result;
}

// Main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  scanf(" %s", plaintext);

  // Encrypt the plaintext using the Caesar cipher
  char *ciphertext = caesar_encrypt(plaintext);

  // Print the ciphertext
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext using the Caesar cipher
  char *decrypted_plaintext = caesar_decrypt(ciphertext);

  // Print the decrypted plaintext
  printf("The decrypted plaintext is: %s\n", decrypted_plaintext);

  // Perform a bitwise XOR operation on the plaintext and ciphertext
  char *bitwise_xor_result = bitwise_xor(plaintext, ciphertext);

  // Print the result of the bitwise XOR operation
  printf("The result of the bitwise XOR operation is: %s\n", bitwise_xor_result);

  // Free the allocated memory
  free(ciphertext);
  free(decrypted_plaintext);
  free(bitwise_xor_result);

  return 0;
}