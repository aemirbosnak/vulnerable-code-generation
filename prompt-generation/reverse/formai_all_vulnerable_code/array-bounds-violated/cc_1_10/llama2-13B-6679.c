//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 50
#define MAX_KEY_LENGTH 20

// Gratitude-themed constant definitions
#define GRATITUDE_KEY "THANK_YOU_FOR_TRUSTING_ME_WITH_YOUR_SECRETS"
#define GRATITUDE_MESSAGE "YOU_ARE_AMAZING_AND_I_AM_GRATEFUL_FOR_YOUR_LOVE"

int main() {
  // Gratitude-themed variable definitions
  char message[MAX_MESSAGE_LENGTH];
  char key[MAX_KEY_LENGTH];

  // Ask the user for the message and key
  printf("Please enter a message (max %d characters): ", MAX_MESSAGE_LENGTH);
  fgets(message, MAX_MESSAGE_LENGTH, stdin);

  printf("Please enter a key (max %d characters): ", MAX_KEY_LENGTH);
  fgets(key, MAX_KEY_LENGTH, stdin);

  // Encrypt the message
  for (int i = 0; i < strlen(message); i++) {
    // Calculate the corresponding character in the key
    int key_index = (int)strchr(key, message[i]) - message[i];

    // If the key index is negative, the character is not in the key
    if (key_index < 0) {
      message[i] = message[i] ^ GRATITUDE_KEY[key_index + strlen(GRATITUDE_KEY)];
    } else {
      message[i] = message[i] ^ GRATITUDE_KEY[key_index];
    }
  }

  // Print the encrypted message
  printf("Encrypted message: %s\n", message);

  // Decrypt the message (just for fun)
  for (int i = 0; i < strlen(message); i++) {
    // Calculate the corresponding character in the key
    int key_index = (int)strchr(key, message[i]) - message[i];

    // If the key index is negative, the character is not in the key
    if (key_index < 0) {
      message[i] = message[i] ^ GRATITUDE_KEY[key_index + strlen(GRATITUDE_KEY)];
    } else {
      message[i] = message[i] ^ GRATITUDE_KEY[key_index];
    }
  }

  printf("Decrypted message: %s\n", message);

  return 0;
}