#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr = NULL;
  int data = 0xdeadbeef;
  *ptr = (int*)malloc(data);
  free(ptr);
  printf("Hello, world!");
  return 0;
}
