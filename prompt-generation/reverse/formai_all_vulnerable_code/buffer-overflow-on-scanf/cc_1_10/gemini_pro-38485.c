//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A secret key for our super-secret algorithm
#define KEY "I'm a little teapot, short and stout!"

// Function to encrypt a string using our super-secret algorithm
char *encrypt(char *plaintext) {
  // Allocate memory for the encrypted string
  char *ciphertext = malloc(strlen(plaintext) + 1);
  if (ciphertext == NULL) {
    // Oops, we couldn't allocate memory!
    printf("Sorry, I can't encrypt that string right now. My memory is a bit short!\n");
    return NULL;
  }

  // Encrypt the string one character at a time
  for (int i = 0; i < strlen(plaintext); i++) {
    // XOR each character with the secret key
    ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
  }

  // Null-terminate the encrypted string
  ciphertext[strlen(plaintext)] = '\0';

  // Return the encrypted string
  return ciphertext;
}

// Function to decrypt a string using our super-secret algorithm
char *decrypt(char *ciphertext) {
  // Allocate memory for the decrypted string
  char *plaintext = malloc(strlen(ciphertext) + 1);
  if (plaintext == NULL) {
    // Oops, we couldn't allocate memory!
    printf("Sorry, I can't decrypt that string right now. My memory is a bit short!\n");
    return NULL;
  }

  // Decrypt the string one character at a time
  for (int i = 0; i < strlen(ciphertext); i++) {
    // XOR each character with the secret key
    plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
  }

  // Null-terminate the decrypted string
  plaintext[strlen(ciphertext)] = '\0';

  // Return the decrypted string
  return plaintext;
}

// Function to get a string from the user
char *get_string() {
  // Allocate memory for the string
  char *string = malloc(100);
  if (string == NULL) {
    // Oops, we couldn't allocate memory!
    printf("Sorry, I can't get that string right now. My memory is a bit short!\n");
    return NULL;
  }

  // Get the string from the user
  printf("Enter a string to encrypt: ");
  scanf("%s", string);

  // Return the string
  return string;
}

// Main function
int main() {
  // Get a string from the user
  char *plaintext = get_string();
  if (plaintext == NULL) {
    return 1;
  }

  // Encrypt the string
  char *ciphertext = encrypt(plaintext);
  if (ciphertext == NULL) {
    free(plaintext);
    return 1;
  }

  // Print the encrypted string
  printf("Encrypted string: %s\n", ciphertext);

  // Decrypt the string
  char *decryptedtext = decrypt(ciphertext);
  if (decryptedtext == NULL) {
    free(plaintext);
    free(ciphertext);
    return 1;
  }

  // Print the decrypted string
  printf("Decrypted string: %s\n", decryptedtext);

  // Free the memory allocated for the strings
  free(plaintext);
  free(ciphertext);
  free(decryptedtext);

  return 0;
}