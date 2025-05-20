//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main() {
  // Get the plaintext and key from the user
  char plaintext[100], key[100];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);
  printf("Enter the key: ");
  scanf("%s", key);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext, key);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decryptedtext = decrypt(ciphertext, key);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedtext);

  return 0;
}

// Encrypt the plaintext using the key
char *encrypt(char *plaintext, char *key) {
  int plaintext_length = strlen(plaintext);
  int key_length = strlen(key);

  // Create a ciphertext buffer
  char *ciphertext = malloc(plaintext_length + 1);
  memset(ciphertext, 0, plaintext_length + 1);

  // Encrypt each character of the plaintext
  for (int i = 0; i < plaintext_length; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % key_length];
  }

  return ciphertext;
}

// Decrypt the ciphertext using the key
char *decrypt(char *ciphertext, char *key) {
  int ciphertext_length = strlen(ciphertext);
  int key_length = strlen(key);

  // Create a decrypted text buffer
  char *decryptedtext = malloc(ciphertext_length + 1);
  memset(decryptedtext, 0, ciphertext_length + 1);

  // Decrypt each character of the ciphertext
  for (int i = 0; i < ciphertext_length; i++) {
    decryptedtext[i] = ciphertext[i] ^ key[i % key_length];
  }

  return decryptedtext;
}