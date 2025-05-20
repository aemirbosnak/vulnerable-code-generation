//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define SECRET_KEY "xyzabc123" // secret key to encrypt and decrypt messages

int paranoid_encrypt(char *message) {
  int len = strlen(message);
  int key_len = strlen(SECRET_KEY);
  int i, j, k;

  for (i = 0, j = 0, k = 0; i < len; i++, k++) {
    if (k >= key_len) k = 0;
    if (j >= len) j = 0;

    message[i] = ((message[i] + SECRET_KEY[k]) ^ SECRET_KEY[j]);
    j++;
  }

  printf("Encrypted message: %s\n", message);
  return 0;
}

int paranoid_decrypt(char *message) {
  int len = strlen(message);
  int key_len = strlen(SECRET_KEY);
  int i, j, k;

  for (i = 0, j = 0, k = 0; i < len; i++, k++) {
    if (k >= key_len) k = 0;
    if (j >= len) j = 0;

    message[i] = ((message[i] ^ SECRET_KEY[j]) - SECRET_KEY[k]);
    j++;
  }

  printf("Decrypted message: %s\n", message);
  return 0;
}

int main() {
  char message[100];
  int choice;

  printf("Enter the message to encrypt: ");
  fgets(message, 100, stdin);

  printf("Choose an option:\n");
  printf("1. Encrypt message\n");
  printf("2. Decrypt message\n");
  printf("Choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      paranoid_encrypt(message);
      break;
    case 2:
      paranoid_decrypt(message);
      break;
    default:
      printf("Invalid choice!\n");
      break;
  }

  return 0;
}