//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the encryption key
#define KEY_SIZE 256

// Declare the encryption and decryption functions
int encrypt(char* plaintext, char* key, char* ciphertext);
int decrypt(char* ciphertext, char* key, char* plaintext);

// Main function
int main() {
  // Declare the variables
  char plaintext[1024];
  char key[KEY_SIZE];
  char ciphertext[1024];
  int choice;

  // Get the user's choice
  printf("1. Encrypt a message\n");
  printf("2. Decrypt a message\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Get the plaintext or ciphertext
  if (choice == 1) {
    printf("Enter the plaintext: ");
    scanf(" %[^\n]%*c", plaintext);
  } else if (choice == 2) {
    printf("Enter the ciphertext: ");
    scanf(" %[^\n]%*c", ciphertext);
  } else {
    printf("Invalid choice");
    return 1;
  }

  // Get the key
  printf("Enter the key: ");
  scanf(" %[^\n]%*c", key);

  // Encrypt or decrypt the message
  if (choice == 1) {
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
  } else if (choice == 2) {
    decrypt(ciphertext, key, plaintext);
    printf("Plaintext: %s\n", plaintext);
  }

  return 0;
}

// Encryption function
int encrypt(char* plaintext, char* key, char* ciphertext) {
  int plaintext_length = strlen(plaintext);
  int key_length = strlen(key);

  // Check if the key is long enough
  if (key_length < plaintext_length) {
    printf("Error: The key is too short\n");
    return 1;
  }

  // Encrypt the message
  for (int i = 0; i < plaintext_length; i++) {
    ciphertext[i] = plaintext[i] ^ key[i];
  }

  // Return 0 if successful
  return 0;
}

// Decryption function
int decrypt(char* ciphertext, char* key, char* plaintext) {
  int ciphertext_length = strlen(ciphertext);
  int key_length = strlen(key);

  // Check if the key is long enough
  if (key_length < ciphertext_length) {
    printf("Error: The key is too short\n");
    return 1;
  }

  // Decrypt the message
  for (int i = 0; i < ciphertext_length; i++) {
    plaintext[i] = ciphertext[i] ^ key[i];
  }

  // Return 0 if successful
  return 0;
}