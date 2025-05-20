#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = NULL;
  ptr = (int *)malloc(10);
  if (ptr == NULL) {
    return 1;
  }
  *ptr = 5;
  printf("%d", *ptr);
  free(ptr);
  return 0;
}
