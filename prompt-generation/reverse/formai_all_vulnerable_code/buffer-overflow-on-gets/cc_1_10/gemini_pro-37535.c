//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Declare the encryption and decryption functions
char *encrypt(char *plaintext, int key);
char *decrypt(char *ciphertext, int key);

// Define the main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Get the encryption key from the user
  int key;
  printf("Enter the encryption key: ");
  scanf("%d", &key);

  // Encrypt the plaintext using the encryption function
  char *ciphertext = encrypt(plaintext, key);

  // Print the ciphertext to the console
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext using the decryption function
  char *decryptedtext = decrypt(ciphertext, key);

  // Print the decrypted text to the console
  printf("The decrypted text is: %s\n", decryptedtext);

  return 0;
}

// Define the encryption function
char *encrypt(char *plaintext, int key) {
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] + key;
  }

  // Terminate the ciphertext with a null character
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext, int key) {
  // Allocate memory for the decrypted text
  char *decryptedtext = malloc(strlen(ciphertext) + 1);

  // Decrypt each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    decryptedtext[i] = ciphertext[i] - key;
  }

  // Terminate the decrypted text with a null character
  decryptedtext[strlen(ciphertext)] = '\0';

  // Return the decrypted text
  return decryptedtext;
}