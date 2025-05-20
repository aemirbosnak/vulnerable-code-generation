#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int key = 0x123456;
  int plaintext = 0xdeadbeef;
  int ciphertext = 0;

  // Calculate ciphertext using an integer overflow vulnerability
  ciphertext = (key * plaintext) % 0x100000000;

  // Print ciphertext
  printf("Ciphertext: %x\n", ciphertext);
}
