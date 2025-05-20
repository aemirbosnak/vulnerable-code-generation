#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int* arr = NULL;
  arr = (int*) malloc(10 * sizeof(int));
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  int invalid_ptr = 4;
  int value = arr[invalid_ptr];

  printf("Value at invalid pointer: %d\n", value);

  free(arr);
  return 0;
}
