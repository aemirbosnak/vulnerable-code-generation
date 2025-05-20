//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the encryption and decryption functions
char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

// Define the main function
int main() {
  // Prompt the user to enter the plaintext and key
  printf("Enter the plaintext: ");
  char plaintext[100];
  scanf("%s", plaintext);

  printf("Enter the key: ");
  char key[100];
  scanf("%s", key);

  // Encrypt the plaintext using the key
  char *ciphertext = encrypt(plaintext, key);

  // Print the ciphertext
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext using the key
  char *decryptedtext = decrypt(ciphertext, key);

  // Print the decrypted text
  printf("The decrypted text is: %s\n", decryptedtext);

  return 0;
}

// Define the encryption function
char *encrypt(char *plaintext, char *key) {
  // Get the length of the plaintext and key
  int plaintextLength = strlen(plaintext);
  int keyLength = strlen(key);

  // Create a buffer for the ciphertext
  char *ciphertext = malloc(plaintextLength + 1);

  // Encrypt the plaintext using the key
  for (int i = 0; i < plaintextLength; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % keyLength];
  }

  // Add a null terminator to the end of the ciphertext
  ciphertext[plaintextLength] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext, char *key) {
  // Get the length of the ciphertext and key
  int ciphertextLength = strlen(ciphertext);
  int keyLength = strlen(key);

  // Create a buffer for the decrypted text
  char *decryptedtext = malloc(ciphertextLength + 1);

  // Decrypt the ciphertext using the key
  for (int i = 0; i < ciphertextLength; i++) {
    decryptedtext[i] = ciphertext[i] ^ key[i % keyLength];
  }

  // Add a null terminator to the end of the decrypted text
  decryptedtext[ciphertextLength] = '\0';

  // Return the decrypted text
  return decryptedtext;
}