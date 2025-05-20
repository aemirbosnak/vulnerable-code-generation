//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1024

// Romeo's key
unsigned char romeo_key[MAX_KEY_SIZE];

// Juliet's message
unsigned char juliet_message[MAX_MESSAGE_SIZE];

// Encryption function
void encrypt(unsigned char *message, size_t message_size, unsigned char *key, size_t key_size) {
  for (size_t i = 0; i < message_size; i++) {
    message[i] ^= key[i % key_size];
  }
}

// Decryption function
void decrypt(unsigned char *message, size_t message_size, unsigned char *key, size_t key_size) {
  encrypt(message, message_size, key, key_size);
}

int main() {
  // Generate Romeo's key
  for (size_t i = 0; i < MAX_KEY_SIZE; i++) {
    romeo_key[i] = rand() % 256;
  }

  // Read Juliet's message from standard input
  size_t message_size;
  printf("Juliet, enter your message: ");
  scanf("%s", juliet_message);
  message_size = strlen(juliet_message);

  // Encrypt Juliet's message using Romeo's key
  encrypt(juliet_message, message_size, romeo_key, MAX_KEY_SIZE);

  // Send the encrypted message to Romeo
  printf("Romeo, here is Juliet's encrypted message: ");
  fwrite(juliet_message, sizeof(unsigned char), message_size, stdout);

  // Decrypt the encrypted message using Romeo's key
  decrypt(juliet_message, message_size, romeo_key, MAX_KEY_SIZE);

  // Print the decrypted message
  printf("\nRomeo's decrypted message: %s\n", juliet_message);

  return 0;
}