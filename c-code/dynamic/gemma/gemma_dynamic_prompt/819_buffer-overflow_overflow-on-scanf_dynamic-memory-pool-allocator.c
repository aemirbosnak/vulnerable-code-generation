#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* allocate(int size) {
  void* ptr = malloc(size);
  return ptr;
}

int main() {
  char* buffer = allocate(1024);
  printf("Enter a string: ");
  scanf("%s", buffer);
  free(buffer);
  return 0;
}
