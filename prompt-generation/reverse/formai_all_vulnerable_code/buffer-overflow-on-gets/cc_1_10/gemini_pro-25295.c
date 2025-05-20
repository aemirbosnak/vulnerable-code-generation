//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "ThisIsNotASecretKey"

void encrypt(char* plaintext, char* ciphertext) {
  // Initialize the variables.
  int i, key_len = strlen(KEY);
  
  // Loop through the plaintext and encrypt each character using the key.
  for (i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ KEY[i % key_len];
  }
  
  // Add a null-terminator to the ciphertext.
  ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char* ciphertext, char* plaintext) {
  // Initialize the variables.
  int i, key_len = strlen(KEY);
  
  // Loop through the ciphertext and decrypt each character using the key.
  for (i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ KEY[i % key_len];
  }
  
  // Add a null-terminator to the plaintext.
  plaintext[strlen(ciphertext)] = '\0';
}

int main() {
  // Get the plaintext from the user.
  char plaintext[100];
  printf("Enter the plaintext: ");
  gets(plaintext);
  
  // Encrypt the plaintext.
  char ciphertext[100];
  encrypt(plaintext, ciphertext);
  
  // Print the ciphertext.
  printf("The ciphertext is: %s\n", ciphertext);
  
  // Decrypt the ciphertext.
  decrypt(ciphertext, plaintext);
  
  // Print the decrypted plaintext.
  printf("The decrypted plaintext is: %s\n", plaintext);
  return 0;
}