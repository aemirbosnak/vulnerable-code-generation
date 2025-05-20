#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(char *msg, int len, char key) {
  for (int i = 0; i < len; i++) {
    msg[i] ^= key;
  }
  return 0;
}

int main() {
  char msg[] = "Hello, world!";
  int len = strlen(msg);
  char key = 'A';

  encrypt(msg, len, key);

  printf("%s\n", msg);

  return 0;
}
