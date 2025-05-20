//FormAI DATASET v1.0 Category: modern Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to encrypt message
void encrypt(char message[], int key) {
  int i;
  for(i = 0; message[i] != '\0'; ++i) {
    if(message[i] >= 'a' && message[i] <= 'z') {
      message[i] = ((message[i] - 'a') + key) % 26 + 'a';
    }
    else if(message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = ((message[i] - 'A') + key) % 26 + 'A';
    }
  }
}

// Function to decrypt message
void decrypt(char message[], int key) {
  int i;
  for(i = 0; message[i] != '\0'; ++i) {
    if(message[i] >= 'a' && message[i] <= 'z') {
      message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
    }
    else if(message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
    }
  }
}

int main() {
  char message[100];
  int key, choice;

  printf("Enter the message: ");
  fgets(message, sizeof(message), stdin);

  printf("Enter the key: ");
  scanf("%d", &key);

  printf("Enter your choice:\n");
  printf("1. Encrypt message\n");
  printf("2. Decrypt message\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      encrypt(message, key);
      printf("Encrypted message: %s", message);
      break;
    case 2:
      decrypt(message, key);
      printf("Decrypted message: %s", message);
      break;
    default:
      printf("Invalid choice");
  }

  return 0;
}