#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int* arr = NULL;
  arr = (int*)malloc(10);
  arr[10] = 5; // Out of bounds write
  printf("%d", arr[10]);
  free(arr);
  return 0;
}
