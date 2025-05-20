//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Algo {
  char* name;
  int (*encrypt)(char*,int,char*);
  int (*decrypt)(char*,int,char*);
};

int caesar_cipher_encrypt(char* plaintext, int key, char* ciphertext) {
  int i;
  int len = strlen(plaintext);
  for (i = 0; i < len; i++) {
    if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
      ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
    } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
      ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
    } else {
      ciphertext[i] = plaintext[i];
    }
  }
  ciphertext[len] = '\0';
  return len;
}

int caesar_cipher_decrypt(char* ciphertext, int key, char* plaintext) {
  int i;
  int len = strlen(ciphertext);
  for (i = 0; i < len; i++) {
    if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
      plaintext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
    } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
      plaintext[i] = (ciphertext[i] - 'A' - key + 26) % 26 + 'A';
    } else {
      plaintext[i] = ciphertext[i];
    }
  }
  plaintext[len] = '\0';
  return len;
}

int main() {
  char plaintext[1000];
  int key;
  char ciphertext[1000];
  char decrypted_plaintext[1000];
  struct Algo caesar = {"Caesar Cipher", caesar_cipher_encrypt, caesar_cipher_decrypt};
  int (*encrypt_func)(char*,int,char*) = caesar.encrypt;
  int (*decrypt_func)(char*,int,char*) = caesar.decrypt;
  printf("Enter the plaintext: ");
  scanf("%[^\n]s", plaintext);
  getchar();
  printf("Enter the key: ");
  scanf("%d", &key);
  int ciphertext_length = encrypt_func(plaintext, key, ciphertext);
  printf("Encrypted text: %s\n", ciphertext);
  int decrypted_plaintext_length = decrypt_func(ciphertext, key, decrypted_plaintext);
  printf("Decrypted text: %s\n", decrypted_plaintext);
  return 0;
}