//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 26
#define KEY_SIZE 16

void encrypt(char *message, char *key);
void decrypt(char *cipher, char *key);

int main() {
  char message[100], key[KEY_SIZE], cipher[100];

  printf("Enter message to encrypt: ");
  scanf("%s", message);

  printf("Enter encryption key: ");
  scanf("%s", key);

  encrypt(message, key);
  printf("Encrypted message: %s\n", message);

  decrypt(message, key);
  printf("Decrypted message: %s\n", message);

  return 0;
}

void encrypt(char *message, char *key) {
  int i, j, k;

  for (i = 0, j = 0; message[i]!= '\0'; i++) {
    if (isalpha(message[i])) {
      message[i] = toupper(message[i]);
      k = message[i] - 'A';
      k = (k + atoi(key)) % SIZE;
      message[i] = (k + 'A');
    }
  }
}

void decrypt(char *cipher, char *key) {
  int i, j, k;

  for (i = 0, j = 0; cipher[i]!= '\0'; i++) {
    if (isalpha(cipher[i])) {
      cipher[i] = toupper(cipher[i]);
      k = cipher[i] - 'A';
      k = (k - atoi(key)) % SIZE;
      if (k < 0) {
        k += SIZE;
      }
      cipher[i] = (k + 'A');
    }
  }
}