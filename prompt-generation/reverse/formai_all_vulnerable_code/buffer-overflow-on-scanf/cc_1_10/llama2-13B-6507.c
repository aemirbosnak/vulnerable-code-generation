//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 20

// Function to encrypt a message using a Caesar cipher
void encrypt_message(char *message, int key) {
  int i, j;
  char c, d;

  // Shift the message by the given key
  for (i = 0; i < strlen(message); i++) {
    c = message[i];
    d = (c + key) % 26;
    message[i] = d;
  }
}

// Function to decrypt a message using a Caesar cipher
void decrypt_message(char *message, int key) {
  int i, j;
  char c, d;

  // Shift the message by the given key in reverse
  for (i = strlen(message) - 1; i >= 0; i--) {
    c = message[i];
    d = (c - key) % 26;
    message[i] = d;
  }
}

int main() {
  // Get the message and key from the user
  char message[MAX_MESSAGE_LENGTH];
  int key;
  printf("Enter a message: ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);
  printf("Enter a key: ");
  scanf("%d", &key);

  // Encrypt the message
  encrypt_message(message, key);

  // Print the encrypted message
  printf("Encrypted message: %s\n", message);

  // Decrypt the message
  decrypt_message(message, key);

  // Print the decrypted message
  printf("Decrypted message: %s\n", message);

  return 0;
}