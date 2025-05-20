//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
const char *key = "This is a very secret key";

// Encrypt the given message using the given key
char *encrypt(const char *message) {
  char *encryptedMessage = malloc(strlen(message) + 1);
  for (int i = 0; i < strlen(message); i++) {
    encryptedMessage[i] = message[i] ^ key[i % strlen(key)];
  }
  encryptedMessage[strlen(message)] = '\0';
  return encryptedMessage;
}

// Decrypt the given message using the given key
char *decrypt(const char *encryptedMessage) {
  char *decryptedMessage = malloc(strlen(encryptedMessage) + 1);
  for (int i = 0; i < strlen(encryptedMessage); i++) {
    decryptedMessage[i] = encryptedMessage[i] ^ key[i % strlen(key)];
  }
  decryptedMessage[strlen(encryptedMessage)] = '\0';
  return decryptedMessage;
}

int main() {
  // Get the message from the user
  char message[100];
  printf("Enter the message you want to encrypt: ");
  scanf("%s", message);

  // Encrypt the message
  char *encryptedMessage = encrypt(message);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypt the encrypted message
  char *decryptedMessage = decrypt(encryptedMessage);

  // Print the decrypted message
  printf("Decrypted message: %s\n", decryptedMessage);

  // Free the allocated memory
  free(encryptedMessage);
  free(decryptedMessage);

  return 0;
}