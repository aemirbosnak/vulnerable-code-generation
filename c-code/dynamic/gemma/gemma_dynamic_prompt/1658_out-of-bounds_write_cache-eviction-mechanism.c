#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = (int *)malloc(10 * sizeof(int));
  arr[10] = 10;
  arr[-1] = 20;

  printf("%d", arr[0]);
  free(arr);

  return 0;
}
