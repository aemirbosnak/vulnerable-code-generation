#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *key, char *msg) {
  int i = 0;
  while (key[i] && msg[i]) {
    msg[i] ^= key[i];
    i++;
  }
}

int main() {
  char key[] = "secret";
  char msg[] = "Hello, world!";

  encrypt(key, msg);

  printf("%s", msg);

  return 0;
}
