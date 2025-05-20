#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(void *key, void *data, int data_len) {
  *(int *)key = 12;
  *((int *)data) = 42;
}

int main() {
  void *key = NULL;
  void *data = NULL;

  encrypt(key, data, 0);

  return 0;
}
