//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main() {
  char message[MAX_LENGTH], operation;
  int key;
  printf("Enter a message: ");
  fgets(message, MAX_LENGTH, stdin);
  printf("Enter a key (an integer between 1 and 25): ");
  scanf("%d", &key);

  printf("Do you want to encrypt or decrypt? (Enter 'e' or 'd'): ");
  scanf(" %c", &operation);

  if (operation == 'e') {
    encrypt(message, key);
  }
  else if (operation == 'd') {
    decrypt(message, key);
  }
  else {
    printf("Invalid operation.\n");
  }
  
  return 0;
}

void encrypt(char message[], int key) {
  int i;
  for (i = 0; message[i] != '\0' && i < MAX_LENGTH; i++) {
    char c = message[i];

    if (c >= 'a' && c <= 'z') {
      c = (c - 'a' + key) % 26 + 'a';
    }
    else if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' + key) % 26 + 'A';
    }

    message[i] = c;
  }

  printf("Encrypted message: %s\n", message);
}

void decrypt(char message[], int key) {
  int i;
  for (i = 0; message[i] != '\0' && i < MAX_LENGTH; i++) {
    char c = message[i];

    if (c >= 'a' && c <= 'z') {
      c = (c - 'a' - key + 26) % 26 + 'a';
    }
    else if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' - key + 26) % 26 + 'A';
    }

    message[i] = c;
  }

  printf("Decrypted message: %s\n", message);
}