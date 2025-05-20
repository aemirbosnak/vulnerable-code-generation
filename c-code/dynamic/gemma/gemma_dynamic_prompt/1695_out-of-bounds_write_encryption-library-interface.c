#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int encrypt_block(unsigned char *buf, int len, unsigned int key) {
  for (int i = 0; i < len; i++) {
    buf[i] ^= key;
  }
  return len;
}

int main() {
  unsigned char buf[] = "Hello, world!";
  int len = sizeof(buf) - 1;
  unsigned int key = 0x12345;

  encrypt_block(buf, len, key);

  printf("%s\n", buf);

  return 0;
}
