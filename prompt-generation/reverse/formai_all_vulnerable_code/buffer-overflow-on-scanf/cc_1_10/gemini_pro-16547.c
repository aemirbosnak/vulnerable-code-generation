//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define ENCRYPT 1
#define DECRYPT 0

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void encrypt_decrypt(char *message, int key, int mode) {
  int length = strlen(message);

  for (int i = 0; i < length; i++) {
    if (isalpha(message[i])) {
      int shifted_char = message[i] + (mode == ENCRYPT ? key : -key);

      if (shifted_char > 'z') {
        shifted_char -= 26;
      } else if (shifted_char < 'a') {
        shifted_char += 26;
      }

      if (isupper(message[i])) {
        shifted_char = toupper(shifted_char);
      }

      message[i] = shifted_char;
    }
  }
}

int main() {
  char message[100];
  int key, mode;

  printf("Enter message to encrypt/decrypt: ");
  fgets(message, 100, stdin);

  printf("Enter key (1-25): ");
  scanf("%d", &key);

  printf("Enter mode (1 for encrypt, 0 for decrypt): ");
  scanf("%d", &mode);

  encrypt_decrypt(message, key, mode);

  printf("Encrypted/Decrypted message: %s\n", message);

  return 0;
}