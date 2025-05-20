//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
/*
 * Cryptography Implementation in C
 *
 * This program implements a simple cryptography algorithm in C.
 * It uses the Caesar Cipher to encrypt and decrypt a message.
 *
 * Compile and run with:
 *
 *   gcc -o crypt crypt.c
 *   ./crypt
 *
 * Usage:
 *
 *   ./crypt -e [message]
 *   ./crypt -d [encrypted message]
 *
 * Examples:
 *
 *   ./crypt -e "hello world"
 *   ./crypt -d "khoor zruog"
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY 3

char* encrypt(char* message) {
  int length = strlen(message);
  char* encrypted = malloc(length * sizeof(char));

  for (int i = 0; i < length; i++) {
    encrypted[i] = message[i] + KEY;
  }

  return encrypted;
}

char* decrypt(char* encrypted) {
  int length = strlen(encrypted);
  char* message = malloc(length * sizeof(char));

  for (int i = 0; i < length; i++) {
    message[i] = encrypted[i] - KEY;
  }

  return message;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: ./crypt -e [message] or ./crypt -d [encrypted message]\n");
    return 1;
  }

  char* message = argv[2];
  char* encrypted = encrypt(message);
  char* decrypted = decrypt(encrypted);

  printf("Message: %s\n", message);
  printf("Encrypted: %s\n", encrypted);
  printf("Decrypted: %s\n", decrypted);

  return 0;
}