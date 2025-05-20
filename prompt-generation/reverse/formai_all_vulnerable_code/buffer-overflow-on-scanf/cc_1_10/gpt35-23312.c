//FormAI DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);

int main() {
  char message[MAX], choice;
  int key;

  printf("Enter a message to encrypt: ");
  fgets(message, MAX, stdin);

  printf("Enter a key: ");
  scanf("%d", &key);

  printf("\nWould you like to encrypt or decrypt the message? (e/d): ");
  getchar();
  scanf("%c", &choice);

  if (choice == 'e') {
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
  } else if (choice == 'd') {
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
  } else {
    printf("Invalid choice.\n");
    return 1;
  }

  return 0;
}

void encrypt(char *plaintext, int key) {
  int i, ch;

  for (i = 0; plaintext[i] != '\0'; ++i) {
    ch = plaintext[i];

    if (ch >= 'a' && ch <= 'z') {
      ch = (ch + key - 'a') % 26 + 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = (ch + key - 'A') % 26 + 'A';
    }

    plaintext[i] = ch;
  }
}

void decrypt(char *ciphertext, int key) {
  int i, ch;

  for (i = 0; ciphertext[i] != '\0'; ++i) {
    ch = ciphertext[i];

    if (ch >= 'a' && ch <= 'z') {
      ch = (ch - key - 'a' + 26) % 26 + 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = (ch - key - 'A' + 26) % 26 + 'A';
    }

    ciphertext[i] = ch;
  }
}