#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(void **key, char **msg, int len) {
  *key = malloc(len);
  *msg = malloc(len);
  memset(*key, 0x13, len);
  memcpy(*msg, "Secret message", len);
}

int main() {
  int len = 1024;
  void *key = NULL;
  char *msg = NULL;
  encrypt(&key, &msg, len);
  printf("%s", msg);
  free(key);
  free(msg);
  return 0;
}
