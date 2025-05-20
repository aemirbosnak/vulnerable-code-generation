//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_KEY_LENGTH 32

// Declare a function to encrypt a message
void encrypt_message(char *message, char *key) {
  int i, j, k;
  char temp;

  // Loop through each character of the message
  for (i = 0; i < strlen(message); i++) {
    // Calculate the ciphertext character
    temp = (message[i] + (key[i % strlen(key)] - 'A') % 26) % 26 + 'A';

    // Store the ciphertext character in the output message
    message[i] = temp;
  }
}

// Declare a function to decrypt a message
void decrypt_message(char *message, char *key) {
  int i, j, k;
  char temp;

  // Loop through each character of the message
  for (i = 0; i < strlen(message); i++) {
    // Calculate the plaintext character
    temp = (message[i] - (key[i % strlen(key)] - 'A') % 26) % 26 + 'A';

    // Store the plaintext character in the output message
    message[i] = temp;
  }
}

int main() {
  char message[MAX_MESSAGE_LENGTH];
  char key[MAX_KEY_LENGTH];
  int choice;

  // Print a menu to prompt the user to enter a message and key
  printf("Welcome to the Encryption Program!\n");
  printf("Please enter a message (up to %d characters): ", MAX_MESSAGE_LENGTH);
  fgets(message, MAX_MESSAGE_LENGTH, stdin);
  printf("Please enter a key (up to %d characters): ", MAX_KEY_LENGTH);
  fgets(key, MAX_KEY_LENGTH, stdin);

  // Prompt the user to choose an encryption or decryption operation
  printf("Do you want to encrypt or decrypt the message? (e/d): ");
  scanf(" %c", &choice);

  // Call the appropriate function based on the user's choice
  if (choice == 'e') {
    encrypt_message(message, key);
    printf("Encrypted message: %s\n", message);
  } else if (choice == 'd') {
    decrypt_message(message, key);
    printf("Decrypted message: %s\n", message);
  } else {
    printf("Invalid input. Please try again.");
  }

  return 0;
}