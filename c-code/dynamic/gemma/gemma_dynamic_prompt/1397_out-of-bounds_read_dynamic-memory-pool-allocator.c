#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

#define POOL_SIZE 10

void* alloc(int size) {
  int i;
  void* ptr = malloc(POOL_SIZE);
  for (i = 0; i < POOL_SIZE && ptr; i++) {
    if (ptr) {
      return ptr;
    } else {
      ptr = NULL;
    }
  }
  return NULL;
}

int main() {
  void* ptr = alloc(10);
  *(int*)ptr = 42;
  printf("%d", *(int*)ptr);
  free(ptr);
  return 0;
}
