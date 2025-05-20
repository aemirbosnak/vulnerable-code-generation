//FormAI DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key) {
  int i;
  for(i = 0; message[i] != '\0'; ++i){
    if(message[i] >= 'a' && message[i] <= 'z'){
      message[i] = ((message[i] - 'a' + key) % 26) + 'a';
    }
    else if(message[i] >= 'A' && message[i] <= 'Z'){
      message[i] = ((message[i] - 'A' + key) % 26) + 'A';
    }
  }
}

void decrypt(char *message, int key) {
  int i;
  for(i = 0; message[i] != '\0'; ++i){
    if(message[i] >= 'a' && message[i] <= 'z'){
      message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
    }
    else if(message[i] >= 'A' && message[i] <= 'Z'){
      message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
    }
  }
}

int main() {
  char message[1000];
  int key, choice;

  printf("Welcome to Happy Encryption!\n");

  do {
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter message to encrypt: ");
        scanf("%*c%[^\n]s", message);
        printf("Enter key value: ");
        scanf("%d", &key);

        encrypt(message, key);

        printf("Encrypted message: %s\n", message);
        break;
      case 2:
        printf("Enter message to decrypt: ");
        scanf("%*c%[^\n]s", message);
        printf("Enter key value: ");
        scanf("%d", &key);

        decrypt(message, key);

        printf("Decrypted message: %s\n", message);
        break;
      case 3:
        printf("Thanks for using Happy Encryption!\n");
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  } while (choice != 3);

  return 0;
}