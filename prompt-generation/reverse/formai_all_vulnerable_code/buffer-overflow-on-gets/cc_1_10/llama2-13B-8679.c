//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 20

// Function to encrypt a message
void encrypt_message(char *message, char *key) {
  int i, j, k;
  char temp;

  // Iterate through each character of the message
  for (i = 0; i < strlen(message); i++) {
    // Get the current character and its position in the message
    char current = message[i];
    int pos = i;

    // Shift the characters in the message to the right
    for (j = i + 1; j < strlen(message); j++) {
      message[j - 1] = message[j];
    }

    // Insert the key character at the position of the current character
    message[pos] = key[k];

    // Update the key character position
    k++;

    // If the key character is greater than 'z', increment the position
    // of the current character by 1 to avoid overwriting the next character
    if (key[k] > 'z') {
      pos++;
    }
  }
}

// Function to decrypt a message
void decrypt_message(char *message, char *key) {
  int i, j, k;
  char temp;

  // Iterate through each character of the message
  for (i = 0; i < strlen(message); i++) {
    // Get the current character and its position in the message
    char current = message[i];
    int pos = i;

    // Shift the characters in the message to the left
    for (j = i - 1; j >= 0; j--) {
      message[j + 1] = message[j];
    }

    // Insert the key character at the position of the current character
    message[pos] = key[k];

    // Update the key character position
    k++;

    // If the key character is less than 'a', decrement the position
    // of the current character by 1 to avoid overwriting the previous character
    if (key[k] < 'a') {
      pos--;
    }
  }
}

int main() {
  char message[MAX_MESSAGE_LENGTH];
  char key[MAX_KEY_LENGTH];
  int choice;

  // Print a romantic message
  printf("Welcome to my heart, my love.\n");
  printf("I have a message for you, my sweetheart.\n");
  printf("Please enter your key to decrypt it:\n");

  // Get the message and key from the user
  gets(message);
  gets(key);

  // Encrypt the message
  encrypt_message(message, key);

  // Print the encrypted message
  printf("Your encrypted message is: %s\n", message);

  // Ask the user to decrypt the message
  printf("Do you want to decrypt the message? (y/n)\n");
  scanf(" %c", &choice);

  if (choice == 'y') {
    // Decrypt the message
    decrypt_message(message, key);

    // Print the decrypted message
    printf("Your decrypted message is: %s\n", message);
  } else {
    printf("Okay, my love. I will keep the message safe for you.\n");
  }

  return 0;
}