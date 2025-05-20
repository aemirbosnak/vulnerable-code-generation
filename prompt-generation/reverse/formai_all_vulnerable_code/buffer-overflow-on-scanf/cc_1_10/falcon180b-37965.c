//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 256

char encrypt(char plainText, int key) {
  char cipherText;
  if (plainText >= 'a' && plainText <= 'z') {
    cipherText = plainText + key;
    if (cipherText > 'z') {
      cipherText = cipherText - 26;
    }
  } else if (plainText >= 'A' && plainText <= 'Z') {
    cipherText = plainText + key;
    if (cipherText > 'Z') {
      cipherText = cipherText - 26;
    }
  } else {
    cipherText = plainText;
  }
  return cipherText;
}

char decrypt(char cipherText, int key) {
  char plainText;
  if (cipherText >= 'a' && cipherText <= 'z') {
    plainText = cipherText - key;
    if (plainText < 'a') {
      plainText = plainText + 26;
    }
  } else if (cipherText >= 'A' && cipherText <= 'Z') {
    plainText = cipherText - key;
    if (plainText < 'A') {
      plainText = plainText + 26;
    }
  } else {
    plainText = cipherText;
  }
  return plainText;
}

int main() {
  char plainText[100];
  char cipherText[100];
  char decryptedText[100];
  int key;
  printf("Enter the plain text: ");
  scanf("%s", plainText);
  printf("Enter the key: ");
  scanf("%d", &key);
  int i, j;
  for (i = 0; plainText[i]!= '\0'; i++) {
    cipherText[i] = encrypt(plainText[i], key);
  }
  cipherText[i] = '\0';
  printf("Cipher text: %s\n", cipherText);
  for (i = 0, j = strlen(cipherText) - 1; i < strlen(cipherText); i++, j--) {
    decryptedText[i] = decrypt(cipherText[j], key);
  }
  decryptedText[i] = '\0';
  printf("Decrypted text: %s\n", decryptedText);
  return 0;
}