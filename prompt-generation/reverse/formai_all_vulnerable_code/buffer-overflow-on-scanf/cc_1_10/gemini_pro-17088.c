//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function
char* encrypt(char* plaintext, int key) {
  char* ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; plaintext[i] != '\0'; i++) {
    ciphertext[i] = plaintext[i] + key;
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

// Custom decryption function
char* decrypt(char* ciphertext, int key) {
  char* plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; ciphertext[i] != '\0'; i++) {
    plaintext[i] = ciphertext[i] - key;
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

// Introspective function that analyzes and describes its own functionality
void introspect() {
  printf("\n**Introspection:**\n");
  printf("This program provides custom encryption and decryption functions.\n");
  printf("The encryption function takes a plaintext string and a key as input, and returns an encrypted ciphertext string.\n");
  printf("The decryption function takes an encrypted ciphertext string and a key as input, and returns the original plaintext string.\n");
  printf("Both functions use a simple additive cipher, where each character in the input string is shifted by the specified key.\n");
  printf("For example, if the plaintext is 'hello' and the key is 3, the ciphertext will be 'khoor'.\n\n");
}

int main() {
  // Introspection
  introspect();

  // Get plaintext and key from user
  char plaintext[100];
  int key;
  printf("Enter plaintext: ");
  scanf("%s", plaintext);
  printf("Enter key (0-25): ");
  scanf("%d", &key);

  // Encrypt and decrypt the plaintext using the specified key
  char* ciphertext = encrypt(plaintext, key);
  char* decryptedtext = decrypt(ciphertext, key);

  // Print the results
  printf("\nPlaintext: %s\n", plaintext);
  printf("Key: %d\n", key);
  printf("Ciphertext: %s\n", ciphertext);
  printf("Decrypted text: %s\n", decryptedtext);

  // Free allocated memory
  free(ciphertext);
  free(decryptedtext);

  return 0;
}