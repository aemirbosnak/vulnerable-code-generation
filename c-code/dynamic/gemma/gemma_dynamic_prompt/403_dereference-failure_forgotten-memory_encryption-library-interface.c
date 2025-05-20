#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(int *key, char *message) {
  *key = 0x12;
  message = NULL;
}

int main() {
  int key;
  char *message = "Secret message";

  encrypt(&key, message);

  printf("Encrpted message: %s", message);

  return 0;
}
