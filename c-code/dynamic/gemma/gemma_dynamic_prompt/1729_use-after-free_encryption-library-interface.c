#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *key = "Secret key";
  char *message = "This is a message";

  // Allocate memory for the encrypted message
  char *encrypted_message = malloc(strlen(message) * 2);

  // Encrypt the message
  encrypt(key, message, encrypted_message);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encrypted_message);

  // Free the memory allocated for the encrypted message
  free(encrypted_message);

  return 0;
}

void encrypt(char *key, char *message, char *encrypted_message) {
  // Calculate the length of the message
  int message_length = strlen(message);

  // Allocate memory for the encrypted message
  encrypted_message = malloc(message_length * 2);

  // Encrypt the message using a simple XOR operation
  for (int i = 0; i < message_length; i++) {
    encrypted_message[i] = message[i] ^ key[i % strlen(key)];
  }

  // Copy the encrypted message to the output
  strcpy(encrypted_message, message);
}
