#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char** buffer_manager(int size) {
  char** messages = malloc(size * sizeof(char*));
  for (int i = 0; i < size; i++) {
    messages[i] = NULL;
  }
  return messages;
}

int main() {
  int size = 10;
  char** messages = buffer_manager(size);
  messages[0] = "Hello, world!";
  printf("%s", messages[0]);
  free(messages);
  return 0;
}
