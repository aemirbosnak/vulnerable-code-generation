#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <unistd.h>

int main() {
  int *arr = (int *)malloc(10 * sizeof(int));
  arr[10] = 10; // Out of bounds write

  free(arr);
  return 0;
}
