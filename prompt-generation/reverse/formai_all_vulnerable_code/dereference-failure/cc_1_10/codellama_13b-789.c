//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
// ephemeral_encryptor.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define KEY_SIZE 10
#define KEY_START 32
#define KEY_END 126
#define ENCRYPTED_KEY_SIZE 256

// Function to generate a random key
char* generate_key(void) {
  char* key = malloc(KEY_SIZE + 1);
  int i;

  for (i = 0; i < KEY_SIZE; i++) {
    key[i] = rand() % (KEY_END - KEY_START + 1) + KEY_START;
  }

  key[KEY_SIZE] = '\0';

  return key;
}

// Function to encrypt a string
char* encrypt(char* plaintext, char* key) {
  char* ciphertext = malloc(strlen(plaintext) + 1);
  int i, j;

  for (i = 0; i < strlen(plaintext); i++) {
    j = i % strlen(key);
    ciphertext[i] = plaintext[i] ^ key[j];
  }

  ciphertext[strlen(plaintext)] = '\0';

  return ciphertext;
}

// Function to decrypt a string
char* decrypt(char* ciphertext, char* key) {
  char* plaintext = malloc(strlen(ciphertext) + 1);
  int i, j;

  for (i = 0; i < strlen(ciphertext); i++) {
    j = i % strlen(key);
    plaintext[i] = ciphertext[i] ^ key[j];
  }

  plaintext[strlen(ciphertext)] = '\0';

  return plaintext;
}

// Example program
int main(void) {
  char* plaintext = "This is a test string.";
  char* key = generate_key();
  char* ciphertext = encrypt(plaintext, key);
  char* decrypted = decrypt(ciphertext, key);

  printf("Plaintext: %s\n", plaintext);
  printf("Key: %s\n", key);
  printf("Ciphertext: %s\n", ciphertext);
  printf("Decrypted: %s\n", decrypted);

  free(key);
  free(ciphertext);
  free(decrypted);

  return 0;
}