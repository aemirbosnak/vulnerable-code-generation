#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 10;
  int *arr = (int *)malloc(size * sizeof(int));

  arr[size - 1] = 10;

  free(arr);

  return 0;
}
