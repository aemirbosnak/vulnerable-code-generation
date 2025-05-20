//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_KEY_LENGTH 32

// Function to encrypt a message using a Caesar Cipher
void encrypt_message(char *message, int key) {
  int i, j;
  char c;

  // Loop through each character in the message
  for (i = 0; message[i] != '\0'; i++) {
    // Check if the character is a letter (lowercase or uppercase)
    if (isalpha(message[i])) {
      // Calculate the shifted character
      c = (message[i] + key) % 26;

      // If the shifted character is outside the range of 'a' to 'z',
      // wrap around to the beginning of the alphabet
      if (c < 'a') {
        c += 26;
      }

      // Replace the original character with the shifted character
      message[i] = c;
    }
  }
}

int main() {
  // Declare variables to store the message and key
  char message[MAX_MESSAGE_LENGTH];
  int key;

  // Ask the user for the message and key
  printf("Enter a message: ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);
  printf("Enter a key (1-26): ");
  scanf("%d", &key);

  // Encrypt the message using the Caesar Cipher
  encrypt_message(message, key);

  // Print the encrypted message
  printf("Encrypted message: %s\n", message);

  return 0;
}