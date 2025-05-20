//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0
#define MAX 1024

void encrypt_decrypt(char *message, int mode, char *key);
void key_generator(char *key);
void brute_force(char *message);

int main()
{
  char message[MAX], key[MAX];
  int choice;

  printf("Enter your message: ");
  gets(message);

  printf("Enter your key: ");
  gets(key);

  key_generator(key);

  printf("Do you want to encrypt or decrypt? (1/0): ");
  scanf("%d", &choice);

  if (choice == ENCRYPT) {
    encrypt_decrypt(message, ENCRYPT, key);
  } else if (choice == DECRYPT) {
    encrypt_decrypt(message, DECRYPT, key);
  } else {
    printf("Invalid choice!\n");
    return EXIT_FAILURE;
  }

  printf("The encrypted/decrypted message is: %s\n", message);

  brute_force(message);

  return EXIT_SUCCESS;
}

void encrypt_decrypt(char *message, int mode, char *key)
{
  int i, j;
  char temp;

  if (mode == ENCRYPT) {
    for (i = 0; i < strlen(message); i++) {
      for (j = 0; j < strlen(key) && i+j<strlen(message); j++) {
        temp = message[i+j];
        message[i+j] = message[i+j] ^ key[j];
        key[j] = temp;
      }
    }
  } else if (mode == DECRYPT) {
    for (i = 0; i < strlen(message); i++) {
      for (j = 0; j < strlen(key) && i+j<strlen(message); j++) {
        temp = message[i+j];
        message[i+j] = message[i+j] ^ key[j];
        key[j] = temp;
      }
    }
  }
}

void key_generator(char *key)
{
  int i, j;
  for (i = 0; i < strlen(key); i++) {
    for (j = 0; j < strlen(key) && i+j<strlen(key); j++) {
      key[i+j] = rand() % 256;
    }
  }
}

void brute_force(char *message) {
  char key[MAX];
  int i, j;
  for (i = 0; i < 256; i++) {
    for (j = 0; j < strlen(message); j++) {
      key[j] = message[j] ^ i;
    }
    printf("Trying key %d: %s\n", i, key);
  }
}