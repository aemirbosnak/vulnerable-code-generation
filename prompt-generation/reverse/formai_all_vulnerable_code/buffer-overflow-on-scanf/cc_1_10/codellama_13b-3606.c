//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void generate_key(unsigned char* key) {
  for (int i = 0; i < KEY_SIZE; i++) {
    key[i] = (unsigned char)rand();
  }
}

void encrypt_block(unsigned char* block, unsigned char* key) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    block[i] = block[i] ^ key[i % KEY_SIZE];
  }
}

void decrypt_block(unsigned char* block, unsigned char* key) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    block[i] = block[i] ^ key[i % KEY_SIZE];
  }
}

int main() {
  unsigned char key[KEY_SIZE];
  generate_key(key);

  unsigned char plaintext[BLOCK_SIZE];
  unsigned char ciphertext[BLOCK_SIZE];
  unsigned char decrypted[BLOCK_SIZE];

  printf("Enter plaintext: ");
  scanf("%s", plaintext);

  encrypt_block(plaintext, key);
  memcpy(ciphertext, plaintext, BLOCK_SIZE);

  printf("Ciphertext: ");
  for (int i = 0; i < BLOCK_SIZE; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  decrypt_block(ciphertext, key);
  memcpy(decrypted, ciphertext, BLOCK_SIZE);

  printf("Decrypted: ");
  for (int i = 0; i < BLOCK_SIZE; i++) {
    printf("%c", decrypted[i]);
  }
  printf("\n");

  return 0;
}