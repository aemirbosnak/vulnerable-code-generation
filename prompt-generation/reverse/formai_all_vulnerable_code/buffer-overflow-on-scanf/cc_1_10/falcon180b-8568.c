//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

typedef struct {
  char key[SIZE];
  int key_length;
  int current_key_index;
} CaesarCipher;

void caesar_encrypt(char* message, int message_length, CaesarCipher* cipher) {
  int i;
  for (i = 0; i < message_length; i++) {
    if (isalpha(message[i])) {
      message[i] = (message[i] - 'a' + cipher->current_key_index) % 26 + 'a';
    }
  }
}

void caesar_decrypt(char* message, int message_length, CaesarCipher* cipher) {
  int i;
  for (i = 0; i < message_length; i++) {
    if (isalpha(message[i])) {
      message[i] = (message[i] - 'a' - cipher->current_key_index + 26) % 26 + 'a';
    }
  }
}

int main() {
  CaesarCipher cipher;
  cipher.key_length = 0;
  cipher.current_key_index = 0;

  char key[SIZE];
  int key_length;

  printf("Enter key: ");
  scanf("%s", key);
  key_length = strlen(key);

  if (key_length > SIZE) {
    printf("Key too long. Maximum key length is %d.\n", SIZE);
    return 1;
  }

  strcpy(cipher.key, key);
  cipher.key_length = key_length;

  char message[SIZE];
  int message_length;
  printf("Enter message: ");
  scanf("%s", message);
  message_length = strlen(message);

  caesar_encrypt(message, message_length, &cipher);
  printf("Encrypted message: %s\n", message);

  caesar_decrypt(message, message_length, &cipher);
  printf("Decrypted message: %s\n", message);

  return 0;
}