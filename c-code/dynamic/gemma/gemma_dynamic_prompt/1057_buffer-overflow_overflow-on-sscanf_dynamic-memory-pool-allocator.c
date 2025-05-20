#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* alloc(int size) {
  return malloc(size);
}

int main() {
  char* buffer = alloc(10);
  char input[100];

  printf("Enter a string: ");
  scanf(buffer, "%s", input);

  free(buffer);
  return 0;
}
