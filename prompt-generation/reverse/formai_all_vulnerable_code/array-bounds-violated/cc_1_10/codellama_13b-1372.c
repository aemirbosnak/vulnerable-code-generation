//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: surrealist
/*
 * File Encryptor
 *
 * This program encrypts a file using a surrealist encryption method.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000000

void encrypt(char* plaintext, char* key) {
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < strlen(plaintext); i++, j++, k++) {
    if (j == strlen(key)) {
      j = 0;
    }
    plaintext[i] = plaintext[i] ^ key[j];
  }
}

void decrypt(char* ciphertext, char* key) {
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < strlen(ciphertext); i++, j++, k++) {
    if (j == strlen(key)) {
      j = 0;
    }
    ciphertext[i] = ciphertext[i] ^ key[j];
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <file to encrypt/decrypt> <key>\n", argv[0]);
    return 1;
  }

  FILE* file = fopen(argv[1], "r+");
  if (file == NULL) {
    printf("Error: unable to open file %s\n", argv[1]);
    return 1;
  }

  char key[MAX_FILE_SIZE];
  fgets(key, MAX_FILE_SIZE, stdin);
  if (key[strlen(key) - 1] == '\n') {
    key[strlen(key) - 1] = '\0';
  }

  char plaintext[MAX_FILE_SIZE];
  fgets(plaintext, MAX_FILE_SIZE, file);
  if (plaintext[strlen(plaintext) - 1] == '\n') {
    plaintext[strlen(plaintext) - 1] = '\0';
  }

  encrypt(plaintext, key);
  fprintf(file, "%s", plaintext);
  fclose(file);

  return 0;
}