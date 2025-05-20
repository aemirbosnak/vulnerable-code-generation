//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Romeo and Juliet cipher key
const char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// Function to encrypt a message using the Romeo and Juliet cipher
char *encrypt(char *message) {
  // Allocate memory for the encrypted message
  char *encryptedMessage = malloc(strlen(message) + 1);

  // Loop through each character in the message
  for (int i = 0; i < strlen(message); i++) {
    // Find the index of the character in the key
    int index = strchr(key, message[i]) - key;

    // If the character is not found in the key, leave it unchanged
    if (index == -1) {
      encryptedMessage[i] = message[i];
    }
    // Otherwise, replace the character with the corresponding character in the key
    else {
      encryptedMessage[i] = key[(index + 13) % 52];
    }
  }

  // Terminate the encrypted message with a null character
  encryptedMessage[strlen(message)] = '\0';

  // Return the encrypted message
  return encryptedMessage;
}

// Function to decrypt a message using the Romeo and Juliet cipher
char *decrypt(char *message) {
  // Allocate memory for the decrypted message
  char *decryptedMessage = malloc(strlen(message) + 1);

  // Loop through each character in the message
  for (int i = 0; i < strlen(message); i++) {
    // Find the index of the character in the key
    int index = strchr(key, message[i]) - key;

    // If the character is not found in the key, leave it unchanged
    if (index == -1) {
      decryptedMessage[i] = message[i];
    }
    // Otherwise, replace the character with the corresponding character in the key
    else {
      decryptedMessage[i] = key[(index - 13) % 52];
    }
  }

  // Terminate the decrypted message with a null character
  decryptedMessage[strlen(message)] = '\0';

  // Return the decrypted message
  return decryptedMessage;
}

// Main function
int main() {
  // Get the message to be encrypted from the user
  char message[100];
  printf("Enter the message to be encrypted: ");
  gets(message);

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