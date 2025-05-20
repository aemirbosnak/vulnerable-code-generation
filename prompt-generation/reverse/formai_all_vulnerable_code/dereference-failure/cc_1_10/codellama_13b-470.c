//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 100

char* encrypt(char* message, char* key) {
  char* encrypted = (char*) malloc(strlen(message) * sizeof(char));
  int key_length = strlen(key);
  int i, j;
  for (i = 0, j = 0; i < strlen(message); i++, j++) {
    if (j == key_length) {
      j = 0;
    }
    encrypted[i] = message[i] + key[j];
  }
  return encrypted;
}

char* decrypt(char* message, char* key) {
  char* decrypted = (char*) malloc(strlen(message) * sizeof(char));
  int key_length = strlen(key);
  int i, j;
  for (i = 0, j = 0; i < strlen(message); i++, j++) {
    if (j == key_length) {
      j = 0;
    }
    decrypted[i] = message[i] - key[j];
  }
  return decrypted;
}

int main() {
  char message[MAX_LENGTH];
  char key[MAX_LENGTH];
  char encrypted[MAX_LENGTH];
  char decrypted[MAX_LENGTH];

  printf("Enter the message: ");
  fgets(message, MAX_LENGTH, stdin);
  printf("Enter the key: ");
  fgets(key, MAX_LENGTH, stdin);

  strcpy(encrypted, encrypt(message, key));
  printf("Encrypted message: %s\n", encrypted);

  strcpy(decrypted, decrypt(encrypted, key));
  printf("Decrypted message: %s\n", decrypted);

  return 0;
}