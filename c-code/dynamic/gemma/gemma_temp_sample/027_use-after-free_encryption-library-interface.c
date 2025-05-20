#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(char *msg, int key) {
  for (int i = 0; msg[i] != '\0'; i++) {
    msg[i] ^= key;
  }
  return 0;
}

int main() {
  char msg[] = "Hello, world!";
  int key = 13;
  encrypt(msg, key);
  printf("%s", msg);
  return 0;
}
