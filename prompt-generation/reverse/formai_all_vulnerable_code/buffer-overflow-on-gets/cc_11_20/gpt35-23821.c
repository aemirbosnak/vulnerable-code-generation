//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
  char message[100];
  int key, choice, i;

  printf("Welcome to the Brave Encryption Program!\n\n");
  printf("Enter a message to encrypt: ");
  gets(message);

  printf("\nEnter a key value (1-26): ");
  scanf("%d", &key);

  printf("\nSelect an encryption method:\n");
  printf("1. Caesar Cipher\n");
  printf("2. Multiplicative Cipher\n");
  printf("3. Affine Cipher\n");
  printf("\nEnter your choice (1-3): ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      // Caesar Cipher
      for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
          message[i] = (message[i] + key - 'a') % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
          message[i] = (message[i] + key - 'A') % 26 + 'A';
        }
      }
      printf("\nEncrypted message: %s\n", message);
      break;

    case 2:
      // Multiplicative Cipher
      for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
          message[i] = ((message[i] - 'a') * key) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
          message[i] = ((message[i] - 'A') * key) % 26 + 'A';
        }
      }
      printf("\nEncrypted message: %s\n", message);
      break;

    case 3:
      // Affine Cipher
      for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
          message[i] = ((message[i] - 'a') * key + 5) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
          message[i] = ((message[i] - 'A') * key + 5) % 26 + 'A';
        }
      }
      printf("\nEncrypted message: %s\n", message);
      break;

    default:
      printf("\nInvalid choice. Please try again.\n");
      exit(0);
  }

  return 0;
}