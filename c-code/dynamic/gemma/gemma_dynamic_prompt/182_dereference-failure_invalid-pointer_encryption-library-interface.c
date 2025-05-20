#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *key, char *msg) {
  // Invalid pointer dereference
  *(key + 1) = msg;
  printf("Encryptered message: %s", key);
}

int main() {
  char *key = malloc(10);
  char *msg = "Secret message";

  encrypt(key, msg);

  return 0;
}
