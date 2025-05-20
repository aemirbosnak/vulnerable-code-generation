#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>

int encrypt(int key, int plaintext) {
  int ciphertext = plaintext + key;
  return ciphertext;
}

int main() {
  int key = 12;
  int plaintext = 1000000000;

  int ciphertext = encrypt(key, plaintext);

  printf("Ciphertext: %d\n", ciphertext);

  return 0;
}
