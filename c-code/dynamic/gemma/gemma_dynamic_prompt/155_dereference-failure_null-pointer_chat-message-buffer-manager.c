#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = NULL;
  arr = (int *)malloc(10 * sizeof(int));
  *arr = 5;
  printf("%d", *arr);
  free(arr);
  return 0;
}
