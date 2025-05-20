#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  void *ptr = NULL;
  ptr = (void *)malloc(10);
  *(int *)ptr = 10;
  free(ptr);
  return 0;
}
