//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main() {
  char message[SIZE];
  int choice, key;

  printf("Enter a message to encrypt: ");
  fgets(message, SIZE, stdin);

  printf("Enter a key (1-25): ");
  scanf("%d", &key);

  printf("Enter 1 to encrypt or 2 to decrypt: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      encrypt(message, key);
      break;
    case 2:
      decrypt(message, key);
      break;
    default:
      printf("Invalid choice.\n");
      return 1;
  }

  printf("Encrypted/Decrypted message: %s\n", message);

  return 0;
}

void encrypt(char *message, int key) {
  int i;

  for (i = 0; message[i]!= '\0'; i++) {
    if (isalpha(message[i])) {
      message[i] = (message[i] + key - 65) % 26 + 65;
    }
  }
}

void decrypt(char *message, int key) {
  int i;

  for (i = 0; message[i]!= '\0'; i++) {
    if (isalpha(message[i])) {
      message[i] = (message[i] - key - 65) % 26 + 65;
    }
  }
}