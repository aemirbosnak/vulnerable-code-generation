//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ROT13 encryption/decryption */
void rot13(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = ((str[i] - 'A') + 13) % 26 + 'A';
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = ((str[i] - 'a') + 13) % 26 + 'a';
    }
  }
}

/* Vigenere encryption/decryption */
void vigenere(char *plaintext, char *key, char *ciphertext) {
  int i, j, k;
  k = 0;
  for (i = 0; plaintext[i] != '\0'; i++) {
    if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
      ciphertext[i] = ((plaintext[i] - 'A') + (key[k] - 'A')) % 26 + 'A';
      k = (k + 1) % strlen(key);
    } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
      ciphertext[i] = ((plaintext[i] - 'a') + (key[k] - 'a')) % 26 + 'a';
      k = (k + 1) % strlen(key);
    } else {
      ciphertext[i] = plaintext[i];
    }
  }
  ciphertext[i] = '\0';
}

/* Main program */
int main() {
  char plaintext[100], ciphertext[100], key[100];
  int choice;

  printf("Welcome to the Retro Cryptography Machine!\n");
  printf("1. ROT13 Encryption/Decryption\n");
  printf("2. Vigenere Encryption/Decryption\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the plaintext: ");
      scanf(" %[^\n]", plaintext);
      rot13(plaintext);
      printf("Ciphertext: %s\n", plaintext);
      break;
    case 2:
      printf("Enter the plaintext: ");
      scanf(" %[^\n]", plaintext);
      printf("Enter the key: ");
      scanf(" %[^\n]", key);
      vigenere(plaintext, key, ciphertext);
      printf("Ciphertext: %s\n", ciphertext);
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}