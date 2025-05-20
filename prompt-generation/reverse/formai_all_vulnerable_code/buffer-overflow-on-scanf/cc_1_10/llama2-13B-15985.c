//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 50
#define MAX_KEY_LENGTH 10

// Function to generate a random key
void generate_key(char *key) {
  int i;
  for (i = 0; i < MAX_KEY_LENGTH; i++) {
    key[i] = 'a' + (rand() % 26);
  }
}

// Function to encrypt the message using the Caesar Cipher
void encrypt(char *message, char *key) {
  int i;
  for (i = 0; i < strlen(message); i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      message[i] = (message[i] + key[i - 'a'] - 'a') % 'z' + 'a';
    } else if (message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = (message[i] + key[i - 'A'] - 'A') % 'Z' + 'A';
    }
  }
}

// Function to decrypt the message using the Caesar Cipher
void decrypt(char *message, char *key) {
  int i;
  for (i = 0; i < strlen(message); i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      message[i] = (message[i] - key[i - 'a'] + 'a') % 'z' + 'a';
    } else if (message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = (message[i] - key[i - 'A'] + 'A') % 'Z' + 'A';
    }
  }
}

int main() {
  char message[MAX_MESSAGE_LENGTH];
  char key[MAX_KEY_LENGTH];
  int choice;

  // Ask the user for the message
  printf("Enter a message (up to %d characters long): ", MAX_MESSAGE_LENGTH);
  fgets(message, MAX_MESSAGE_LENGTH, stdin);

  // Ask the user for the key
  printf("Enter a key (up to %d characters long): ", MAX_KEY_LENGTH);
  fgets(key, MAX_KEY_LENGTH, stdin);

  // Generate the random key if the user didn't enter one
  if (strlen(key) == 0) {
    generate_key(key);
  }

  // Encrypt the message
  encrypt(message, key);

  // Print the encrypted message
  printf("Encrypted message: %s\n", message);

  // Ask the user if they want to decrypt the message
  printf("Do you want to decrypt the message? (y/n): ");
  scanf("%d", &choice);

  // Decrypt the message if the user wants to
  if (choice == 1) {
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
  }

  return 0;
}