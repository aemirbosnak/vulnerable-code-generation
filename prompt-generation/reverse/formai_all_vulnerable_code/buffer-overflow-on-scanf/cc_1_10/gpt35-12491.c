//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

void encrypt(char input[], int key);
void decrypt(char input[], int key);

int main() {
  char input[MAX_LENGTH];
  int key;
  int choice;

  printf("Welcome to the Cryptography Program!\n");
  printf("1. Encrypt\n2. Decrypt\n");
  printf("Please select an option: ");
  scanf("%d", &choice);
  printf("\nEnter your message: ");
  scanf(" %[^\n]%*c", input);

  if (choice == 1) {
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    encrypt(input, key);
    printf("Encrypted message: %s\n", input);
  } else if (choice == 2) {
    printf("Enter the decryption key: ");
    scanf("%d", &key);
    decrypt(input, key);
    printf("Decrypted message: %s\n", input);
  } else {
    printf("Invalid choice. Please try again.\n");
  }

  return 0;
}

void encrypt(char input[], int key) {
  int length = strlen(input);

  for (int i = 0; i < length; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      input[i] = ((input[i] - 'a') + key) % 26 + 'a';
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] = ((input[i] - 'A') + key) % 26 + 'A';
    }
  }
}

void decrypt(char input[], int key) {
  int length = strlen(input);

  for (int i = 0; i < length; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      input[i] = ((input[i] - 'a') - key + 26) % 26 + 'a';
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] = ((input[i] - 'A') - key + 26) % 26 + 'A';
    }
  }
}