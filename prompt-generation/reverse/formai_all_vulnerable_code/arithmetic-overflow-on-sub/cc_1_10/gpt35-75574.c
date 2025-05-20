//FormAI DATASET v1.0 Category: modern Encryption ; Style: enthusiastic
//Welcome to my dynamic C encryption program!
//This program generates a unique key to encrypt and decrypt messages

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MSG_SIZE 100

int main() {
  srand(time(NULL));
  char message[MAX_MSG_SIZE];
  int key[MAX_MSG_SIZE], encrypted[MAX_MSG_SIZE], decrypted[MAX_MSG_SIZE];
  int key_size, msg_size;

  printf("Welcome to our C encryption program! Please enter the message you would like to encrypt:\n");
  fgets(message, MAX_MSG_SIZE, stdin);

  msg_size = strlen(message);
  key_size = msg_size / 2;

  for (int i = 0; i < key_size; i++) {
    key[i] = rand() % 26; // generate random key of size `key_size`
  }

  // Encrypt the message using the generated key
  for (int i = 0; i < msg_size; i++) {
    encrypted[i] = message[i] + key[i % key_size];
  }

  // Decrypt the encrypted message using the key
  for (int i = 0; i < msg_size; i++) {
    decrypted[i] = encrypted[i] - key[i % key_size];
  }

  printf("Original message: %s\n", message);
  printf("Encrypted message: ");
  for (int i = 0; i < msg_size; i++) {
    printf("%c", encrypted[i]);
  }
  printf("\n");

  printf("Decrypted message: ");
  for (int i = 0; i < msg_size; i++) {
    printf("%c", decrypted[i]);
  }
  printf("\n");

  return 0;
}