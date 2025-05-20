//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "This is a secret key"

// Encrypt a string using the XOR cipher
char *xor_encrypt(char *plaintext) {
  int key_len = strlen(KEY);
  char *ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ KEY[i % key_len];
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

// Decrypt a string using the XOR cipher
char *xor_decrypt(char *ciphertext) {
  int key_len = strlen(KEY);
  char *plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ KEY[i % key_len];
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

// Print a string in a mind-bending style
void print_mind_bending(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    printf("%c", str[i] ^ ' ');
  }
  printf("\n");
}

int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Encrypt the plaintext using the XOR cipher
  char *ciphertext = xor_encrypt(plaintext);

  // Print the ciphertext in a mind-bending style
  printf("Ciphertext: ");
  print_mind_bending(ciphertext);

  // Decrypt the ciphertext using the XOR cipher
  char *decrypted_plaintext = xor_decrypt(ciphertext);

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}