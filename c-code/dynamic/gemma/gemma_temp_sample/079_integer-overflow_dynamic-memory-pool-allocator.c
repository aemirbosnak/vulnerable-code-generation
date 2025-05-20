#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  int *arr = NULL;
  int size = 0;

  for (int i = 0; i < 1000000; i++) {
    arr = realloc(arr, size * sizeof(int));
    size++;
  }

  free(arr);

  return 0;
}
