#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  int *arr = NULL;
  int size = 0;

  // Allocate memory
  arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    return 1;
  }

  // Dynamically increase the size of the array
  size = 10;
  arr = (int *)realloc(arr, size * sizeof(int));
  if (arr == NULL) {
    return 1;
  }

  // Free a portion of the memory
  free(arr + 2);

  // Free the entire block of memory
  free(arr);

  return 0;
}
