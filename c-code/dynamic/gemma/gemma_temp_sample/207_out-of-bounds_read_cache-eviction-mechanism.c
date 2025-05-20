#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = (int *)malloc(10 * sizeof(int));
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  // Out of bounds read vulnerability
  int value = arr[10];

  printf("Value: %d", value);

  free(arr);
  return 0;
}
