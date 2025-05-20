//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretpassword"

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main() {
  char message[1000];
  char choice;
  printf("Welcome to the Cryptography machine!\n\n");
  printf("Please enter your message: ");
  fgets(message, 1000, stdin);

  printf("\nDo you want to encrypt or decrypt the message? (e/d): ");
  scanf(" %c", &choice);

  switch (choice) {
    case 'e':
      encrypt(message, KEY);
      break;
    case 'd':
      decrypt(message, KEY);
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  printf("\nYour message is: %s\n", message);
  return 0;
}

void encrypt(char *message, char *key) {
  int keyLen = strlen(key);
  int messageLen = strlen(message);

  for (int i = 0, j = 0; i < messageLen - 1; i++, j++) {
    if (j == keyLen) {
      j = 0;
    }
    message[i] = ((message[i] + key[j]) % 26) + 'A';
  }
}

void decrypt(char *message, char *key) {
  int keyLen = strlen(key);
  int messageLen = strlen(message);

  for (int i = 0, j = 0; i < messageLen - 1; i++, j++) {
    if (j == keyLen) {
      j = 0;
    }
    message[i] = (((message[i] - key[j]) + 26) % 26) + 'A';
  }
}