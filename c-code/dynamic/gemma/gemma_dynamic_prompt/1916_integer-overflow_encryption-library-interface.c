#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int key = 12;
  int ciphertext = 1337;

  int result = encrypt(key, ciphertext);

  if (result == -1) {
    printf("Error encrypting data.\n");
  } else {
    printf("Encrypted data: %d\n", result);
  }

  return 0;
}

int encrypt(int key, int ciphertext) {
  int product = key * ciphertext;
  int encrypted_result = product % 2;

  if (encrypted_result == 0) {
    return encrypted_result;
  } else {
    return -1;
  }
}
