#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = NULL;
  arr = (int *)malloc(10 * sizeof(int));

  // This line intentionally dereferences an array element beyond the bounds of the allocated memory
  arr[10] = 5;

  free(arr);
  return 0;
}
