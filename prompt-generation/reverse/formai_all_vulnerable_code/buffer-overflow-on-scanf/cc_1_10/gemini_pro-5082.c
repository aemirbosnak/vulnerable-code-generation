//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define KEY "mysecretkey"

// Define the encryption function.
char *encrypt(char *plaintext) {
  // Get the length of the plaintext.
  int len = strlen(plaintext);

  // Allocate memory for the ciphertext.
  char *ciphertext = malloc(len + 1);

  // Copy the plaintext into the ciphertext.
  strcpy(ciphertext, plaintext);

  // Encrypt the ciphertext using the XOR operation.
  for (int i = 0; i < len; i++) {
    ciphertext[i] ^= KEY[i % strlen(KEY)];
  }

  // Return the ciphertext.
  return ciphertext;
}

// Define the decryption function.
char *decrypt(char *ciphertext) {
  // Get the length of the ciphertext.
  int len = strlen(ciphertext);

  // Allocate memory for the plaintext.
  char *plaintext = malloc(len + 1);

  // Copy the ciphertext into the plaintext.
  strcpy(plaintext, ciphertext);

  // Decrypt the plaintext using the XOR operation.
  for (int i = 0; i < len; i++) {
    plaintext[i] ^= KEY[i % strlen(KEY)];
  }

  // Return the plaintext.
  return plaintext;
}

// Get the input from the user.
char *get_input() {
  // Allocate memory for the input.
  char *input = malloc(1024);

  // Get the input from the user.
  printf("Enter the text to encrypt: ");
  scanf("%s", input);

  // Return the input.
  return input;
}

// Print the output to the user.
void print_output(char *output) {
  // Print the output to the user.
  printf("The encrypted text is: %s\n", output);
}

// Main function.
int main() {
  // Get the input from the user.
  char *input = get_input();

  // Encrypt the input.
  char *ciphertext = encrypt(input);

  // Print the output to the user.
  print_output(ciphertext);

  // Decrypt the ciphertext.
  char *plaintext = decrypt(ciphertext);

  // Print the plaintext to the user.
  printf("The decrypted text is: %s\n", plaintext);

  // Free the allocated memory.
  free(input);
  free(ciphertext);
  free(plaintext);

  // Return 0 to indicate success.
  return 0;
}