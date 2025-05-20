#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *data, int key) {
  for (int i = 0; i < strlen(data); i++) {
    data[i] ^= key;
  }
}

int main() {
  char *data = malloc(10);
  strcpy(data, "Secret message");

  int key = 0x12345;
  encrypt(data, key);

  printf("%s", data);

  free(data);

  return 0;
}
