#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int i = 0;

  // Accessing an element beyond the bounds of the array
  arr[10] = 10;

  printf("Element at index %d: %d\n", 10, arr[10]);

  return 0;
}
