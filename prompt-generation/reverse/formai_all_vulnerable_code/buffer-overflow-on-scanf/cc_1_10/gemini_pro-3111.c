//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for encryption and decryption
#define KEY "abcdefghijklmnopqrstuvwxyz"
#define KEY_SIZE 26

// Encryption function
char encrypt(char c) {
  int index = c - 'a';
  if (index < 0 || index >= KEY_SIZE) {
    return c;
  }
  return KEY[(index + 13) % KEY_SIZE];
}

// Decryption function
char decrypt(char c) {
  int index = c - 'a';
  if (index < 0 || index >= KEY_SIZE) {
    return c;
  }
  return KEY[(index - 13 + KEY_SIZE) % KEY_SIZE];
}

// Get user input for the message to encrypt/decrypt
char* get_input() {
  char* message = malloc(100);
  printf("Enter a message to encrypt/decrypt: ");
  scanf("%s", message);
  return message;
}

// Print the encrypted/decrypted message
void print_message(char* message, int encrypted) {
  printf("\n%s", encrypted ? "Encrypted Message:" : "Decrypted Message:");
  for (int i = 0; message[i] != '\0'; i++) {
    printf("%c", message[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Get user input for the message
  char* message = get_input();

  // Encrypt the message
  printf("\nEncrypting the message...\n");
  for (int i = 0; message[i] != '\0'; i++) {
    message[i] = encrypt(message[i]);
  }

  // Print the encrypted message
  print_message(message, 1);

  // Decrypt the message
  printf("\nDecrypting the encrypted message...\n");
  for (int i = 0; message[i] != '\0'; i++) {
    message[i] = decrypt(message[i]);
  }

  // Print the decrypted message
  print_message(message, 0);

  // Free the allocated memory for the message
  free(message);

  return 0;
}