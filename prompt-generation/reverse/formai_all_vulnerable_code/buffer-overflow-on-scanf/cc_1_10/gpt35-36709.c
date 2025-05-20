//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main() {
  char message[1000];
  int key;
  int choice;
  
  printf("Enter your message: ");
  fgets(message, sizeof(message), stdin);

  printf("Enter the key value (1-25): ");
  scanf("%d", &key);

  printf("Enter 1 to encrypt or 2 to decrypt: ");
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
      printf("Invalid choice. Program terminating...");
      exit(0);
  }

  return 0;
}

void encrypt(char* message, int key) {
  int i;

  for(i = 0; i < strlen(message); i++) {
    if(message[i] >= 'a' && message[i] <= 'z') {
      message[i] = (((message[i] - 'a') + key) % 26) + 'a';
    }
    else if(message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = (((message[i] - 'A') + key) % 26) + 'A';
    }
  }
}

void decrypt(char* message, int key) {
  int i;

  for(i = 0; i < strlen(message); i++) {
    if(message[i] >= 'a' && message[i] <= 'z') {
      message[i] = (((message[i] - 'a') - key + 26) % 26) + 'a';
    }
    else if(message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = (((message[i] - 'A') - key + 26) % 26) + 'A';
    }
  }
}